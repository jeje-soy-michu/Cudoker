set(OUT_FILE ${CMAKE_PROJECT_NAME}_run)
add_library(${CMAKE_PROJECT_NAME}
  engine/deck.h
  engine/deck.cc
  engine/game_state.h
  engine/game_state.cc
  engine/lookup_table.h
  engine/lookup_table.cc

  game/player.h
  game/player.cc
  game/table.h
  game/table.cc
)

add_executable(OUT_FILE main.cc)
target_link_libraries(OUT_FILE ${CMAKE_PROJECT_NAME})
