cmake_minimum_required(VERSION 3.22)

set(VCPKG_ROOT "/home/ivan/vcpkg")

set(CMAKE_TOOLCHAIN_FILE "${VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake")

project(TaskTableParser)

set(CMAKE_CXX_STANDARD 20)

set(CLASSES StringOperations TableParser)

set(HEADERS ${CLASSES} Utility)
list(TRANSFORM HEADERS PREPEND include/)
list(TRANSFORM HEADERS APPEND .hpp)

set(SOURSES ${CLASSES} main)
list(TRANSFORM SOURSES PREPEND src/)
list(TRANSFORM SOURSES APPEND .cpp)

add_executable(TaskTableParser ${HEADERS} ${SOURSES})

target_include_directories(TaskTableParser PRIVATE include/)
