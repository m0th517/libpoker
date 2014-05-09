#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>
#include "pokerdefs.hpp"
#include "phase_type.hpp"

namespace poker {

using std::vector;
using std::string;

// ----------------------------------------------------------------------
/// @brief   Represents a Pokerplayer with basic attributes
// ----------------------------------------------------------------------
class Player {
public:
  /// the amount of chips the player has in bb
  bb bankroll;

  /// an array to store investments for the game 4 phases separately.
  vector<bb> invested;

  /// stores if the player is active/inactive or allin
  StatusType::Enum status;

  // ----------------------------------------------------------------------
  /// @brief   Constructs a Player without specifying previous investments.
  ///          investments get initialized with zero.
  ///
  /// @param _bankroll the players amount of money
  /// @param _status   current status of player \sa{ StatusType }
  // ----------------------------------------------------------------------
  Player(bb _bankroll, StatusType::Enum _status);

  // ----------------------------------------------------------------------
  /// @brief   Constructs a Player with all basic attributes.
  ///
  /// @param _bankroll  look at other constructor.
  /// @param _invested  a vector<bb> of size 4. gets resized properly.
  /// @param _status    look at other constructor.
  // ----------------------------------------------------------------------
  Player(bb _bankroll, bb _invested, StatusType::Enum _status);

  Player(const Player &p);

  Player& operator=(const Player &p);

  ~Player();

  bool invest(const bb &amount, const PhaseType::Enum &phase);
  bb total_investment() const;
};
}

#endif
