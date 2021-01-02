#ifndef GAME_STATE_H_
#define GAME_STATE_H_

#include <list>
#include <algorithm>

#include "game/player.h"

enum Action {
    kFold,
    kCall,
    kRaise,
    kSmallBlind,
    kBigBlind,
    kAnte
};
enum Stage {
    kBlinds,
    kPreFlop,
    kFlop,
    kTurn,
    kRiver
};

struct GameAction {
  Action action;
  int amount;
  Player *author;
};

class GameState 
{
  public:
    GameState() {}
    
    void AddGameAction(GameAction gameAction);
    void AddCardToBoard(int card, int position);
    void Clear();
    
    int* get_board() { return board_; }
    std::list<GameAction> get_history() { return history_; }
  private:
    int board_[5] = {0,0,0,0,0};
    std::list<GameAction> history_;
};

#endif // GAME_STATE_H_