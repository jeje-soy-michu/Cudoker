add_library(twoplustwo
  TwoPlusTwoHandEvaluator/pokerlib.cpp
  TwoPlusTwoHandEvaluator/mtrand.cpp
)

target_link_libraries(${CMAKE_PROJECT_NAME} PUBLIC twoplustwo)