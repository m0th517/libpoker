#ifndef ACTION_SEQUENCE_H
#define ACTION_SEQUENCE_H

#include <string>
#include <vector>
#include "action.hpp"
#include "phase_type.hpp"

namespace poker {

using std::vector;
using std::string;

// ----------------------------------------------------------------------
/// @brief Stores an sequence of actions ( action and amount ) to keep 
/// track of everything a player did.
// ----------------------------------------------------------------------
class ActionSequence {
  typedef vector<Action> Line;

public:
  /// stores 4 lines. one for every phase
  vector<Line> sequence;

  ActionSequence();
  ~ActionSequence();

  ActionSequence(const ActionSequence &p);

  // ----------------------------------------------------------------------
  /// @brief   appends an action to the sequence
  ///
  /// @param action the action to append 
  /// @param phase phase in which action to append
  /// @param betting_round the action took place 
  // ----------------------------------------------------------------------
  void append(const Action &action, const PhaseType::Enum &phase,
              const int &betting_round);

  // ----------------------------------------------------------------------
  /// @brief  works similar to append, buts creates a new sequence instead 
  ///         of appending to class directly.
  ///
  /// @param action to assume
  /// @param phase where action took place
  /// @param betting_round where action took place
  ///
  /// @return a copy of the current sequence + the passed action.
  // ----------------------------------------------------------------------
  ActionSequence assume(const Action &action, const PhaseType::Enum &phase,
                        const int &betting_round) const;

  // ----------------------------------------------------------------------
  /// @brief   returns a sequence where every action that is contained 
  /// in both self and subsequence object are removed.
  ///
  /// @param sequence to take as subtractor
  ///
  /// @return a sequence with all elements from other list removed.
  // ----------------------------------------------------------------------
  ActionSequence subtract(const ActionSequence &sequence) const;

  // ----------------------------------------------------------------------
  /// @brief   
  ///
  /// @param phase
  ///
  /// @return true if sequence has at least one action 
  // ----------------------------------------------------------------------
  bool has_actions(const PhaseType::Enum &phase) const {
    return sequence[phase].size() > 0;
  }

  Line phase_actions(PhaseType::Enum phase) { return sequence[phase]; }

  string str() const;
};
};

#endif
