# Libpoker
Libpoker is a small library for Poker related Datastructures. It currently supports the following classes:

* **Card** - Represents one of 52 Cards in a deck.
* **Hand** - A tuple of cards representing a players hidden cards
* **Action** - Actions Fold/Call/Check/Raise with amount
* **ActionSequence** - A collection of Actions 

## Requirements
* decimal_for_cpp
* UnitTest++ for tests

## Build
```
$ git clone --recursive https://github.com/pandaant/libpoker
$ cd libpoker
$ make all
```

## Usage
