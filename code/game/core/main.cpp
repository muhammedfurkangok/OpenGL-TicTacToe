#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <assimp/scene.h>
#include <assimp/postprocess.h>


#include <vector>
#include <iostream>

// Shader source code
constexpr auto vertex_stage_text = R"(
#version 450
layout(location = 0) in vec3 position;
layout(location = 0) uniform mat4 proj;
layout(location = 1) uniform mat4 view;
layout(location = 2) uniform mat4 model;
void main()
{
    gl_Position = proj * view * model * vec4(position, 1.0);
}
)";

constexpr auto fragment_stage_text = R"(
#version 450
out vec4 color;
void main()
{
    color = vec4(1.0, 0.0, 0.0, 1.0);
}
)";

// Function to compile a shader
GLuint compileShader(GLenum type, const char* source) {
    GLuint shader = glCreateShader(type);
    glShaderSource(shader, 1, &source, nullptr);
    glCompileShader(shader);

    GLint success;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    if (!success) {
        char infoLog[512];
        glGetShaderInfoLog(shader, 512, nullptr, infoLog);
        std::cerr << "Shader Compilation Error: " << infoLog << std::endl;
    }
    return shader;
}

// Function to initialize buffers
void initializeBuffers(GLuint& vao, GLuint& vbo, GLuint& ebo, const std::vector<float>& vertices, const std::vector<uint32_t>& elements) {
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(float) * vertices.size(), vertices.data(), GL_STATIC_DRAW);

    glGenBuffers(1, &ebo);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(uint32_t) * elements.size(), elements.data(), GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
}

// Function to update uniform matrices
void updateUniformMatrix(GLuint location, const glm::mat4& matrix) {
    glUniformMatrix4fv(location, 1, GL_FALSE, glm::value_ptr(matrix));
}

int main() {
    glfwInit();

    constexpr auto window_width = 1000;
    constexpr auto window_height = 1000;

    const auto window = glfwCreateWindow(window_width, window_height, "Tic-Tac-Toe", nullptr, nullptr);
    glfwMakeContextCurrent(window);
    gladLoadGL();

    // Compile shaders and link program
    GLuint vertex_stage = compileShader(GL_VERTEX_SHADER, vertex_stage_text);
    GLuint fragment_stage = compileShader(GL_FRAGMENT_SHADER, fragment_stage_text);

    GLuint shader = glCreateProgram();
    glAttachShader(shader, vertex_stage);
    glAttachShader(shader, fragment_stage);
    glLinkProgram(shader);

    // Vertex and element data
    const std::vector<float> vertices = {
        -0.5f,  0.5f, 0.0f,
         0.5f,  0.5f, 0.0f,
         0.5f, -0.5f, 0.0f,
        -0.5f, -0.5f, 0.0f
    };

    const std::vector<uint32_t> elements = {
        0, 1, 2,
        2, 3, 0
    };

    GLuint vao, vbo, ebo;
    initializeBuffers(vao, vbo, ebo, vertices, elements);

    glClearColor(0.5f, 0.5f, 0.5f, 1.0f);

    auto proj = glm::perspective(glm::radians(60.0f), static_cast<float>(window_width) / static_cast<float>(window_height), 0.1f, 100.0f);
    auto view = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, -3.0f));

    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();

        if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
            glfwSetWindowShouldClose(window, true);
        }

        glClear(GL_COLOR_BUFFER_BIT);

        glUseProgram(shader);

        updateUniformMatrix(0, proj);
        updateUniformMatrix(1, view);

        constexpr auto tile_space = 1.1f;

        for (auto row = 0; row < 3; row++) {
            for (auto col = 0; col < 3; col++) {
                const auto x = -tile_space + col * tile_space;
                const auto y = tile_space - row * tile_space;

                auto model = glm::translate(glm::mat4(1.0f), glm::vec3(x, y, 0.0f));
                updateUniformMatrix(2, model);

                glDrawElements(GL_TRIANGLES, elements.size(), GL_UNSIGNED_INT, nullptr);
            }
        }

        glfwSwapBuffers(window);
    }

    glDeleteVertexArrays(1, &vao);
    glDeleteBuffers(1, &vbo);
    glDeleteBuffers(1, &ebo);

    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}