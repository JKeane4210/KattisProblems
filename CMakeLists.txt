cmake_minimum_required(VERSION 3.17)
project(KattisProblems)

set(CMAKE_CXX_STANDARD 14)

add_executable(SingleSourceNegativeWeights singleSourceNegativeWeights.cpp)
add_executable(WaifUntilDark WaifUntilDark.cpp)
add_executable(Treehouse treehouses.cpp)
add_executable(LostMap lostMap.cpp)
add_executable(LostMap2 lostMap2.cpp)

#include_directories(/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/include/c++)
#include_directories(/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/include/c++/v1)