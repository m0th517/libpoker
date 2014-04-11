#include <UnitTest++.h>
#include <player.hpp>

SUITE(PlayerTests) {
  using namespace Poker;
  using namespace PhaseType;

  TEST(TestInvestment) {
    Player p("mark", amt_bb(100));
    CHECK_EQUAL(true, p.make_investment(amt_bb(10), Preflop));
    CHECK_EQUAL(true, p.make_investment(amt_bb(90), Preflop));
    // nope, no more money left
    CHECK_EQUAL(false, p.make_investment(amt_bb(1), Preflop));
  }

  TEST(TestInvestmentToMuch) {
    Player p("mark", amt_bb(100));
    CHECK_EQUAL(false, p.make_investment(amt_bb(1000), Preflop));
  }

  TEST(TestTotalInvestment) {
    Player p("mark", amt_bb(100));

    p.make_investment(amt_bb(10), Preflop);
    p.make_investment(amt_bb(10), Flop);
    p.make_investment(amt_bb(10), River);

    CHECK_EQUAL(amt_bb(30), p.total_investment());
  }
}
