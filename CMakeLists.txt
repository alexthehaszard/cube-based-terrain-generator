cmake_minimum_required(VERSION 3.5)
project(cube-based-terrain-generator)

find_package(OpenGL REQUIRED)
find_package(glfw3 3.4 REQUIRED)

file(GLOB_RECURSE SOURCE_FILES 
	${CMAKE_SOURCE_DIR}/src/*.cpp)
	
file(GLOB_RECURSE HEADER_FILES 
	${CMAKE_SOURCE_DIR}/src/*.h)

include_directories(${CMAKE_BINARY_DIR}/src)

add_executable(${PROJECT_NAME} 
    ${HEADER_FILES} 
    ${SOURCE_FILES}
)

include_directories(
	"${CMAKE_SOURCE_DIR}/src"
	"${CMAKE_SOURCE_DIR}/include"
)

target_link_libraries(${PROJECT_NAME} 
    ${OPENGL_LIBRARY} 
    glfw
)
