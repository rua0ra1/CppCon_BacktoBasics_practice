add_library(mathlib SHARED math.cpp)

# Expose include directory for consumers
target_include_directories(mathlib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})