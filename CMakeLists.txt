cmake_minimum_required(VERSION 3.16)
project(cardboard_game_engine)

set(CMAKE_EXPORT_COMPILE_COMMANDS on)

set(CARDBOARD_GRAPHICS_TARGET "none" CACHE STRING "Gameengine rendering target")
set(CARDBOARD_WINDOWS_TARGET "none" CACHE STRING "Gameengine resource window target")

# --------------------------------------------------------------------------------
# DEPENDENCIES

# STBI - image loading
add_subdirectory(${PROJECT_SOURCE_DIR}/dep/stbi)
include_directories(${PROJECT_SOURCE_DIR}/dep/stbi)
set(CARDBOARD_DEPENDENCIES_LIBRARIES ${CARDBOARD_DEPENDENCIES_LIBRARIES}
	stbi
)

# GLM - fast math
include_directories(${PROJECT_SOURCE_DIR}/dep/glm)

# IMGUI - editor gui
include_directories(${PROJECT_SOURCE_DIR}/dep/imgui)
include_directories(${PROJECT_SOURCE_DIR}/dep/cardboard_imgui)
set(IMGUI_SOURCES ${IMGUI_SOURCES}
	${PROJECT_SOURCE_DIR}/dep/imgui/imgui.cpp
	${PROJECT_SOURCE_DIR}/dep/imgui/imgui_draw.cpp
	${PROJECT_SOURCE_DIR}/dep/imgui/imgui_widgets.cpp
	${PROJECT_SOURCE_DIR}/dep/imgui/imgui_demo.cpp
)
if(CARDBOARD_GRAPHICS_TARGET STREQUAL "opengl")
	add_compile_definitions(IMGUI_IMPL_OPENGL_LOADER_GLAD)
	set(IMGUI_SOURCES ${IMGUI_SOURCES}
		${PROJECT_SOURCE_DIR}/dep/imgui/examples/imgui_impl_opengl3.cpp
	)
endif()
if(CARDBOARD_WINDOWS_TARGET STREQUAL "glfw")
	set(IMGUI_SOURCES ${IMGUI_SOURCES}
		${PROJECT_SOURCE_DIR}/dep/imgui/examples/imgui_impl_glfw.cpp
	)
endif()
add_library(imgui ${IMGUI_SOURCES})
set(CARDBOARD_DEPENDENCIES_LIBRARIES ${CARDBOARD_DEPENDENCIES_LIBRARIES}
	imgui
)

# --------------------------------------------------------------------------------
# TARGETS
# GRAPHICAL

if(CARDBOARD_GRAPHICS_TARGET STREQUAL "opengl")
	find_package(OpenGL REQUIRED)
	add_subdirectory(${PROJECT_SOURCE_DIR}/dep/glad)
	include_directories(${PROJECT_SOURCE_DIR}/dep/glad/include)


	set(CARDBOARD_GRAPHICS_LIBRARIES ${CARDBOARD_GRAPHICS_LIBRARIES}
		OpenGL::GL
		glad
	)

	set(CARDBOARD_GRAPHICS_SOURCES ${CARDBOARD_GRAPHICS_SOURCES}
		${PROJECT_SOURCE_DIR}/src/graphics/opengl/context.cpp
		${PROJECT_SOURCE_DIR}/src/graphics/opengl/shader.cpp
		${PROJECT_SOURCE_DIR}/src/graphics/opengl/vertex_buffer.cpp
		${PROJECT_SOURCE_DIR}/src/graphics/opengl/element_buffer.cpp
		${PROJECT_SOURCE_DIR}/src/graphics/opengl/vertex_array.cpp
		${PROJECT_SOURCE_DIR}/src/graphics/opengl/quad_renderer.cpp
		${PROJECT_SOURCE_DIR}/src/graphics/opengl/texture.cpp
		${PROJECT_SOURCE_DIR}/src/graphics/opengl/texture_batch.cpp
	)
else()
	message(FATAL_ERROR "There was no graphics target specified! ${CARDBOARD_GRAPHICS_TARGET}")
endif()

set(CARDBOARD_GRAPHICS_SOURCES ${CARDBOARD_GRAPHICS_SOURCES}
	${PROJECT_SOURCE_DIR}/src/graphics/particle_system.cpp
	${PROJECT_SOURCE_DIR}/src/graphics/camera.cpp
)

add_compile_definitions(CARDBOARD_GRAPHICS_TARGET_OPENGL)

# --------------------------------------------------------------------------------
# TARGETS
# WINDOWS

if(CARDBOARD_WINDOWS_TARGET STREQUAL "glfw")
	add_subdirectory(${PROJECT_SOURCE_DIR}/dep/glfw)
	include_directories(${PROJECT_SOURCE_DIR}/dep/glfw/include)

	set(CARDBOARD_WINDOWS_LIBRARIES ${CARDBOARD_WINDOWS_LIBRARIES}
		glfw
	)

	set(CARDBOARD_WINDOWS_SOURCES ${CARDBOARD_WINDOWS_SOURCES}
		${PROJECT_SOURCE_DIR}/src/resources/glfw/window.cpp
		${PROJECT_SOURCE_DIR}/src/resources/glfw/keyboard.cpp
		${PROJECT_SOURCE_DIR}/src/resources/glfw/mouse.cpp
	)
else()
	message(FATAL_ERROR "There was no windows target specified! ${CARDBOARD_WINDOWS_TARGET}")
endif()

set(CARDBOARD_WINDOWS_SOURCES ${CARDBOARD_WINDOWS_SOURCES}
	${PROJECT_SOURCE_DIR}/src/resources/texture_loader.cpp
	${PROJECT_SOURCE_DIR}/src/resources/file.cpp
)

add_compile_definitions(CARDBOARD_WINDOWS_TARGET_GLFW)

# --------------------------------------------------------------------------------
# ASSETS

file(COPY ${PROJECT_SOURCE_DIR}/assets DESTINATION ${PROJECT_BINARY_DIR})

# --------------------------------------------------------------------------------
# MAIN EXECUTABLE

include_directories(${PROJECT_SOURCE_DIR}/src)

add_executable(cardboard_game_engine
	${PROJECT_SOURCE_DIR}/src/main.cpp
	${CARDBOARD_WINDOWS_SOURCES}
	${CARDBOARD_GRAPHICS_SOURCES}
	${CARDBOARD_DEPENDENCIES_SOURCES}
)

target_link_libraries(cardboard_game_engine 
	${CARDBOARD_WINDOWS_LIBRARIES}
	${CARDBOARD_GRAPHICS_LIBRARIES}
	${CARDBOARD_DEPENDENCIES_LIBRARIES}
)
	
# --------------------------------------------------------------------------------
# MAIN EXECUTABLE
# COMPILER OPTIONS

target_compile_features(cardboard_game_engine PRIVATE cxx_std_17)
if(MSVC)
  target_compile_options(cardboard_game_engine PRIVATE /W4 /WX)
else()
  target_compile_options(cardboard_game_engine PRIVATE -Wall -Wextra -pedantic -Werror)
endif()


