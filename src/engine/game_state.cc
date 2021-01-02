#include "engine/game_state.h"

void GameState::AddGameAction(GameAction gameAction)
{
  history_.push_back(gameAction);
}

void GameState::AddCardToBoard(int card, int position)
{
  board_[position] = card;
}

void GameState::Clear()
{
  history_.clear();
  std::fill(board_, board_+5, 0);
}