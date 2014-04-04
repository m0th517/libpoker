#include "player.h"
#include <iostream>

namespace Poker {

Player::Player() : Player("") {}

Player::Player(string _name) : name(_name), bankroll(0), invested(4, amt_bb(0)) {}

Player::Player(string _name, amt_bb _bankroll)
    : name(_name), bankroll(_bankroll), invested(4, amt_bb(0)) {}

Player::Player(string _name, amt_bb _bankroll, vector<amt_bb> _invested)
    : name(_name), bankroll(_bankroll), invested(_invested) {}

Player::Player(const Player &op) {
  name = op.name;
  bankroll = op.bankroll;
  invested = op.invested;
}

Player& Player::operator=(const Player &op){
  name = op.name;
  bankroll = op.bankroll;
  invested = op.invested;
  return *this;
}

Player::~Player() {}

bool Player::make_investment(amt_bb amount, PhaseType::Enum phase) {
  if (bankroll < amount)
    return false;
  bankroll -= amount;
  invested[static_cast<unsigned>(phase)] += amount;
  return true;
}

amt_bb Player::total_investment() const {
  amt_bb sum(0);
  for (unsigned i = 0; i < 4; ++i)
    sum += invested[i];
  return sum;
}
}
