#ifndef SUIT_TYPE_H
#define SUIT_TYPE_H

namespace poker {

// ----------------------------------------------------------------------
/// @brief   Internal representation of the different suits.
// ----------------------------------------------------------------------
namespace SuitType {

enum Enum { Club, Diamond, Heart, Spade };

static const char *ToStr[] = {"c", "d", "h", "s"};

// ----------------------------------------------------------------------
/// @brief   function searches for the index of a char in ToStr
///
/// @param c char to look up index for possible values are in ToStr.
///
/// @return the index of char when found, -1 otherwise.
// ----------------------------------------------------------------------
int find_index(const char c);
}
}

#endif
