cmake_minimum_required(VERSION 3.22)
project(zappy)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/build)

if(APPLE)
    include_directories(/opt/homebrew/include)
    link_directories(/opt/homebrew/lib)
endif()

include_directories(libs/gll/include)
include_directories(server/include)
include_directories(ai/include)
include_directories(gui/include)

file(GLOB_RECURSE GLL_SRC "libs/gll/src/*.c")
file(GLOB_RECURSE SERVER_SRC "server/src/*.c")
file(GLOB_RECURSE GUI_SRC "gui/src/*.cpp")
set(AI_SRC "${CMAKE_SOURCE_DIR}/ai/src/zappy_ai")

add_library(gll STATIC ${GLL_SRC})
target_compile_options(gll PRIVATE -W -Wall -Wextra -Werror)

add_executable(server ${SERVER_SRC})
target_link_libraries(server gll)
target_compile_options(server PRIVATE -W -Wall -Wextra -Werror)
set_target_properties(server PROPERTIES OUTPUT_NAME "zappy_server")


add_executable(gui ${GUI_SRC})
target_link_libraries(gui sfml-graphics sfml-window sfml-system sfml-audio)
target_compile_options(gui PRIVATE -W -Wall -Wextra -Werror)
set_target_properties(gui PROPERTIES OUTPUT_NAME "zappy_gui")

add_custom_command(
    OUTPUT ${CMAKE_BINARY_DIR}/zappy_ai
    COMMAND ${CMAKE_COMMAND} -E copy ${AI_SRC} ${CMAKE_BINARY_DIR}/zappy_ai
    DEPENDS ${AI_SRC}
)

add_custom_target(zappy_server
    COMMAND ${CMAKE_COMMAND} --build ${CMAKE_BINARY_DIR} --target server
)

add_custom_target(zappy_ai ALL DEPENDS ${CMAKE_BINARY_DIR}/zappy_ai)

add_custom_target(zappy_gui
    COMMAND ${CMAKE_COMMAND} --build ${CMAKE_BINARY_DIR} --target gui
)
