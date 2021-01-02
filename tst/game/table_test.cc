#include "game/table.h"

#include <gtest/gtest.h>

#include "game/player.h"

void iterateOverTable(Player *&p, int table_size)
{
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

TEST(Table, headsUpBlindCheck)
{
  Table *t = new Table(100, 2);
  Player *dealer = t->get_dealer();

  t->StartRound();

  EXPECT_EQ(dealer->get_stack(), 99);
  Player *big_blind = dealer->get_next();
  EXPECT_EQ(big_blind->get_stack(), 98);
  EXPECT_EQ(t->get_pot(), 3);
}

TEST(Table, 6MaxNoAnte)
{
  Table *t = new Table(100, 6);
  Player *p, *small_blind = t->get_dealer()->get_next();

  t->StartRound();

  EXPECT_EQ(small_blind->get_stack(), 99);
  Player *big_blind = small_blind->get_next();
  EXPECT_EQ(big_blind->get_stack(), 98);

  p = big_blind;
  for(int i=0; i<4; i++) {
    p = p->get_next();
    EXPECT_EQ(p->get_stack(), 100);
  }

  EXPECT_EQ(t->get_pot(), 3);
}

TEST(Table, 9MaxAnte)
{
  Table *t = new Table(100, 9, 1, 2, 1);
  Player *p, *small_blind = t->get_dealer()->get_next();

  t->StartRound();

  EXPECT_EQ(small_blind->get_stack(), 98);
  Player *big_blind = small_blind->get_next();
  EXPECT_EQ(big_blind->get_stack(), 97);

  p = big_blind;
  for(int i=0; i<7; i++) {
    p = p->get_next();
    EXPECT_EQ(p->get_stack(), 99);
  }

  EXPECT_EQ(t->get_pot(), 12);
}

TEST(Table, nextDealer)
{
  Table *t = new Table();
  Player *next_dealer = t->get_dealer()->get_next();

  t->EndRound();

  EXPECT_EQ(t->get_dealer(), next_dealer);
}