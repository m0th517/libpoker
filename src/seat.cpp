#include "seat.hpp"

namespace poker {
Seat::Seat(const Seat &s) {
  status = s.status;
  type = s.type;
  player = Player(s.player);
}

Seat& Seat::operator=(const Seat &s) {
  status = s.status;
  type = s.type;
  player = Player(s.player);
  return *this;
}

bool Seat::is_active() const { return status == StatusType::Active; }

bool Seat::is_inactive() const { return status == StatusType::Inactive; }

bool Seat::is_allin() const { return status == StatusType::Allin; }

void Seat::set_inactive() { status = StatusType::Inactive; }

void Seat::set_active() { status = StatusType::Active; }

void Seat::set_allin() { status = StatusType::Allin; }
}
