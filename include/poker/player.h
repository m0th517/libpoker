/*
 * File:   player.h
 * Author: batman
 *
 * Created on August 8, 2013, 12:08 AM
 */

#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>
#include "pokerdefs.h"
#include "phase_type.h"

namespace Poker {

using std::vector;
using std::string;

class Player {
public:
  string name;
  amt_bb bankroll;
  vector<amt_bb> invested;

  Player();
  Player(string _name);
  Player(string _name, amt_bb _bankroll);
  Player(string _name, amt_bb _bankroll, vector<amt_bb> _invested);
  Player(const Player &p);
  Player& operator=(const Player &p);

  virtual ~Player();
  bool make_investment(amt_bb amount, PhaseType::Enum phase);
  amt_bb total_investment() const;
};
}

#endif /* PLAYER_H */

