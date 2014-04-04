/*
 * File:   status_type.hpp
 * Author: batman
 *
 * Created on August 8, 2013, 1:38 AM
 */

#ifndef STATUS_TYPE_H
#define STATUS_TYPE_H

namespace Poker {
namespace StatusType {

enum Enum {
  Active,
  Inactive,
  Allin
};

static const char *ToStr[] = { "Active", "Inactive", "Allin" };

static const char *ToStrShort[] = { "A", "I", "AI" };
};
}

#endif /* STATUS_TYPE_H */

