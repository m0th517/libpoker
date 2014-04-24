#include <iostream>
#include <UnitTest++.h>
#include <action_sequence.h>

SUITE(ActionSequenceTests) {
  using namespace Poker;
  using namespace PhaseType;
  using namespace ActionType;

  TEST(TestAppend) {
    ActionSequence seq = ActionSequence();
    CHECK_EQUAL("///", seq.to_str());

    seq.append(Action(Call, amt_bb(10)), Preflop);
    CHECK_EQUAL("C///", seq.to_str());

    seq.append(Action(Check, amt_bb(10)), Flop);
    seq.append(Action(Call, amt_bb(10)), Turn);
    seq.append(Action(Raise, amt_bb(20)), River);

    CHECK_EQUAL("C/X/C/R", seq.to_str());
  }

  TEST(TestAssume) {
    ActionSequence seq = ActionSequence();
    seq.append(Action(Call, amt_bb(10)), Preflop);
    seq.append(Action(Check, amt_bb(10)), Flop);
    seq.append(Action(Call, amt_bb(10)), Turn);
    seq.append(Action(Raise, amt_bb(20)), River);

    ActionSequence assume_seq = seq.assume(Action(Raise, amt_bb(20)), River);
    CHECK_EQUAL("C/X/C/RR", assume_seq.to_str());
  }

  TEST(TestSubtract) {
    // C/X/C/R
    ActionSequence seq = ActionSequence();
    seq.append(Action(Call, amt_bb(10)), Preflop);
    seq.append(Action(Check, amt_bb(10)), Flop);
    seq.append(Action(Call, amt_bb(10)), Turn);
    seq.append(Action(Raise, amt_bb(20)), River);

    CHECK_EQUAL("C/X/C/R", seq.to_str());

    // C/X
    ActionSequence subseq = ActionSequence();
    subseq.append(Action(Call, amt_bb(10)), Preflop);
    subseq.append(Action(Check, amt_bb(10)), Flop);

    CHECK_EQUAL("C/X//", subseq.to_str());

    CHECK_EQUAL("//C/R", seq.subtract(subseq).to_str());
  }

  TEST(TestSubtractNonExistingInSeq) {
    // C/X/C/R
    ActionSequence seq = ActionSequence();
    seq.append(Action(Call, amt_bb(10)), Preflop);
    seq.append(Action(Check, amt_bb(10)), Flop);
    seq.append(Action(Call, amt_bb(10)), Turn);
    seq.append(Action(Raise, amt_bb(20)), River);

    CHECK_EQUAL("C/X/C/R", seq.to_str());

    // C/X
    ActionSequence subseq = ActionSequence();
    subseq.append(Action(Raise, amt_bb(10)), Preflop);
    subseq.append(Action(Call, amt_bb(10)), Flop);
    subseq.append(Action(Raise, amt_bb(10),3), Turn);

    CHECK_EQUAL("R/C/R/", subseq.to_str());
    CHECK_EQUAL("C/X/C/R", seq.subtract(subseq).to_str());
  }
}
