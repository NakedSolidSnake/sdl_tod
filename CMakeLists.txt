cmake_minimum_required(VERSION 3.7.0)

project(SDLEngine)

set(PROJECT_VERSION_MAJOR 0)
set(PROJECT_VERSION_MINOR 1)
set(PROJECT_VERSION_PATCH 0)

set(CMAKE_C_FLAGS "-D_GNU_SOURCE -Wall -std=c99")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_BUILD_TYPE Debug)

add_executable(tod "")        
target_sources(tod 
    PUBLIC 
    ${CMAKE_CURRENT_LIST_DIR}/main.c 
    ${CMAKE_CURRENT_LIST_DIR}/src/tod.c 
    
    )

target_include_directories(tod 
    PUBLIC 
    ${CMAKE_CURRENT_LIST_DIR}/include
)

target_link_libraries(tod ${GTK_LIBRARIES} SDL2)

# add_custom_command(TARGET cadastro POST_BUILD 
#                     COMMAND ${CMAKE_COMMAND} -E create_symlink ${CMAKE_SOURCE_DIR}/assets 
#                     ${CMAKE_BINARY_DIR}/bin/assets) 