cmake_minimum_required(VERSION 3.19)
project(matrix)

set(CMAKE_CXX_STANDARD 11)

set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib/)

include_directories(sparse/
        sparse/utils/
        )

set(SRC_FILE
        sparse/testVec.cpp
        sparse/CoorSchema.cpp
        sparse/CoorSchema.h
        sparse/LinkedMatrix.cpp
        sparse/LinkedMatrix.h
        sparse/PackedMatrix.cpp
        sparse/PackedMatrix.h
        sparse/PackedVector.cpp
        sparse/PackedVector.h
        sparse/utils/SortUtil.cpp
        sparse/utils/SortUtil.h
        sparse/utils/StringUtil.cpp
        sparse/utils/StringUtil.h
        sparse/transform.cpp
        sparse/transform.h
        )

add_library(SparseMatrix STATIC ${SRC_FILE})

link_libraries(SparseMatrix)

add_executable(matrix main.cpp)

add_executable(test_vec sparse/testVec.cpp)

add_executable(test_mat sparse/testMat.cpp)
