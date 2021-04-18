add_executable(MC TestMC.cpp NormalGenerator.cpp NormalGenerator.h OptionData.h Range.cpp Range.cpp)

find_package(Boost 1.75.0 REQUIRED)
target_link_libraries(MC Boost::boost)