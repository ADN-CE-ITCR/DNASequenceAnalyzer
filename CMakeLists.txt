cmake_minimum_required(VERSION 3.1.3)

project(DNASequenceAligner)
find_package (Threads)
set(SOURCE_ALIGNER DNASequenceAligner/main.c
                   DNASequenceAligner/alignerFunctions.c
                   globalConstants.c)
add_executable(DNASequenceAligner ${SOURCE_ALIGNER})
target_link_libraries (DNASequenceAligner ${CMAKE_THREAD_LIBS_INIT})

project(DNASequenceGenerator)
find_package (Threads)
set(SOURCE_GENERATOR DNASequenceGenerator/main.c
                     DNASequenceGenerator/generatorFunctions.c
                     globalConstants.c)
add_executable(DNASequenceGenerator ${SOURCE_GENERATOR})
target_link_libraries (DNASequenceGenerator ${CMAKE_THREAD_LIBS_INIT})