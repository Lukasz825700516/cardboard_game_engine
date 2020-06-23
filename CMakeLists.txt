cmake_minimum_required(VERSION 3.16)
project(cardboard_game_engine)

set(CMAKE_EXPORT_COMPILE_COMMANDS on)

set(CARDBOARD_GRAPHICS_TARGET "none" CACHE STRING "Gameengine rendering target")
set(CARDBOARD_RESOURCES_WINDOWS_TARGET "none" CACHE STRING "Gameengine resource window target")

add_subdirectory(${PROJECT_SOURCE_DIR}/dep/stbi)
include_directories(${PROJECT_SOURCE_DIR}/dep/stbi)

include_directories(${PROJECT_SOURCE_DIR}/dep/glm)

if(CARDBOARD_GRAPHICS_TARGET STREQUAL "opengl")
	find_package(OpenGL REQUIRED)
	add_subdirectory(${PROJECT_SOURCE_DIR}/dep/glad)
	include_directories(${PROJECT_SOURCE_DIR}/dep/glad/include)


	set(CARDBOARD_GRAPHICS_LIBRARIES
		OpenGL::GL
		glad
	)

	set(CARDBOARD_GRAPHICS_SOURCES
		${PROJECT_SOURCE_DIR}/src/graphics/opengl/context.cpp
		${PROJECT_SOURCE_DIR}/src/graphics/opengl/shader.cpp
		${PROJECT_SOURCE_DIR}/src/graphics/opengl/vertex_buffer.cpp
		${PROJECT_SOURCE_DIR}/src/graphics/opengl/element_buffer.cpp
		${PROJECT_SOURCE_DIR}/src/graphics/opengl/vertex_array.cpp
		${PROJECT_SOURCE_DIR}/src/graphics/opengl/quad_renderer.cpp
		${PROJECT_SOURCE_DIR}/src/graphics/opengl/texture.cpp
		${PROJECT_SOURCE_DIR}/src/graphics/opengl/texture_batch.cpp
		${PROJECT_SOURCE_DIR}/src/graphics/texture_data.cpp
		${PROJECT_SOURCE_DIR}/src/graphics/particle_system.cpp
	)
else()
	message(FATAL_ERROR "There was no graphics target specified! ${CARDBOARD_GRAPHICS_TARGET}")
endif()

if(CARDBOARD_RESOURCES_WINDOWS_TARGET STREQUAL "glfw")
	add_subdirectory(${PROJECT_SOURCE_DIR}/dep/glfw)
	include_directories(${PROJECT_SOURCE_DIR}/dep/glfw/include)

	set(CARDBOARD_RESOURCES_WINDOWS_LIBRARIES
		glfw
	)

	set(CARDBOARD_RESOURCES_WINDOWS_SOURCES
		${PROJECT_SOURCE_DIR}/src/resources/glfw/window.cpp
		${PROJECT_SOURCE_DIR}/src/resources/glfw/keyboard.cpp
		${PROJECT_SOURCE_DIR}/src/resources/glfw/mouse.cpp
		${PROJECT_SOURCE_DIR}/src/resources/texture_loader.cpp
	)
else()
	message(FATAL_ERROR "There was no windows target specified! ${CARDBOARD_RESOURCES_WINDOWS_TARGET}")
endif()

file(COPY ${PROJECT_SOURCE_DIR}/assets DESTINATION ${PROJECT_BINARY_DIR})

set(SOURCES
	${PROJECT_SOURCE_DIR}/src/main.cpp
	${PROJECT_SOURCE_DIR}/src/resources/file.cpp
	${PROJECT_SOURCE_DIR}/src/graphics/vertex.cpp
	${PROJECT_SOURCE_DIR}/src/graphics/camera.cpp
	${CARDBOARD_RESOURCES_WINDOWS_SOURCES}
	${CARDBOARD_GRAPHICS_SOURCES}
)

include_directories(${PROJECT_SOURCE_DIR}/src)

add_executable(cardboard_game_engine ${SOURCES})
	
target_compile_features(cardboard_game_engine PRIVATE cxx_std_17)
if(MSVC)
  target_compile_options(cardboard_game_engine PRIVATE /W4 /WX)
else()
  target_compile_options(cardboard_game_engine PRIVATE -Wall -Wextra -pedantic -Werror)
endif()

target_link_libraries(cardboard_game_engine 
	${CARDBOARD_RESOURCES_WINDOWS_LIBRARIES}
	${CARDBOARD_GRAPHICS_LIBRARIES}
	stbi
)

