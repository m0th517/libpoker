#include <UnitTest++.h>
#include <seat.h>
#include <status_type.h>
#include <seat_type.h>

SUITE(SeatTests) {
  using namespace Poker;

  TEST(TestSetIs) {
    Seat s(Player("mark", amt_bb(100)), SeatType::Normal, StatusType::Active);
    CHECK_EQUAL(false, s.is_allin());
    s.set_allin();
    CHECK_EQUAL(true, s.is_allin());

    CHECK_EQUAL(false, s.is_active());
    s.set_active();
    CHECK_EQUAL(true, s.is_active());

    CHECK_EQUAL(false, s.is_inactive());
    s.set_inactive();
    CHECK_EQUAL(true, s.is_inactive());
  }
}
