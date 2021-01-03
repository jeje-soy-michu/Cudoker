#ifndef LOOKUP_TABLE_H_
#define LOOKUP_TABLE_H_

#include <TwoPlusTwoHandEvaluator/poker.h>

class LookupTable
{
  public:
    LookupTable();
    
    int LookupHand(int* pCards);
  private:
    int numIDs = 1;
    int numcards = 0;
    int64_t maxID = 0;
    inline int min(int const x, int const y) {
      return y < x ? y : x;
    }

    const char *kOutputPath = "twoplustwo.bin";
    int hand_rank_[32487834];
    
    int DoEval(int64_t IDin);
    bool LoadFromFile();
    int64_t MakeID(int64_t IDin, int newcard);
    int SaveID(int64_t ID, int64_t *card_ids);
    void SaveToFile();
};

#endif // LOOKUP_TABLE_H_
