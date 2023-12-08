cmake_minimum_required(VERSION 3.8.2)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-narrowing")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wno-narrowing")

set(CMAKE_CXX_STANDARD 98)
set(CMAKE_C_STANDARD 90)

cmake_policy(SET CMP0048 NEW)
project("ft_printf" VERSION 0.1.0 LANGUAGES C CXX ASM)
set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_REQUIRED_LIBRARIES "-lbsd")

include_directories(include)

add_custom_target(BuildTheLib ALL
        COMMAND cd ../../libft
        COMMAND make
        )

add_library(FTLIB STATIC IMPORTED)
set_target_properties(FTLIB PROPERTIES
        IMPORTED_LOCATION ${CMAKE_CURRENT_BINARY_DIR}/../libft/libft.a # Make sure to use absolute path here
        INTERFACE_INCLUDE_DIRECTORIES ${CMAKE_CURRENT_SOURCE_DIR}/include
        INTERFACE_COMPILE_DEFINITIONS "OPTIMISTIC"
        )
add_dependencies(FTLIB BuildTheLib)

set(FT_CFLAGS
        -g3
        -Wall -Wextra -Werror
        -O0)

set(FTPRINTF_TARGET_NAME ftprintf)

set(FTPRINTF_HEADERS
        "")
set(FTPRINTF_SOURCES
        "")

file(GLOB FTPRINTF_HEADERS "ft_*.h")
file(GLOB FTPRINTF_SOURCES "ft_*.c")

#Generate the library from the sources
add_library(${FTPRINTF_TARGET_NAME} STATIC ${FTPRINTF_HEADERS} ${FTPRINTF_SOURCES})
target_include_directories(${FTPRINTF_TARGET_NAME} PRIVATE include)
target_compile_options(${FTPRINTF_TARGET_NAME} PRIVATE ${FT_CFLAGS})
target_link_libraries(${FTPRINTF_TARGET_NAME} PRIVATE FTLIB)

set(TARGET_NAME main)
set(TARGET_HEADERS
        "")
set(TARGET_SOURCES
        "")

file(GLOB TARGET_HEADERS "src/*.h")
file(GLOB TARGET_SOURCES "src/*.c")

set(TARGET_CFLAGS
        -c -w
        -g
        -fno-exceptions
        -ffunction-sections
        -fdata-sections
        -fno-threadsafe-statics
        -O0)
set(TARGET_LINK_FLAGS -w -lbsd -O0)
set(THREADS_PREFER_PTHREAD_FLAG ON)

find_package (Threads REQUIRED)
add_executable(${TARGET_NAME} ${TARGET_HEADERS} ${TARGET_SOURCES})
target_include_directories(${TARGET_NAME} PRIVATE include src)
target_compile_options(${TARGET_NAME} PRIVATE ${TARGET__CFLAGS})
target_link_options(${TARGET_NAME} PRIVATE ${DMP_LINK_FLAGS})
target_link_libraries(${TARGET_NAME} bsd ftprintf Threads::Threads)