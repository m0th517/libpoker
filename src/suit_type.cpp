#include "suit_type.hpp"

int Poker::SuitType::find_index(const char c) {
  for (int i = 0; i < 4; ++i)
    if (c == *SuitType::ToStr[i])
      return i;
  return -1;
}
