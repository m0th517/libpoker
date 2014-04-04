/*
 * File:   hand.hpp
 * Author: batman
 *
 * Created on July 29, 2013, 11:18 PM
 */

#ifndef HAND_H
#define HAND_H

#include <bitset>
#include <vector>
#include "card.hpp"

namespace Poker {

using std::vector;

class Hand {
private:
  Card highcard, lowcard;

  inline void set_cards(Card c1, Card c2) {
    highcard = (c1 > c2) ? c1 : c2;
    lowcard = (c1 < c2) ? c1 : c2;
  }

public:
  typedef std::bitset<52> bitset_type;

  Hand(Card c1, Card c2) { set_cards(c1, c2); }

  Hand(int c1, int c2) { set_cards(Card(c1), Card(c2)); }

  Hand(string _hand) {
    Card card1 = Card(_hand.substr(0,2));
    Card card2 = Card(_hand.substr(2,2));
    set_cards(card1, card2);
  }

  inline Card get_highcard() const { return highcard; }

  inline Card get_lowcard() const { return lowcard; }

  // this function can be deleted? constructor does the same
  inline static Hand from_str(string _hand) {
    Card card1 = Card(_hand.substr(0,2));
    Card card2 = Card(_hand.substr(2,2));
    return Hand(card1, card2);
  }

  bool operator==(const Hand &oh) const {
    return (highcard == oh.get_highcard() && lowcard == oh.get_lowcard());
  }

  bool operator!=(const Hand &oh) const { return !(*this == oh); }

  bool operator<(const Hand &oh) const {
    return (to_bitset().to_ulong() < oh.to_bitset().to_ulong());
  }

  bool operator<=(const Hand &oh) const {
    return (to_bitset().to_ulong() <= oh.to_bitset().to_ulong());
  }

  bool operator>(const Hand &oh) const {
    return (to_bitset().to_ulong() > oh.to_bitset().to_ulong());
  }

  bool operator>=(const Hand &oh) const {
    return (to_bitset().to_ulong() >= oh.to_bitset().to_ulong());
  }

  bitset_type to_bitset() const {
    bitset_type set;
    set[highcard.get_card() - 1] = 1;
    set[lowcard.get_card() - 1] = 1;
    return set;
  }

  vector<Card> to_vector() const {
    Card init[] = {highcard, lowcard};
    return vector<Card>(init, init + sizeof(init) / sizeof(init[0]) );
  }

  vector<int> to_raw_vector() const {
    int init[] = { highcard.get_card(), lowcard.get_card() };
    return vector<int>(init, init + sizeof(init) / sizeof(init[0]) );
  }

  string to_169str() const {
    stringstream str;
    str << FaceType::ToStr[highcard.get_value()]
        << FaceType::ToStr[lowcard.get_value()]
        << ((SuitType::ToStr[highcard.get_suit()] ==
             SuitType::ToStr[lowcard.get_suit()])
                ? "s"
                : "");
    return str.str();
  }

  virtual string to_str() const {
    stringstream str;
    str << highcard.to_str() << lowcard.to_str();
    return str.str();
  }
};
}

#endif /* HAND_H */

