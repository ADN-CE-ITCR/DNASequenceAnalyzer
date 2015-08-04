cmake_minimum_required(VERSION 3.0.2)

######################################
project(DNASequenceAligner)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c99" -Wformat-security" -Wformat=")
 set(CMAKE_C_FLAGS "-std=c99") 
find_package (Threads)
set(SOURCE_ALIGNER DNASequenceAligner/main.c
                   DNASequenceAligner/alignerFunctions.c
                   globalConstants.c)
add_executable(DNASequenceAligner ${SOURCE_ALIGNER})
target_link_libraries (DNASequenceAligner ${CMAKE_THREAD_LIBS_INIT})


######################################
project(DNASequenceGenerator)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c11" -Wformat-security" -Wformat=")
find_package (Threads)
set(SOURCE_GENERATOR DNASequenceGenerator/main.c
                     DNASequenceGenerator/generatorFunctions.c
                     globalConstants.c)
add_executable(DNASequenceGenerator ${SOURCE_GENERATOR})
target_link_libraries (DNASequenceGenerator ${CMAKE_THREAD_LIBS_INIT})
