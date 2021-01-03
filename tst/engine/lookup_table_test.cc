#include "engine/lookup_table.h"

#include <gtest/gtest.h>

#include "engine/deck.h"

class LookupTableTest: public ::testing::Test
{
  protected:
    LookupTable *lt;
    virtual void SetUp() { lt = new LookupTable(); }
    virtual void TearDown() { delete lt; }
};

TEST_F(LookupTableTest, highCard9)
{
	int cards[] = { kCard_2c, kCard_3d, kCard_4h, kCard_5s, kCard_7c, kCard_8d, kCard_9h };

  int score = lt->LookupHand(cards);

  EXPECT_EQ(score, 4145);
}

TEST_F(LookupTableTest, onePair)
{
	int cards[] = { kCard_2c, kCard_2d, kCard_4h, kCard_5s, kCard_7c, kCard_8d, kCard_9h };

  int score = lt->LookupHand(cards);

  EXPECT_EQ(score, 8227);
}

TEST_F(LookupTableTest, twoPair)
{
	int cards[] = { kCard_2c, kCard_2d, kCard_4h, kCard_4s, kCard_7c, kCard_8d, kCard_9h };

  int score = lt->LookupHand(cards);

  EXPECT_EQ(score, 12305);
}

TEST_F(LookupTableTest, threeOfAKind)
{
	int cards[] = { kCard_2c, kCard_2d, kCard_2h, kCard_5s, kCard_7c, kCard_8d, kCard_9h };

  int score = lt->LookupHand(cards);

  EXPECT_EQ(score, 16405);
}

TEST_F(LookupTableTest, straight)
{
	int cards[] = { kCard_2c, kCard_3d, kCard_4h, kCard_5s, kCard_6c, kCard_8d, kCard_9h };

  int score = lt->LookupHand(cards);

  EXPECT_EQ(score, 20482);
}

TEST_F(LookupTableTest, flush)
{
	int cards[] = { kCard_2c, kCard_3c, kCard_4c, kCard_5c, kCard_7c, kCard_8d, kCard_9h };

  int score = lt->LookupHand(cards);

  EXPECT_EQ(score, 24577);
}

TEST_F(LookupTableTest, fullHouse)
{
	int cards[] = { kCard_2c, kCard_2d, kCard_2h, kCard_5s, kCard_5c, kCard_8d, kCard_9h };

  int score = lt->LookupHand(cards);

  EXPECT_EQ(score, 28675);
}

TEST_F(LookupTableTest, fourOfAKind)
{
	int cards[] = { kCard_2c, kCard_2d, kCard_2h, kCard_2s, kCard_7c, kCard_8d, kCard_9h };

  int score = lt->LookupHand(cards);

  EXPECT_EQ(score, 32775);
}

TEST_F(LookupTableTest, royalFlush)
{
	int cards[] = { kCard_Ac, kCard_Jc, kCard_Kc, kCard_As, kCard_Qc, kCard_Ad, kCard_Tc };

  int score = lt->LookupHand(cards);

  // Royal flush
  EXPECT_EQ(score, 36874);
}