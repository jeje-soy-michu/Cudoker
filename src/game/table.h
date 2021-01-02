#ifndef TABLE_H_
#define TABLE_H_

#include <vector>

#include "engine/game_state.h"
#include "game/player.h"

class Table
{
  public:
    Table(int default_stack=100, int active_players=9, int small_blind=1, int big_blind=2, int ante=0);

    void StartRound();
    void PreFlop();
    void Flop();
    void Turn();
    void River();
    void EndRound();

    Player *get_dealer() { return dealer_; }
    int get_pot() { return pot_; }

    void set_dealer(Player *dealer) { dealer_ = dealer; }
  private:
    bool heads_up_;
    int  ante_, big_blind_, pot_, small_blind_, active_players_;
    GameState *game_state_;
    Player *dealer_;

    void Bet(Player *&player, int amount, Action action);
    void RemovePlayer(Player *player);
};

#endif // TABLE_H_