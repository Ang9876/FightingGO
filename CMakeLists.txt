cmake_minimum_required(VERSION 3.8)
project(CGpipeline)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_EXE_LINKER_FLAGS "-lGLFW3 -framework Cocoa -framework OpenGL -framework IOKit -framework CoreVideo -lassimp")
set(SOURCE_FILES main.cpp glad.cpp Shader.cpp Shader.h stb_image.h stb_image.cpp Camera.h Mesh.h Model.h Light.h Monster.cpp Monster.h Model.cpp Tree.cpp Tree.h surface.cpp surface.h Gun.cpp Gun.h ifCollision.cpp ifCollision.h Skybox.cpp Skybox.h)
add_executable(CGpipeline ${SOURCE_FILES})