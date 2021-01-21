cmake_minimum_required(VERSION 3.17)
project(minishell C)

set(CMAKE_C_STANDARD 99)

include_directories(.)

file(GLOB SRCS "srcs/*.c")
file(GLOB EXT "libft/libft.a")

add_executable(minishell ${SRCS} ${EXT})
target_link_libraries(minishell ${CMAKE_SOURCE_DIR}/libft/libft.a)