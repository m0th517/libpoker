#ifndef CARD_H
#define CARD_H

#include <string>
#include <stdexcept>

#include "face_type.hpp"
#include "suit_type.hpp"

namespace poker {

using std::string;

// ----------------------------------------------------------------------
/// @brief   Encapsulates a card in RAYW's format.
// ----------------------------------------------------------------------
class Card {
public:
  // ----------------------------------------------------------------------
  /// @brief    Constructs a card object from an integer
  ///           value between 1 and 52.
  ///
  /// @param card number to create card from
  // ----------------------------------------------------------------------
  explicit Card(int card) : _card(card) {
    if (card < 1 || card > 52)
      throw std::out_of_range("Cardvalue is out of bounds. ( 1 - 52 )");
  }

  // ----------------------------------------------------------------------
  /// @brief  Creates a Card object from a card string.
  ///
  ///         string format: 'Fs' where
  ///           - F = Facevalue (2,3,4,..,K,A)
  ///           - s = Suit (s,d,c,h)
  ///
  /// @param card a string representation of card
  // ----------------------------------------------------------------------
  explicit Card(string card) {
    int value = FaceType::find_index(card[0]);
    int suit = SuitType::find_index(card[1]);

    if (value == -1 || suit == -1)
      throw std::logic_error(
          "Suit or Facevalue of the Card could not be determined.");

    _card = 4 * value + suit + 1;
  }

  // ----------------------------------------------------------------------
  /// @brief   returns the cardvalue itself
  ///
  /// @return int between 1 - 52
  // ----------------------------------------------------------------------
  int card() const { return _card; }

  // ----------------------------------------------------------------------
  /// @brief   calculates the face value of the card. \sa{ FaceType }.
  ///
  /// @return the facevalue of the card as enum
  // ----------------------------------------------------------------------
  FaceType::Enum value() const {
    return static_cast<FaceType::Enum>((int)((_card - suit() - 1) * 0.25));
  }

  // ----------------------------------------------------------------------
  /// @brief   calculates the suit of the card. \sa{ SuitType }.
  ///
  /// @return the suit of the card as enum
  // ----------------------------------------------------------------------
  SuitType::Enum suit() const {
    return static_cast<SuitType::Enum>((int)(_card - 1) % 4);
  }

  // ----------------------------------------------------------------------
  /// @brief generates string represenation of card.  
  ///
  /// @return cardstring. Example: As, Kh, ... 
  // ----------------------------------------------------------------------
  string str() const {
    return string(FaceType::ToStr[value()]) + SuitType::ToStr[suit()];
  }

  bool operator==(const Card &oc) const { return (_card == oc.card()); }
  bool operator!=(const Card &oc) const { return !(*this == oc); }
  bool operator<(const Card &oc) const { return (_card < oc.card()); }
  bool operator>(const Card &oc) const { return (_card > oc.card()); }
  bool operator<=(const Card &oc) const { return (*this < oc || *this == oc); }
  bool operator>=(const Card &oc) const { return (*this > oc || *this == oc); }

private:
  int _card;
};
}

#endif
