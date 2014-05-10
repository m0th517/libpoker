#ifndef ACTION_H
#define ACTION_H

#include <sstream>
#include "pokerdefs.hpp"
#include "action_type.hpp"

namespace poker {

using std::string;
using namespace pokerdefs;

// ----------------------------------------------------------------------
/// @brief   Representation of a Action a player made.
// ----------------------------------------------------------------------
struct Action {
  /// the amount of money the action costs
  bb amount;
  ActionType::Enum action;

  // ----------------------------------------------------------------------
  /// @brief   Constructs a Action object without an amount. The amount
  ///          gets initialized with 0.
  ///
  /// @param _action action to encapsulate \sa{ ActionType }
  // ----------------------------------------------------------------------
  explicit Action(ActionType::Enum _action) : amount(bb(0)), action(_action) {}

  // ----------------------------------------------------------------------
  /// @brief   Construct a full Action object.
  ///
  /// @param _action action to encapsulate
  /// @param _amount monetary cost of action
  // ----------------------------------------------------------------------
  Action(ActionType::Enum _action, bb _amount)
      : amount(_amount), action(_action) {}

  ~Action() {}

  bool operator==(const Action &oha) const {
    return (action == oha.action && amount == oha.amount);
  }

  bool operator!=(const Action &oha) const { return !(*this == oha); }

  string str() { return ActionType::ToStrShort[action]; }

  string str_w_amt() {
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
};

#endif
