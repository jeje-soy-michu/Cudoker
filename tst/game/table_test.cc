#include "game/table.h"

#include <gtest/gtest.h>

#include "game/player.h"

void iterateOverTable(Player *&p, int table_size) {
    for (int i=0; i < table_size; i++) {
        if(p == nullptr) break;
        p = p->get_next();
    }
}

TEST(Table, defaultConstructor)
{
    Player *p, *dealer;
    Table *t = new Table();
    p = dealer = t->get_dealer();

    iterateOverTable(p, 9);
    
    EXPECT_EQ(p, dealer);
    EXPECT_EQ(dealer->get_stack(), 100);
}

TEST(Table, startWith250Stack)
{
    Table *t = new Table(250);
    
    EXPECT_EQ(t->get_dealer()->get_stack(), 250);
}

TEST(Table, headsUp)
{
    Player *p, *dealer;
    Table *t = new Table(100, 2);
    p = dealer = t->get_dealer();

    iterateOverTable(p, 2);
    
    EXPECT_EQ(p, dealer);
}

TEST(Table, table6max)
{
    Player *p, *dealer;
    Table *t = new Table(100, 6);
    p = dealer = t->get_dealer();

    iterateOverTable(p, 6);
    
    EXPECT_EQ(p, dealer);
}
