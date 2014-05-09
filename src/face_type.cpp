#include "face_type.hpp"

int poker::FaceType::find_index(const char c) {
  for (int i = 0; i < 13; ++i)
    if (c == *FaceType::ToStr[i])
      return i;
  return -1;
}
