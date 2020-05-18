project(glad)

include_directories(${PROJECT_SOURCE_DIR}/include)
add_library(glad SHARED ${PROJECT_SOURCE_DIR}/src/glad.c)
