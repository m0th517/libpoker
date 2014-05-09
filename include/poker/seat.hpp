/*
 * File:   seat.hpp
 * Author: batman
 *
 * Created on August 8, 2013, 2:05 AM
 */

#ifndef SEAT_H
#define SEAT_H

#include "status_type.hpp"
#include "seat_type.hpp"
#include "player.hpp"

namespace poker {

class Seat {
public:
  Player player;
  SeatType::Enum type;
  StatusType::Enum status;

  Seat(Player _player, SeatType::Enum _type, StatusType::Enum _status)
      : player(_player), type(_type), status(_status) {}
  Seat(const Seat &s);
  virtual Seat& operator=(const Seat &s);
  virtual ~Seat() {}

  bool is_active() const;
  bool is_inactive() const;
  bool is_allin() const;

  void set_inactive();
  void set_active();
  void set_allin();
};
}
#endif /* SEAT_H */

