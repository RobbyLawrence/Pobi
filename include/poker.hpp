#include <vector>
#include <iostream>

struct Card {
    char suit;
    size_t val;
    Card(char suitn, size_t valn) {
        if (suitn != 'H' && suitn != 'C' && suitn != 'S' && suitn != 'D') {
            std::cerr << suitn << " is not a valid suit.\n";
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
            default:
                std::cerr << "Unknown suit type.";
        }
        std::cout << "Value: " << val << '\n';
    }
};
