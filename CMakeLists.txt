cmake_minimum_required(VERSION 3.16)
project(cardboard_game_engine)

set(CMAKE_EXPORT_COMPILE_COMMANDS on)

set(CARDBOARD_GRAPHICS_TARGET "none" CACHE STRING "Gameengine rendering target")
set(CARDBOARD_GRAPHICS_LIBRARIES)
set(CARDBOARD_GRAPHICS_SOURCES)

if(CARDBOARD_GRAPHICS_TARGET STREQUAL "opengl")
	find_package(OpenGL REQUIRED)
	find_package(glfw3 REQUIRED)
	add_subdirectory(${PROJECT_SOURCE_DIR}/dep/glad)
	include_directories(${PROJECT_SOURCE_DIR}/dep/glad/include)

	set(CARDBOARD_GRAPHICS_LIBRARIES
		OpenGL::GL
		glfw
		glad
	)

	set(CARDBOARD_GRAPHICS_SOURCES
		${PROJECT_SOURCE_DIR}/src/graphics/opengl/context.cpp
		${PROJECT_SOURCE_DIR}/src/graphics/opengl/shader.cpp
		${PROJECT_SOURCE_DIR}/src/graphics/opengl/vertex_buffer.cpp
		${PROJECT_SOURCE_DIR}/src/graphics/opengl/element_buffer.cpp
		${PROJECT_SOURCE_DIR}/src/graphics/opengl/window.cpp
		${PROJECT_SOURCE_DIR}/src/graphics/opengl/mesh.cpp
	)
else()
	message(FATAL_ERROR "There was no graphics target specified! ${CARDBOARD_GRAPHICS_TARGET}")
endif()

file(COPY ${PROJECT_SOURCE_DIR}/assets DESTINATION ${PROJECT_BINARY_DIR})

set(SOURCES
	${PROJECT_SOURCE_DIR}/src/main.cpp
	${PROJECT_SOURCE_DIR}/src/resources/file.cpp
	${PROJECT_SOURCE_DIR}/src/graphics/vertex.cpp
	${CARDBOARD_GRAPHICS_SOURCES}
)

include_directories(${PROJECT_SOURCE_DIR}/src)

add_executable(cardboard_game_engine ${SOURCES})
	
target_compile_features(cardboard_game_engine PRIVATE cxx_std_17)

target_link_libraries(cardboard_game_engine 
	${CARDBOARD_GRAPHICS_LIBRARIES}
)

