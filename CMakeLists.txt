cmake_minimum_required(VERSION 3.1.3)

project(DNASequenceAligner)
set(SOURCE_ALIGNER DNASequenceAligner/main.c)
add_executable(DNASequenceAligner ${SOURCE_ALIGNER})

project(DNASequenceGenerator)
set(SOURCE_GENERATOR DNASequenceGenerator/main.c
                     DNASequenceGenerator/constants.c)
add_executable(DNASequenceGenerator ${SOURCE_GENERATOR})