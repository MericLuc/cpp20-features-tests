cmake_minimum_required(VERSION 3.20)

project(module_test)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(MODS_PATH ${CMAKE_BINARY_DIR}/modules)

function(add_module arg_name)
    file(MAKE_DIRECTORY ${MODS_PATH})
    add_custom_target(${arg_name}.pcm
        COMMAND ${CMAKE_COMMAND} -E echo "Building module ${arg_name}..."
        COMMAND
            ${CMAKE_CXX_COMPILER}
            -std=c++20
            -stdlib=libc++
            -fmodules
            -c ${CMAKE_CURRENT_SOURCE_DIR}/${ARGN}
            -Xclang
            -emit-module-interface
            -o ${MODS_PATH}/${arg_name}.pcm
        )
endfunction()

add_compile_options(-Wall
                    -Werr
                    -fmodules
                    -stdlib=libc++
                    -fbuiltin-module-map
                    -fimplicit-module-maps
                    -fprebuilt-module-path=${MODS_PATH}
)

add_module(mathm mathm.cpp)
add_executable(${PROJECT_NAME}
        main.cpp
        mathm.cpp
        )

# Build module before target using it
add_dependencies(${PROJECT_NAME} mathm.pcm)
