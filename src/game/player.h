#ifndef PLAYER_H_
#define PLAYER_H_

class Player
{
  public:
    Player(int stack=100): Player(nullptr, stack) {}
    Player(Player* next, int stack=100);

    bool is_active() { return active_; }
    int get_stack() { return stack_; }
    Player* get_next() { return next_; }

    void set_active(bool active) { active_ = active; }
    void set_stack(int stack) { stack_ = stack; }
    void set_next(Player* next) { next_ = next; }
  private:
    bool active_;
    int stack_;
    Player *next_;
};

#endif // PLAYER_H_