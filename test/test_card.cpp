#include <card.hpp>
#include <UnitTest++.h>

SUITE(CardTests) {

  using namespace poker;

  TEST(CardFromNumber) {
    int cardindex = 5; // 3c
    Card c = Card(cardindex);

    CHECK_EQUAL(cardindex, c.card());
  }

  TEST(TestSuits) {
    Card c = Card(5); // 3c
    CHECK_EQUAL(SuitType::Club, c.suit());

    c = Card(19); // 6h
    CHECK_EQUAL(SuitType::Heart, c.suit());

    c = Card(2); // 2d
    CHECK_EQUAL(SuitType::Diamond, c.suit());

    c = Card(24); // 7s
    CHECK_EQUAL(SuitType::Spade, c.suit());
  }

  TEST(TestFaceValues) {
    Card c = Card(5); // 3c
    CHECK_EQUAL(FaceType::Trey, c.value());

    c = Card(19); // 6h
    CHECK_EQUAL(FaceType::Six, c.value());

    c = Card(2); // 2d
    CHECK_EQUAL(FaceType::Deuce, c.value());

    c = Card(24); // 7s
    CHECK_EQUAL(FaceType::Seven, c.value());

    c = Card(52); // As
    CHECK_EQUAL(FaceType::Ace, c.value());

    c = Card(37); // Jc
    CHECK_EQUAL(FaceType::Jack, c.value());
  }

  TEST(CardToString) {
    Card c = Card(5); // 3c
    CHECK_EQUAL("3c", c.str());

    c = Card(37); // Jc
    CHECK_EQUAL("Jc", c.str());
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
    CHECK_EQUAL(0, Card::lookup_suit('c'));
    CHECK_EQUAL(3, Card::lookup_suit('s'));
  }

  TEST(FindFaceIndex) {
    CHECK_EQUAL(0, Card::lookup_face_value('2'));
    CHECK_EQUAL(12, Card::lookup_face_value('A'));
  }

  TEST(CardFromString) {
    Card a = Card("As"); // 52
    CHECK_EQUAL(52, a.card());

    a = Card("3c"); // 5
    CHECK_EQUAL(5, a.card());

    a = Card("Jc"); // 37
    CHECK_EQUAL(37, a.card());
  }
}
