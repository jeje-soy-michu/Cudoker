#include "game/player.h"

#include <gtest/gtest.h>

TEST(Player, defaultStack)
{
    Player *p = new Player();
    
    EXPECT_EQ(p->get_stack(), 100);
}

TEST(Player, differentStack)
{
    Player *p = new Player(200);
    
    EXPECT_EQ(p->get_stack(), 200);
}

TEST(Player, updateStack)
{
    Player *p = new Player();
    
    p->set_stack(150);
    
    EXPECT_EQ(p->get_stack(), 150);
}

TEST(Player, nextPlayer)
{
    Player *p = new Player(), *aux = new Player();
    
    p->set_next(aux);
    
    EXPECT_EQ(p->get_next(), aux);
}

TEST(Player, nextPlayerConstructor)
{
    Player *aux = new Player(), *p = new Player(aux);
    
    p->set_next(aux);
    
    EXPECT_EQ(p->get_next(), aux);
}