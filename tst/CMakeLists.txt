enable_testing()

add_executable(tests
    main_test.cc
    
    game/player_test.cc
    game/table_test.cc
)
    
target_link_libraries(tests PUBLIC ${CMAKE_PROJECT_NAME} gtest)

include(GoogleTest)

gtest_discover_tests(tests)