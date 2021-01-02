#include "engine/game_state.h"

#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "game/player.h"

TEST(GameState, emptyBoard)
{
  int expected_array[5] = {0, 0, 0, 0, 0};
  
  GameState *g = new GameState();
  
  EXPECT_THAT(expected_array, testing::ElementsAreArray(g->get_board(), 5));
  EXPECT_TRUE(g->get_history().empty());
}

TEST(GameState, smallBlind)
{
  int expected_array[5] = {0, 0, 0, 0, 0};
  GameState *g = new GameState();
  GameAction game_action = {kSmallBlind, 1, nullptr};
  
  g->AddGameAction(game_action);
  
  GameAction result_game_action = g->get_history().front();
  EXPECT_THAT(expected_array, testing::ElementsAreArray(g->get_board(), 5));
  EXPECT_EQ(result_game_action.action, kSmallBlind);
  EXPECT_EQ(result_game_action.amount, 1);
  EXPECT_EQ(result_game_action.author, nullptr);
}

TEST(GameState, bigBlind)
{
  int expected_array[5] = {0, 0, 0, 0, 0};
  Player *author = new Player();
  GameState *g = new GameState();
  GameAction game_action = {kBigBlind, 2, author};
  
  g->AddGameAction(game_action);
  
  GameAction result_game_action = g->get_history().front();
  EXPECT_THAT(expected_array, testing::ElementsAreArray(g->get_board(), 5));
  EXPECT_EQ(result_game_action.action, kBigBlind);
  EXPECT_EQ(result_game_action.amount, 2);
  EXPECT_EQ(result_game_action.author, author);
}

TEST(GameState, flop)
{
  int expected_array[5] = {1, 50, 15, 0, 0};
  GameState *g = new GameState();
  
  g->AddCardToBoard(1, 0);
  g->AddCardToBoard(50, 1);
  g->AddCardToBoard(15, 2);
  
  GameAction result_game_action = g->get_history().front();
  EXPECT_THAT(expected_array, testing::ElementsAreArray(g->get_board(), 5));
}

TEST(GameState, bigBlindAndFlop)
{
  int expected_array[5] = {1, 50, 15, 0, 0};
  Player *author = new Player();
  GameState *g = new GameState();
  GameAction game_action = {kBigBlind, 2, author};
  
  g->AddGameAction(game_action);
  g->AddCardToBoard(1, 0);
  g->AddCardToBoard(50, 1);
  g->AddCardToBoard(15, 2);
  
  GameAction result_game_action = g->get_history().front();
  EXPECT_THAT(expected_array, testing::ElementsAreArray(g->get_board(), 5));
  EXPECT_EQ(result_game_action.action, kBigBlind);
  EXPECT_EQ(result_game_action.amount, 2);
  EXPECT_EQ(result_game_action.author, author);
}

TEST(GameState, clearGameState)
{
  int expected_array[5] = {1, 50, 15, 0, 0};
  int empty_array[5] = {0, 0, 0, 0, 0};
  Player *author = new Player();
  GameState *g = new GameState();
  GameAction game_action = {kBigBlind, 2, author};
  
  g->AddGameAction(game_action);
  g->AddCardToBoard(1, 0);
  g->AddCardToBoard(50, 1);
  g->AddCardToBoard(15, 2);
  
  GameAction result_game_action = g->get_history().front();
  EXPECT_THAT(expected_array, testing::ElementsAreArray(g->get_board(), 5));
  EXPECT_EQ(result_game_action.action, kBigBlind);
  EXPECT_EQ(result_game_action.amount, 2);
  EXPECT_EQ(result_game_action.author, author);
  
  g->Clear();
  
  EXPECT_THAT(empty_array, testing::ElementsAreArray(g->get_board(), 5));
  EXPECT_TRUE(g->get_history().empty());
}