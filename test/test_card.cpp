#include <card.h>
#include <UnitTest++.h>

SUITE(CardTests) {

  using namespace Poker;

  TEST(CardFromNumber) {
    int cardindex = 5; // 3c
    Card c = Card(cardindex);

    CHECK_EQUAL(cardindex, c.get_card());
  }

  TEST(TestSuits) {
    Card c = Card(5); // 3c
    CHECK_EQUAL(SuitType::Club, c.get_suit());

    c = Card(19); // 6h
    CHECK_EQUAL(SuitType::Heart, c.get_suit());

    c = Card(2); // 2d
    CHECK_EQUAL(SuitType::Diamond, c.get_suit());

    c = Card(24); // 7s
    CHECK_EQUAL(SuitType::Spade, c.get_suit());
  }

  TEST(TestFaceValues) {
    Card c = Card(5); // 3c
    CHECK_EQUAL(FaceType::Trey, c.get_value());

    c = Card(19); // 6h
    CHECK_EQUAL(FaceType::Six, c.get_value());

    c = Card(2); // 2d
    CHECK_EQUAL(FaceType::Deuce, c.get_value());

    c = Card(24); // 7s
    CHECK_EQUAL(FaceType::Seven, c.get_value());

    c = Card(52); // As
    CHECK_EQUAL(FaceType::Ace, c.get_value());

    c = Card(37); // Jc
    CHECK_EQUAL(FaceType::Jack, c.get_value());
  }

  TEST(CardToString) {
    Card c = Card(5); // 3c
    CHECK_EQUAL("3c", c.to_str());

    c = Card(37); // Jc
    CHECK_EQUAL("Jc", c.to_str());
  }

  TEST(CardEquality) {
    Card a = Card(5);  // 3c
    Card b = Card(37); // Jc
    Card c = Card(5);  // 3c

    CHECK(a != b);
    CHECK(a == c);
    CHECK(c != b);
  }

  TEST(TestCardLess) {
    Card a = Card(5);  // 3c
    Card b = Card(37); // Jc
    Card c = Card(52); // As

    CHECK(a < b);
    CHECK(b < c);
  }

  TEST(TestCardLessEqual) {
    Card a = Card(5);  // 3c
    Card b = Card(37); // Jc
    Card c = Card(5);  // 3c

    CHECK(a <= b);
    CHECK(a <= c);
  }

  TEST(TestCardBigger) {
    Card a = Card(5);  // 3c
    Card b = Card(37); // Jc

    CHECK(b > a);
  }

  TEST(TestCardBiggerEqual) {
    Card a = Card(5);  // 3c
    Card b = Card(37); // Jc
    Card c = Card(5);  // 3c

    CHECK(b >= a);
    CHECK(a >= c);
  }

  TEST(FindSuitIndex) {
    CHECK_EQUAL(0, SuitType::find_index('c'));
    CHECK_EQUAL(3, SuitType::find_index('s'));
  }

  TEST(FindFaceIndex) {
    CHECK_EQUAL(0, FaceType::find_index('2'));
    CHECK_EQUAL(12, FaceType::find_index('A'));
  }

  TEST(CardFromString) {
    Card a = Card("As"); // 52
    CHECK_EQUAL(52, a.get_card());

    a = Card("3c"); // 5
    CHECK_EQUAL(5, a.get_card());

    a = Card("Jc"); // 37
    CHECK_EQUAL(37, a.get_card());
  }
}
