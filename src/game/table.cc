#include "game/table.h"

#include "game/player.h"

Table::Table(int default_stack, int size, int small_blind, int big_blind): small_blind_(small_blind), big_blind_(big_blind)
{
    Player *p;
    dealer_ = p = new Player(default_stack);
    for(int i=1; i < size; i++) {
        p->set_next(new Player());
        p = p->get_next();
    }
    p->set_next(dealer_);
}