/*
 * File:   action.h
 * Author: batman
 *
 * Created on August 8, 2013, 12:54 AM
 */

#ifndef ACTION_H
#define ACTION_H

#include <sstream>
#include "pokerdefs.hpp"
#include "action_type.hpp"

namespace Poker {

using std::string;

struct Action {
  amt_bb amount;
  int betting_round;
  ActionType::Enum action;

  Action() {}

  Action(ActionType::Enum _action, amt_bb _amount = amt_bb(0),
         int _betting_round = 0)
      : amount(_amount), betting_round(_betting_round), action(_action) {}

  bool operator==(const Action &oha) const {
    return (action == oha.action && amount == oha.amount &&
            betting_round == oha.betting_round);
  }

  string to_str() { return ActionType::ToStrShort[action]; }
  string to_str_w_amt() {
    std::stringstream ss;
    ss << ActionType::ToStrShort[action] << " " << decimal_cast<1>(amount);
    return ss.str();
  }

  inline bool is_raise() { return action == ActionType::Raise; }

  inline bool is_call() { return action == ActionType::Call; }

  inline bool is_fold() { return action == ActionType::Fold; }

  inline bool is_check() { return action == ActionType::Check; }

  inline bool is_bet() { return action == ActionType::Bet; }

  inline bool is_allin() { return action == ActionType::AllIn; }

  inline bool is_raise_or_bet_or_allin() {
    return is_raise() || is_bet() || is_allin();
  }
};
}

#endif /* ACTION_H */

