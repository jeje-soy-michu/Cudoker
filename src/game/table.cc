#include "game/table.h"

#include <algorithm>

#include "engine/game_state.h"
#include "game/player.h"

Table::Table(int default_stack, int active_players, int small_blind, int big_blind, int ante):
  active_players_(active_players),
  small_blind_(small_blind),
  big_blind_(big_blind),
  ante_(ante),
  heads_up_(active_players == 2)
{
  game_state_ = new GameState();
  Player *p;
  dealer_ = p = new Player(default_stack);

  for(int i=1; i < active_players; i++) {
    p->set_next(new Player());
    p = p->get_next();
  }

  p->set_next(dealer_);
}

void Table::StartRound()
{
  Player *p = dealer_;
  int stack, bet;

  pot_ = 0;

  if (0 < ante_) {
    do {
      p = p->get_next();
      p->set_active(true);
      Bet(p, ante_, kAnte);
    } while (p != dealer_);
  }

  // Small blind, if HeadsUp dealer is the small blind
  p = (heads_up_) ? dealer_ : dealer_->get_next();
  Bet(p, small_blind_, kSmallBlind);

  // Big blind
  p = p->get_next();
  Bet(p, big_blind_, kBigBlind);
}

void Table::EndRound()
{
  dealer_ = dealer_->get_next();
}

void Table::Bet(Player *&player, int amount, Action action)
{
  int stack, bet;

  stack = player->get_stack();
  // Ensure the player has enough stack to pay, if not ALLIN.
  bet = std::min(stack, amount);
  // Update player stack
  player->set_stack(stack - bet);
  // Update pot
  pot_ += bet;
  // Update the Game State
  game_state_->AddGameAction({action, bet, player});
}

void Table::RemovePlayer(Player *p)
{
  Player *aux = dealer_;
  while(aux->get_next() != p) {
    aux = aux->get_next();
  }
  aux->set_next(p->get_next());

  heads_up_ = --active_players_ == 2;
}