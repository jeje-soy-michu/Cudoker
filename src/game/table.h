#ifndef TABLE_H_
#define TABLE_H_

#include "game/player.h"

#include <vector>

class Table
{
    public:
        Table(int default_stack=100, int size=9, int small_blind=1, int big_blind=2);
        
        Player* get_dealer() { return dealer_; };
        void set_dealer(Player* dealer) { dealer_ = dealer; };
    private:
        Player* dealer_;
        int small_blind_, big_blind_;
};

#endif // TABLE_H_