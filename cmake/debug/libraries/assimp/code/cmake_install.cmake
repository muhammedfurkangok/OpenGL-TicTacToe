# Install script for directory: C:/Gamedev/OpenGL-TicTacToe/libraries/assimp/code

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "C:/Program Files (x86)/tic-tac-toe")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Debug")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set path to fallback-tool for dependency-resolution.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "C:/Users/gkkan/AppData/Local/Programs/CLion/bin/mingw/bin/objdump.exe")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "libassimp5.4.3-dev" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "C:/Gamedev/OpenGL-TicTacToe/cmake/debug/libraries/assimp/lib/libassimpd.a")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "assimp-dev" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/assimp" TYPE FILE FILES
    "C:/Gamedev/OpenGL-TicTacToe/libraries/assimp/code/../include/assimp/anim.h"
    "C:/Gamedev/OpenGL-TicTacToe/libraries/assimp/code/../include/assimp/aabb.h"
    "C:/Gamedev/OpenGL-TicTacToe/libraries/assimp/code/../include/assimp/ai_assert.h"
    "C:/Gamedev/OpenGL-TicTacToe/libraries/assimp/code/../include/assimp/camera.h"
    "C:/Gamedev/OpenGL-TicTacToe/libraries/assimp/code/../include/assimp/color4.h"
    "C:/Gamedev/OpenGL-TicTacToe/libraries/assimp/code/../include/assimp/color4.inl"
    "C:/Gamedev/OpenGL-TicTacToe/cmake/debug/libraries/assimp/code/../include/assimp/config.h"
    "C:/Gamedev/OpenGL-TicTacToe/libraries/assimp/code/../include/assimp/ColladaMetaData.h"
    "C:/Gamedev/OpenGL-TicTacToe/libraries/assimp/code/../include/assimp/commonMetaData.h"
    "C:/Gamedev/OpenGL-TicTacToe/libraries/assimp/code/../include/assimp/defs.h"
    "C:/Gamedev/OpenGL-TicTacToe/libraries/assimp/code/../include/assimp/cfileio.h"
    "C:/Gamedev/OpenGL-TicTacToe/libraries/assimp/code/../include/assimp/light.h"
    "C:/Gamedev/OpenGL-TicTacToe/libraries/assimp/code/../include/assimp/material.h"
    "C:/Gamedev/OpenGL-TicTacToe/libraries/assimp/code/../include/assimp/material.inl"
    "C:/Gamedev/OpenGL-TicTacToe/libraries/assimp/code/../include/assimp/matrix3x3.h"
    "C:/Gamedev/OpenGL-TicTacToe/libraries/assimp/code/../include/assimp/matrix3x3.inl"
    "C:/Gamedev/OpenGL-TicTacToe/libraries/assimp/code/../include/assimp/matrix4x4.h"
    "C:/Gamedev/OpenGL-TicTacToe/libraries/assimp/code/../include/assimp/matrix4x4.inl"
    "C:/Gamedev/OpenGL-TicTacToe/libraries/assimp/code/../include/assimp/mesh.h"
    "C:/Gamedev/OpenGL-TicTacToe/libraries/assimp/code/../include/assimp/ObjMaterial.h"
    "C:/Gamedev/OpenGL-TicTacToe/libraries/assimp/code/../include/assimp/pbrmaterial.h"
    "C:/Gamedev/OpenGL-TicTacToe/libraries/assimp/code/../include/assimp/GltfMaterial.h"
    "C:/Gamedev/OpenGL-TicTacToe/libraries/assimp/code/../include/assimp/postprocess.h"
    "C:/Gamedev/OpenGL-TicTacToe/libraries/assimp/code/../include/assimp/quaternion.h"
    "C:/Gamedev/OpenGL-TicTacToe/libraries/assimp/code/../include/assimp/quaternion.inl"
    "C:/Gamedev/OpenGL-TicTacToe/libraries/assimp/code/../include/assimp/scene.h"
    "C:/Gamedev/OpenGL-TicTacToe/libraries/assimp/code/../include/assimp/metadata.h"
    "C:/Gamedev/OpenGL-TicTacToe/libraries/assimp/code/../include/assimp/texture.h"
    "C:/Gamedev/OpenGL-TicTacToe/libraries/assimp/code/../include/assimp/types.h"
    "C:/Gamedev/OpenGL-TicTacToe/libraries/assimp/code/../include/assimp/vector2.h"
    "C:/Gamedev/OpenGL-TicTacToe/libraries/assimp/code/../include/assimp/vector2.inl"
    "C:/Gamedev/OpenGL-TicTacToe/libraries/assimp/code/../include/assimp/vector3.h"
    "C:/Gamedev/OpenGL-TicTacToe/libraries/assimp/code/../include/assimp/vector3.inl"
    "C:/Gamedev/OpenGL-TicTacToe/libraries/assimp/code/../include/assimp/version.h"
    "C:/Gamedev/OpenGL-TicTacToe/libraries/assimp/code/../include/assimp/cimport.h"
    "C:/Gamedev/OpenGL-TicTacToe/libraries/assimp/code/../include/assimp/AssertHandler.h"
    "C:/Gamedev/OpenGL-TicTacToe/libraries/assimp/code/../include/assimp/importerdesc.h"
    "C:/Gamedev/OpenGL-TicTacToe/libraries/assimp/code/../include/assimp/Importer.hpp"
    "C:/Gamedev/OpenGL-TicTacToe/libraries/assimp/code/../include/assimp/DefaultLogger.hpp"
    "C:/Gamedev/OpenGL-TicTacToe/libraries/assimp/code/../include/assimp/ProgressHandler.hpp"
    "C:/Gamedev/OpenGL-TicTacToe/libraries/assimp/code/../include/assimp/IOStream.hpp"
    "C:/Gamedev/OpenGL-TicTacToe/libraries/assimp/code/../include/assimp/IOSystem.hpp"
    "C:/Gamedev/OpenGL-TicTacToe/libraries/assimp/code/../include/assimp/Logger.hpp"
    "C:/Gamedev/OpenGL-TicTacToe/libraries/assimp/code/../include/assimp/LogStream.hpp"
    "C:/Gamedev/OpenGL-TicTacToe/libraries/assimp/code/../include/assimp/NullLogger.hpp"
    "C:/Gamedev/OpenGL-TicTacToe/libraries/assimp/code/../include/assimp/cexport.h"
    "C:/Gamedev/OpenGL-TicTacToe/libraries/assimp/code/../include/assimp/Exporter.hpp"
    "C:/Gamedev/OpenGL-TicTacToe/libraries/assimp/code/../include/assimp/DefaultIOStream.h"
    "C:/Gamedev/OpenGL-TicTacToe/libraries/assimp/code/../include/assimp/DefaultIOSystem.h"
    "C:/Gamedev/OpenGL-TicTacToe/libraries/assimp/code/../include/assimp/ZipArchiveIOSystem.h"
    "C:/Gamedev/OpenGL-TicTacToe/libraries/assimp/code/../include/assimp/SceneCombiner.h"
    "C:/Gamedev/OpenGL-TicTacToe/libraries/assimp/code/../include/assimp/fast_atof.h"
    "C:/Gamedev/OpenGL-TicTacToe/libraries/assimp/code/../include/assimp/qnan.h"
    "C:/Gamedev/OpenGL-TicTacToe/libraries/assimp/code/../include/assimp/BaseImporter.h"
    "C:/Gamedev/OpenGL-TicTacToe/libraries/assimp/code/../include/assimp/Hash.h"
    "C:/Gamedev/OpenGL-TicTacToe/libraries/assimp/code/../include/assimp/MemoryIOWrapper.h"
    "C:/Gamedev/OpenGL-TicTacToe/libraries/assimp/code/../include/assimp/ParsingUtils.h"
    "C:/Gamedev/OpenGL-TicTacToe/libraries/assimp/code/../include/assimp/StreamReader.h"
    "C:/Gamedev/OpenGL-TicTacToe/libraries/assimp/code/../include/assimp/StreamWriter.h"
    "C:/Gamedev/OpenGL-TicTacToe/libraries/assimp/code/../include/assimp/StringComparison.h"
    "C:/Gamedev/OpenGL-TicTacToe/libraries/assimp/code/../include/assimp/StringUtils.h"
    "C:/Gamedev/OpenGL-TicTacToe/libraries/assimp/code/../include/assimp/SGSpatialSort.h"
    "C:/Gamedev/OpenGL-TicTacToe/libraries/assimp/code/../include/assimp/GenericProperty.h"
    "C:/Gamedev/OpenGL-TicTacToe/libraries/assimp/code/../include/assimp/SpatialSort.h"
    "C:/Gamedev/OpenGL-TicTacToe/libraries/assimp/code/../include/assimp/SkeletonMeshBuilder.h"
    "C:/Gamedev/OpenGL-TicTacToe/libraries/assimp/code/../include/assimp/SmallVector.h"
    "C:/Gamedev/OpenGL-TicTacToe/libraries/assimp/code/../include/assimp/SmoothingGroups.h"
    "C:/Gamedev/OpenGL-TicTacToe/libraries/assimp/code/../include/assimp/SmoothingGroups.inl"
    "C:/Gamedev/OpenGL-TicTacToe/libraries/assimp/code/../include/assimp/StandardShapes.h"
    "C:/Gamedev/OpenGL-TicTacToe/libraries/assimp/code/../include/assimp/RemoveComments.h"
    "C:/Gamedev/OpenGL-TicTacToe/libraries/assimp/code/../include/assimp/Subdivision.h"
    "C:/Gamedev/OpenGL-TicTacToe/libraries/assimp/code/../include/assimp/Vertex.h"
    "C:/Gamedev/OpenGL-TicTacToe/libraries/assimp/code/../include/assimp/LineSplitter.h"
    "C:/Gamedev/OpenGL-TicTacToe/libraries/assimp/code/../include/assimp/TinyFormatter.h"
    "C:/Gamedev/OpenGL-TicTacToe/libraries/assimp/code/../include/assimp/Profiler.h"
    "C:/Gamedev/OpenGL-TicTacToe/libraries/assimp/code/../include/assimp/LogAux.h"
    "C:/Gamedev/OpenGL-TicTacToe/libraries/assimp/code/../include/assimp/Bitmap.h"
    "C:/Gamedev/OpenGL-TicTacToe/libraries/assimp/code/../include/assimp/XMLTools.h"
    "C:/Gamedev/OpenGL-TicTacToe/libraries/assimp/code/../include/assimp/IOStreamBuffer.h"
    "C:/Gamedev/OpenGL-TicTacToe/libraries/assimp/code/../include/assimp/CreateAnimMesh.h"
    "C:/Gamedev/OpenGL-TicTacToe/libraries/assimp/code/../include/assimp/XmlParser.h"
    "C:/Gamedev/OpenGL-TicTacToe/libraries/assimp/code/../include/assimp/BlobIOSystem.h"
    "C:/Gamedev/OpenGL-TicTacToe/libraries/assimp/code/../include/assimp/MathFunctions.h"
    "C:/Gamedev/OpenGL-TicTacToe/libraries/assimp/code/../include/assimp/Exceptional.h"
    "C:/Gamedev/OpenGL-TicTacToe/libraries/assimp/code/../include/assimp/ByteSwapper.h"
    "C:/Gamedev/OpenGL-TicTacToe/libraries/assimp/code/../include/assimp/Base64.hpp"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "assimp-dev" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/assimp/Compiler" TYPE FILE FILES
    "C:/Gamedev/OpenGL-TicTacToe/libraries/assimp/code/../include/assimp/Compiler/pushpack1.h"
    "C:/Gamedev/OpenGL-TicTacToe/libraries/assimp/code/../include/assimp/Compiler/poppack1.h"
    "C:/Gamedev/OpenGL-TicTacToe/libraries/assimp/code/../include/assimp/Compiler/pstdint.h"
    )
endif()

