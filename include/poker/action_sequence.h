/*
 * File:   action_sequence.h
 * Author: batman
 *
 * Created on August 8, 2013, 12:48 AM
 */

#ifndef ACTION_SEQUENCE_H
#define ACTION_SEQUENCE_H

#include <string>
#include <vector>
#include "action.h"
#include "phase_type.h"

namespace Poker {

using std::vector;
using std::string;

/**
 * Stores an sequence of actions ( action and amount )
 *  to keep track of everything a player did.
 **/
class ActionSequence {
  typedef vector<Action> Line;

public:
  vector<Line> sequence;

  ActionSequence();
  ActionSequence(const ActionSequence &p);
  ~ActionSequence();

  /**
   * append action to sequence
   * @param action to be appended
   * @param phase in which action took place
   */
  void append(Action action, PhaseType::Enum phase);

  /**
   * returns a copy of the current sequence + the passed action.
   * @param action to be assumed
   * @param phase in which action took place
   * @return copy of this + action
   */
  ActionSequence assume(Action action, PhaseType::Enum phase) const;

  /**
   * @param phase to check
   * @return true if sequence has at least one action
   */
  bool has_actions(PhaseType::Enum phase) { return sequence[phase].size() > 0; }

  Line phase_actions(PhaseType::Enum phase) { return sequence[phase]; }

  string to_str() const;
};
}

#endif /* ACTION_SEQUENCE_H */

