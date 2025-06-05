    #include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <assimp/Importer.hpp>
#include <assimp/postprocess.h>
#include <assimp/scene.h>

#include <vector>

// Vertex Shader - pozisyonu model * view * projection matrisleriyle çarpar
auto vertex_stage_text =
        "#version 450\n"
        "layout(location = 0) in vec3 position;\n"
        "layout(location = 0) uniform mat4 proj;\n"
        "layout(location = 1) uniform mat4 view;\n"
        "layout(location = 2) uniform mat4 model;\n"
        "void main()\n"
        "{\n"
        "    gl_Position = proj * view * model * vec4(position, 1.0);\n"
        "}\n";

// Fragment Shader - her pikseli kırmızı yapar
auto fragment_stage_text =
        "#version 450\n"
        "out vec4 color;\n"
        "void main()\n"
        "{\n"
        "    color = vec4(1.0, 0.0, 0.0, 1.0);\n"
        "}\n";

auto main() -> int
{
    glfwInit(); // GLFW başlatılır

    constexpr auto window_width  = 1000;
    constexpr auto window_height = 1000;

    // OpenGL penceresi oluşturuluyor
    const auto window = glfwCreateWindow(window_width, window_height, "Tic-Tac-Toe", nullptr, nullptr);
    glfwMakeContextCurrent(window); // pencereyi aktif yap
    gladLoadGL(); // GL fonksiyonları yüklenir

    // Shader’lar oluşturuluyor
    const auto vertex_stage = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertex_stage, 1, &vertex_stage_text, nullptr);
    glCompileShader(vertex_stage);

    const auto fragment_stage = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragment_stage, 1, &fragment_stage_text, nullptr);
    glCompileShader(fragment_stage);

    // Shader programı bağlanıyor
    const auto shader = glCreateProgram();
    glAttachShader(shader, vertex_stage);
    glAttachShader(shader, fragment_stage);
    glLinkProgram(shader);

    // Kare (tile) vertex ve index verileri
    const std::vector tile_vertices
            {
                    -0.5f,  0.5f, 0.0f,
                    0.5f,  0.5f, 0.0f,
                    0.5f, -0.5f, 0.0f,
                    -0.5f, -0.5f, 0.0f
            };

    const std::vector<uint32_t> tile_elements
            {
                    0, 1, 2, // birinci üçgen
                    2, 3, 0  // ikinci üçgen
            };

    uint32_t tile_vao, tile_vbo, tile_ebo;

    // Tile için VAO, VBO ve EBO oluşturuluyor
    glGenVertexArrays(1, &tile_vao);
    glBindVertexArray(tile_vao);

    glGenBuffers(1, &tile_vbo);
    glBindBuffer(GL_ARRAY_BUFFER, tile_vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(float) * tile_vertices.size(), tile_vertices.data(), GL_STATIC_DRAW);

    glGenBuffers(1, &tile_ebo);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, tile_ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(uint32_t) * tile_elements.size(), tile_elements.data(), GL_STATIC_DRAW);

    // Vertex attribute ayarlanıyor (pozisyon)
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    std::vector<float> x_vertices;
    std::vector<uint32_t> x_elements;

    Assimp::Importer x_importer;

    const auto x_scene = x_importer.ReadFile("x.obj", 0);
    const auto x_mesh = x_scene->mMeshes[0];

    for (auto i = 0; i < x_mesh->mNumVertices; i++)
    {
        auto vertex = x_mesh->mVertices[i];
        x_vertices.push_back(vertex.x);
        x_vertices.push_back(vertex.y);
        x_vertices.push_back(vertex.z);
    }

    for (auto i = 0; i < x_mesh->mNumFaces; i++)
    {
        auto face = x_mesh->mFaces[i];
        x_elements.push_back(face.mIndices[0]);
        x_elements.push_back(face.mIndices[1]);
        x_elements.push_back(face.mIndices[2]);
    }

    uint32_t x_vao, x_vbo, x_ebo;

    // 'X' mesh'i için VAO, VBO, EBO oluşturuluyor
    glGenVertexArrays(1, &x_vao);
    glBindVertexArray(x_vao);

    glGenBuffers(1, &x_vbo);
    glBindBuffer(GL_ARRAY_BUFFER, x_vbo);

    glBufferData(GL_ARRAY_BUFFER, sizeof(float) * x_vertices.size(), x_vertices.data(), GL_STATIC_DRAW);

    glGenBuffers(1, &x_ebo);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, x_ebo);

    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(uint32_t) * x_elements.size(), x_elements.data(), GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);

    glEnableVertexAttribArray(0);



    // 'O' harfi için vertex ve index dizileri
    std::vector<float>    o_vertices;
    std::vector<uint32_t> o_elements;

    Assimp::Importer o_importer;

    // Assimp ile model dosyası okunuyor
    auto o_scene = o_importer.ReadFile("o.obj", 0);
    auto o_mesh  = o_scene->mMeshes[0];

    // Tüm vertexler alınır (x, y, z)
    for (auto i = 0; i < o_mesh->mNumVertices; i++)
    {
        auto vertex = o_mesh->mVertices[i];
        o_vertices.push_back(vertex.x);
        o_vertices.push_back(vertex.y);
        o_vertices.push_back(vertex.z);
    }

    // Her yüzey üç köşe içerir. Bu köşe indexleri alınır
    for (auto i = 0; i < o_mesh->mNumFaces; i++)
    {
        auto face = o_mesh->mFaces[i];
        o_elements.push_back(face.mIndices[0]);
        o_elements.push_back(face.mIndices[1]);
        o_elements.push_back(face.mIndices[2]);
    }

    uint32_t o_vao, o_vbo, o_ebo;

    // 'O' mesh'i için VAO, VBO, EBO oluşturuluyor
    glGenVertexArrays(1, &o_vao);
    glBindVertexArray(o_vao);

    glGenBuffers(1, &o_vbo);
    glBindBuffer(GL_ARRAY_BUFFER, o_vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(float) * o_vertices.size(), o_vertices.data(), GL_STATIC_DRAW);

    glGenBuffers(1, &o_ebo);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, o_ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(uint32_t) * o_elements.size(), o_elements.data(), GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    // Arka plan rengi gri olarak ayarlanır
    glClearColor(0.5f, 0.5f, 0.5f, 1.0f);

    // Kamera ve projeksiyon ayarlanır
    auto proj = glm::perspective(glm::radians(60.0f), static_cast<float>(window_width) / static_cast<float>(window_height), 0.1f, 100.0f);
    auto view = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, -3.0f));

    // Ana oyun döngüsü
    while (!glfwWindowShouldClose(window))
    {
        glfwPollEvents();

        // ESC tuşuna basılırsa pencere kapanır
        if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        {
            glfwSetWindowShouldClose(window, true);
        }

        glClear(GL_COLOR_BUFFER_BIT); // Ekranı temizle

        glUseProgram(shader); // Shader programını kullan

        // Uniform matrisleri GPU'ya gönder
        glUniformMatrix4fv(0, 1, GL_FALSE, glm::value_ptr(proj));
        glUniformMatrix4fv(1, 1, GL_FALSE, glm::value_ptr(view));

        // 3x3 tahta çizimi için döngüler
        for (auto row = 0; row < 3; row++) // satırlar
        {
            for (auto col = 0; col < 3; col++) // sütunlar
            {
                constexpr auto  tile_space = 1.1f;

                const auto x = -tile_space + col * tile_space;
                const auto y =  tile_space - row * tile_space;

                auto model = glm::translate(glm::mat4(1.0f), glm::vec3(x, y, 0.0f)); // her karenin konumu

                glUniformMatrix4fv(2, 1, GL_FALSE, glm::value_ptr(model));

                //glBindVertexArray(tile_vao); // kare VAO'su bağlanır
                //glDrawElements(GL_TRIANGLES, tile_elements.size(), GL_UNSIGNED_INT, nullptr); // kareyi çizmek için

                if(row == col)
                {
                    glBindVertexArray(x_vao);
                    glDrawElements(GL_TRIANGLES, o_elements.size(), GL_UNSIGNED_INT, nullptr); // O modeli çizilir
                }
                else
                {
                    glBindVertexArray(o_vao);
                    glDrawElements(GL_TRIANGLES, x_elements.size(), GL_UNSIGNED_INT, nullptr); // X modeli çizilir
                }

            }
        }

        glfwSwapBuffers(window); // Ekranı güncelle
    }

    // Kaynaklar serbest bırakılır
    glDeleteVertexArrays(1, &tile_vao);
    glDeleteVertexArrays(1, &o_vao);
    glDeleteVertexArrays(1, &x_vao);

    glDeleteBuffers(1, &tile_vbo);
    glDeleteBuffers(1, &tile_ebo);

    glDeleteBuffers(1, &o_vbo);
    glDeleteBuffers(1, &o_ebo);
    glDeleteBuffers(1, &x_vbo);
    glDeleteBuffers(1, &x_ebo);

    glDeleteShader(vertex_stage);
    glDeleteShader(fragment_stage);

    glDeleteProgram(shader);

    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}
