#include <hand.h>
#include <stdexcept>
#include <UnitTest++.h>

SUITE(HandTests) {
  using namespace Poker;

  TEST(HandFromCards) {
    Card a = Card("As");
    Card b = Card("4d");

    Hand h = Hand(a, b);
    CHECK_EQUAL(52, h.get_highcard().get_card());
    CHECK_EQUAL(10, h.get_lowcard().get_card());

    h = Hand(b, a);
    CHECK_EQUAL(52, h.get_highcard().get_card());
    CHECK_EQUAL(10, h.get_lowcard().get_card());
  }

  TEST(HandFromString) {
    Hand h = Hand("AsJc");
    CHECK_EQUAL(52, h.get_highcard().get_card());
    CHECK_EQUAL(37, h.get_lowcard().get_card());
  }

  TEST(HandEquality) {
    Hand a = Hand("Kc7d");
    Hand b = Hand("Kc7d");
    Hand c = Hand("Qc2d");

    CHECK(a == b);
    CHECK(a != c);
  }

  TEST(HandToBitset) {
    Hand a = Hand("As2c");
    CHECK_EQUAL(a.to_bitset().to_string(),
                "1000000000000000000000000000000000000000000000000001");
  }

  TEST(HandToVector) {
    Hand a = Hand("As2c");
    std::vector<Card> vec({ Card("As"), Card("2c") });
    CHECK(a.to_vector() == vec);
  }

  TEST(HandToRawVector) {
    Hand a = Hand("As2c");
    std::vector<int> vec({ Card("As").get_card(), Card("2c").get_card() });
    CHECK(a.to_raw_vector() == vec);
  }

  TEST(HandTestLess) {
    Hand a = Hand("Kc7d");
    Hand b = Hand("Ac2d");
    Hand c = Hand("AcAd");

    CHECK(a < b);
    CHECK(b < c);
  }

  TEST(HandLessEqual) {
    Hand a = Hand("Kc7d");
    Hand b = Hand("Ac2d");
    Hand d = Hand("Kc7d");

    CHECK(a <= b);
    CHECK(a <= d);
  }

  TEST(TestCardBigger) {
    Hand a = Hand("Kc7d");
    Hand b = Hand("Ac2d");
    Hand c = Hand("AcAd");

    CHECK(b > a);
    CHECK(c > b);
  }

  TEST(TestCardBiggerEqual) {
    Hand a = Hand("Kc7d");
    Hand b = Hand("Ac2d");
    Hand c = Hand("AcAd");

    CHECK(b >= a);
    CHECK(c >= b);
  }

  TEST(To169String) {
    Hand a = Hand("Kc7d");
    Hand b = Hand("Ac2d");
    Hand c = Hand("Ac6c");

    CHECK(a.to_169str() == "K7");
    CHECK(b.to_169str() == "A2");
    CHECK(c.to_169str() == "A6s");
  }

  TEST(HandToString) {
    Hand a = Hand("Kc7d");
    Hand b = Hand("Ac2d");

    CHECK(a.to_str() == "Kc7d");
    CHECK(b.to_str() == "Ac2d");
  }
}
