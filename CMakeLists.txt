cmake_minimum_required(VERSION 3.6)
project(c_facil__2_)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    config/cscope_maps.vim
    config/exrc
    config/indent.pro
    config/vim_spell_en.tar
    config/vim_spell_es.tar
    arabToRomano
    arabToRomano.c
    arabToRomano.o
    c_facil.h
    LEEME
    makefile)

add_executable(c_facil__2_ ${SOURCE_FILES})