cmake_minimum_required(VERSION 3.17)
project(KattisProblems)

set(CMAKE_CXX_STANDARD 14)

add_executable(SingleSourceNegativeWeights singleSourceNegativeWeights.cpp)
add_executable(WaifUntilDark WaifUntilDark.cpp)
add_executable(Treehouse treehouses.cpp)
add_executable(LostMap lostMap.cpp)
add_executable(LostMap2 lostMap2.cpp)
add_executable(01Sequences 01Sequences.cpp)
add_executable(01Sequences2 01Sequences2.cpp)
add_executable(ACMScoringContest ACMScoringContest.cpp)
add_executable(A1Paper A1Paper.cpp)
add_executable(LaptopSticker LaptopSticker.cpp)

add_executable(10KindsOfPeople 10KindsOfPeople.cpp)
add_executable(PearWiseVoting MSOE2021Summer/Week1/PearWiseVoting.cpp)
add_executable(RomanHolidays MSOE2021Summer/Week1/RomanHolidays.cpp)
add_executable(PizzaCutting MSOE2021Summer/Week1/PizzaCutting.cpp)
add_executable(CarVet MSOE2021Summer/Week1/CarVet.cpp)
add_executable(ToursDeSalesForce MSOE2021Summer/Week1/ToursDeSalesForce.cpp)
add_executable(PunctiliousCruciverbalist MSOE2021Summer/Week1/PunctiliousCruciverbalist.cpp)
add_executable(Difference MSOE2021Summer/Week1/Difference.cpp)
add_executable(RandomProblem MSOE2021Summer/Week1/RandomProblem.cpp)


#include_directories(/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/include/c++)
#include_directories(/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/include/c++/v1)