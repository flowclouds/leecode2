# cmake_minimum_required(VERSION <specify CMake version here>)
project(leecode2)

set(CMAKE_CXX_STANDARD 14)

#add_executable(leecode2 main.cpp)
#add_executable(leetcode/editor/cn/ [767]重构字符串.cpp)
#add_executable(leecode2 leetcode/editor/cn/asfasdf.cpp)

file (GLOB_RECURSE files *.cpp)
foreach (file ${files})
    string(REGEX REPLACE ".+/(.+)\\..*" "\\1" exe ${file})
    add_executable (${exe} ${file})
    message (\ \ \ \ --\ src/${exe}.cpp\ will\ be\ compiled\ to\ bin/${exe})
endforeach ()

