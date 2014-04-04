/*
 * File:   seat_type.h
 * Author: batman
 *
 * Created on August 8, 2013, 1:39 AM
 */

#ifndef SEAT_TYPE_H
#define SEAT_TYPE_H

namespace Poker {
namespace SeatType {

enum Enum {
  Normal,
  Button,
  Smallblind,
  Bigblind,
};

static const char *ToStr[] = { "Normal", "Button", "Smallblind", "Bigblind" };

static const char *ToStrShort[] = { "N", "B", "S", "B" };
}
}

#endif /* SEAT_TYPE_H */

