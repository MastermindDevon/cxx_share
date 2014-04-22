cmake_minimum_required(VERSION 2.8)

SET(CMAKE_CXX_COMPILER g++ )
SET(CMAKE_C_COMPILER gcc )
SET(CMAKE_CXX_FLAGS  "-O3 ")
SET(CMAKE_C_FLAGS  "-O3 ")
SET(CMAKE_Fortran_FLAGS  "-Wno-deprecated -O3")

SET(CMAKE_EXE_LINKER_FLAGS "")

project(gpuprof2file)

SET(CMAKE_BUILD_TYPE "Release")


# ADD_DEFINITIONS(-DMYAPP_EPETRA)

INCLUDE_DIRECTORIES(
                    )
LINK_DIRECTORIES(
                )

add_executable(
gpuprof2file
gpuprof2file.c
gpuprof2file_maintest.c
)


# C-Files for GPU OpenCL Code:
set_source_files_properties(gpuprof2file.c PROPERTIES LANGUAGE C)
set_source_files_properties(gpuprof2file_maintest.c PROPERTIES LANGUAGE C)
