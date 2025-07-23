cmake_minimum_required(VERSION 3.5)
project(cube-based-terrain-generator)

set(CMAKE_CXX_STANDARD 17)

find_package(OpenGL REQUIRED)
find_package(glfw3 3.4 REQUIRED)
find_package(GLEW REQUIRED HINTS /usr/local/Cellar/glew)
find_package(glm REQUIRED HINTS /usr/local/Cellar/glm)
find_package(GLUT REQUIRED)

file(GLOB_RECURSE SOURCE_FILES 
	${CMAKE_SOURCE_DIR}/src/*.cpp)
	
file(GLOB_RECURSE HEADER_FILES 
	${CMAKE_SOURCE_DIR}/src/*.h)

include_directories(${CMAKE_BINARY_DIR}/src)
include_directories(${CMAKE_BINARY_DIR}/thirdparty/include)

add_executable(${PROJECT_NAME} 
    ${HEADER_FILES} 
    ${SOURCE_FILES}
)

include_directories(
	"${CMAKE_SOURCE_DIR}/src"
	"${CMAKE_SOURCE_DIR}/include"
    ${OPENGL_INCLUDE_DIRS}
    ${GLEW_INCLUDE_DIRS}
    ${GLM_INCLUDE_DIRS}
    ${GLUT_INCLUDE_DIRS}
)

target_link_libraries(${PROJECT_NAME} 
    ${OPENGL_LIBRARIES}
    GLEW::GLEW
    GLUT::GLUT
    glm::glm
    glfw
)
