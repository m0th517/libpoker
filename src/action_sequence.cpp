#include <sstream>
#include "action_sequence.h"
#include "action_type.h"

namespace Poker {

ActionSequence::ActionSequence() : sequence(vector<Line>(4)) {}

ActionSequence::ActionSequence(const ActionSequence &p) {
  sequence = p.sequence;
}

ActionSequence::~ActionSequence() {}

void ActionSequence::append(Action action, PhaseType::Enum phase) {
  sequence[phase].push_back(action);
}

ActionSequence ActionSequence::assume(Action action,
                                      PhaseType::Enum phase) const {
  ActionSequence new_seq = ActionSequence(*this);
  new_seq.append(action, phase);
  return new_seq;
}

string ActionSequence::to_str() const {
  std::stringstream ss;
  bool has_element;
  for (unsigned i = 0; i < 4; i++) {
    has_element = false;
    for (unsigned a = 0; a < sequence[i].size(); a++) {
      ss << ActionType::ToStrShort[sequence[i][a].action];
      has_element = true;
    }
    if (i != 3 && has_element)
      ss << "/";
  }
  return ss.str();
}
}
