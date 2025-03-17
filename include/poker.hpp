#include <vector>
#include <iostream>

std::vector<char> suits = {'H','S','C','D'};
std::vector<size_t> vals = {1,2,3,4,5,6,7,8,9,10,11,12,13};

struct Card {
    char suit;
    size_t val;
    bool valid;
    Card(char suitn, size_t valn) {
        valid = true;
        if (suitn != 'H' && suitn != 'C' && suitn != 'S' && suitn != 'D') {
            std::cerr << suitn << " is not a valid suit.\n";
            valid = false;
        }
        else if (valn < 1 || valn > 13) {
            std::cerr << valn << " is not a valid card value.\n";
            valid = false;
        }
        else {
            suit = suitn;
            val = valn;
        }
    }
    void output() {
        std::cout << "Suit: ";
        switch (suit) {
            case 'H':
                std::cout << "Hearts\n";
                break;
            case 'D':
                std::cout << "Diamonds\n";
                break;
            case 'C':
                std::cout << "Clubs\n";
                break;
            case 'S':
                std::cout << "Spades\n";
                break;
            default:
                std::cerr << "Unknown suit type.";
                break;
        }
        std::cout << "Value: " << val << '\n';
    }
};

struct Deck { // instantiating a new Deck is like placing all cards back in a deck
    std::vector<Card> cards;
    Deck() {
        for (char suit : suits) {
            for (size_t val : vals) {
                cards.push_back(Card(suit,val));
            }
        }
    }
};
