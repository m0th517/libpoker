/*
 * File:   face_type.h
 * Author: batman
 *
 * Created on July 29, 2013, 7:48 PM
 */

#ifndef FACE_TYPE_H
#define FACE_TYPE_H

namespace Poker {
namespace FaceType {

enum Enum {
  Deuce,
  Trey,
  Four,
  Five,
  Six,
  Seven,
  Eight,
  Nine,
  Ten,
  Jack,
  Queen,
  King,
  Ace
};

static const char *ToStr[] = { "2", "3", "4", "5", "6", "7", "8", "9", "T", "J",
                               "Q", "K", "A" };

int find_index(const char c);
}
}

#endif /* FACE_TYPE_H */

