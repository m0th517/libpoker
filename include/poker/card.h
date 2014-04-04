/*
 * File:   card.h
 * Author: batman
 *
 * Created on July 29, 2013, 5:14 PM
 */

#ifndef CARD_H
#define CARD_H

#include <string>
#include <sstream>
#include <stdexcept>

#include "face_type.h"
#include "suit_type.h"

namespace Poker {

using std::string;
using std::stringstream;

/**
 * Represents a card between 1-52 in
 * rayw's format.
 **/
class Card {
private:
  int card;

public:

  Card():card(0) {}

  Card(int _card) : card(_card) {
    if (card < 1 || card > 52)
      throw std::out_of_range("Cardvalue is out of bounds. ( 1 - 52 )");
  }

  /**
  * @param card     string format: Fs
  *                 F = Facevalue (2,3,4,..,K,A)
  *                 s = suit (s,d,c,h)
  */
  Card(string _card) {
    int value = FaceType::find_index(_card[0]);
    int suit = SuitType::find_index(_card[1]);

    if (value == -1 || suit == -1)
      throw std::logic_error(
          "Suit or Facevalue of the Card could not be determined.");

    this->card = 4 * value + suit + 1;
  }

  inline int get_card() const { return card; }

  inline FaceType::Enum get_value() const {
    return static_cast<FaceType::Enum>((int)((card - get_suit() - 1) * 0.25));
  }

  inline SuitType::Enum get_suit() const {
    return static_cast<SuitType::Enum>((SuitType::Enum)(int)(card - 1) % 4);
  }

  bool operator==(const Card &oc) const { return (card == oc.get_card()); }

  bool operator!=(const Card &oc) const { return !(*this == oc); }

  bool operator<(const Card &oc) const { return (card < oc.get_card()); }

  bool operator>(const Card &oc) const { return (card > oc.get_card()); }

  bool operator<=(const Card &oc) const { return (*this < oc || *this == oc); }

  bool operator>=(const Card &oc) const { return (*this > oc || *this == oc); }

  inline string to_str() const {
    stringstream str;
    str << FaceType::ToStr[get_value()] << SuitType::ToStr[get_suit()];
    return str.str();
  }
};
}

#endif /* CARD_H */

