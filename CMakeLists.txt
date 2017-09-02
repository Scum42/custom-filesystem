cmake_minimum_required(VERSION 2.6)

set(PROJECT CustomFilesystem)
set(EXE cf)

project(${PROJECT})

FILE(GLOB_RECURSE SOURCES src/*)
add_executable(
    ${PROJECT}
    ${SOURCES}
)

set_target_properties(
    ${PROJECT}
    PROPERTIES OUTPUT_NAME ${EXE}
)