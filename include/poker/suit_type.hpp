/*
 * File:   suit_type.hpp
 * Author: batman
 *
 * Created on July 29, 2013, 7:51 PM
 */

#ifndef SUIT_TYPE_H
#define SUIT_TYPE_H

namespace Poker {
namespace SuitType {

enum Enum {
  Club,
  Diamond,
  Heart,
  Spade
};

static const char *ToStrLong[] = { "Clubs", "Diamonds", "Hearts", "Spades" };

static const char *ToStr[] = { "c", "d", "h", "s" };

int find_index(const char c);
}
}

#endif /* SUIT_TYPE_H */

