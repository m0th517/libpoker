/*
 * File:   action_type.h
 * Author: batman
 *
 * Created on July 29, 2013, 11:10 PM
 */

#ifndef ACTION_TYPE_H
#define ACTION_TYPE_H

namespace Poker {

/**
 * Stores all possible actions and
 * their stringrepresentations
 **/
namespace ActionType {

enum Enum {
  None,
  Fold,
  Check,
  Call,
  Raise,
  AllIn,
  Bet
};

static const char *ToStr[] = { "None", "Fold", "Check", "Call", "Raise",
                               "AllIn", "Bet" };

static const char *ToStrShort[] = { "N", "F", "X", "C", "R", "A", "B" };
}
}

#endif /* ACTION_TYPE_H */

