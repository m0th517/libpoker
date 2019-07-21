# Libpoker
Libpoker is a small library for Poker related Datastructures. It currently supports the following classes:

* **Card** - Represents one of 52 Cards in a deck.
* **Hand** - A tuple of cards representing a players hidden cards
* **Action** - Actions Fold/Call/Check/Raise with amount
* **ActionSequence** - A collection of Actions 

## Requirements
* decimal_for_cpp ( included as git submodule )
* UnitTest++ for tests (expects headers and lib to be in /usr/{lib,include})

## Build
```bash
$ git clone --recursive https://github.com/pandaant/libpoker
$ cd libpoker
$ make all

# build documentation (requires doxygen)
$ make doc

# build and run tests
$ cd test 
$ make all run
```

## Usage

### Cards

```c++
#include <poker/card.hpp>

using namespace poker;

// create a card from String
Card ace_of_clubs("Ac");

// get the face value
ace_of_clubs.value(); // FaceType::Ace

// get the suit
ace_of_clubs.suit(); // SuitType::Club

// get internal representation
ace_of_clubs.card(); // 52

// card comparisons
Card a("3c");
Card b("Jc");
Card c("3c");

a != b;
a == c;
c != b;
a < b;
a <= c;

```
### Hands

```c++
#include <poker/card.hpp>
#include <poker/hand.hpp>

using namespace poker;

// create a hand from String
Hand hand("AcJs");

// create a hand from 2 Cards
Card ace_of_clubs("Ac");
Card jack_of_spades("Js");

Hand hand(ace_of_clubs, jack_of_spades);

// get the highcard
hand.highcard(); // Ac

// get the lowcard
hand.lowcard(); // Js

// get short representation (suited/unsuited)
Hand hand("AsJs"); // AJs
Hand hand("AcJs"); // AJ

// Hand comparisons
Hand a("Kc7d");
Hand b("Ac2d");
Hand c("Ac6c");

a != b;
a == c;
c != b;
a < b;
a <= c;

```
### Actions and Sequences

```c++
#include <poker/action_sequence.hpp>

using namespace poker;
using namespace PhaseType;
using namespace ActionType;

// create an empty sequence
ActionSequence seq;

// string representation (each phase is delimited by /)
seq.str(); // "///"


// add actions
// Call Preflop for 10 bigblinds in Bettinground 0
seq.append(Action(Call, bb(10)), Preflop, 0);
// Check Flop 
seq.append(Action(Check, bb(10)), Flop, 0);
// Call Turn for 10 bigblinds
seq.append(Action(Call, bb(10)), Turn, 0);
// Raise River for 20 bigblinds
seq.append(Action(Raise, bb(20)), River, 0);

seq.str(); // "C/X/C/R"


// add action and create a new sequence instead of appending
ActionSequence assume_seq = seq.assume(Action(Raise, bb(20)), River, 0);
seq.str();	// "C/X/C/R"
assume_seq.str();	// "C/X/C/RR"


// subtract sequences from each other
ActionSequence subseq;
subseq.append(Action(Call, bb(10)), Preflop, 0);
subseq.append(Action(Check, bb(10)), Flop, 0);

subseq.str(); // "C/X//"
seq.subtract(subseq).str(); // "//C/R"

```
