/*
 * File:   phase_type.h
 * Author: batman
 *
 * Created on July 29, 2013, 11:04 PM
 */

#ifndef PHASE_TYPE_H
#define PHASE_TYPE_H

namespace Poker {
namespace PhaseType {

enum Enum {
  Preflop,
  Flop,
  Turn,
  River,
  Showdown
};

static const char *ToStr[] = { "Preflop", "Flop", "Turn", "River", "Showdown" };

static const char *ToStrShort[] = { "p", "f", "t", "r", "s" };
}
}

#endif /* PHASE_TYPE_H */

