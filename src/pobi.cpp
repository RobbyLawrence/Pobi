#include <iostream>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include "poker.hpp"

double choose(size_t n, size_t k) {
    if (k > n) {
        std::cerr << "Choose function: n must be greater than k.\n";
        return 0;
    }
    if (k * 2 > n) k = n-k; // symmetry
    if (k == 0) return 1;
    int result = n;
    for(int i = 2; i <= k; ++i ) {
        result *= (n-i+1);
        result /= i;
    }
    return (double)result;
}
void analyze_dealt_cards(std::vector<Card> cards, size_t num_players) {
    std::sort(cards.begin(),cards.end(),[](Card a, Card b) {
        return a.val > b.val;
    });
    Card high = cards[0];
    Card low = cards[1];
    std::vector<double> probabilities(9); // pair, two pair, three of a kind,
    printf("Current High Card: %zu of %c\n",cards[0].val,cards[0].suit);
    std::cout <<"-----Probabilities-----\n";
    // probability of pair
    if (low.val == high.val) {
        probabilities[0] = 1.
    }
    else { // cards are different, so only one case
        probabilities[0] = 6 * choose(44,4)/choose(50,5);
    }
    std::cout << "Pair: " << probabilities[0] * 100 << "%\n";
    // probability for two pair
    if (low.val == high.val) {
        probabilities[1] = 1 - (1287. * 4)/2118760;
    }
}

int main() {
    int bank = 0; // this will serve as a counter to tell the user how much money they've won or lost
    /*
    a poker game has several phases that repeat themselves each hand.
    First, we are dealt two cards. We can analyze how much we like our hand, and depending on what others bet,
    check, fold, or raise.
    */
    size_t num_players;
    std::cout << "Hey there! I'm Pobi. Let's win some poker!\n";
    std::cout << "Enter number of players: ";
    std::cin >> num_players;
    std::cout << "Okay great! For this game, we'll count face cards as their numeric value. That means that a K is 13, Q is 12, etc.\n";
    std::cout << R"(Go ahead and enter your first two cards in the format "Suit Value.")" << std::endl;
    char suit;
    size_t val;
    std::vector<Card> dealt_cards;
    Card first = Card('H',(size_t)1);
    Card second = Card('H',(size_t)1);
    while (true) {
        std::cout << "First card: ";
        std::cin >> suit >> val;
        first = Card(suit,val);
        if (first.valid) {
            dealt_cards.push_back(first);
            break;
        }
    }
    while (true) {
        std::cout << "Second card: ";
        std::cin >> suit >> val;
        second = Card(suit,val);
        if (second.valid) {
            dealt_cards.push_back(second);
            break;
        }
    }
    std::string dummy;
    std::cout << "\nLooks like your cards are: \n";
    dealt_cards[0].output();
    dealt_cards[1].output();
    while (dummy != "y" && dummy != "Y") { // allow for card re-entry if the user makes a mistake
        std::cout << "Does that look right? [y/n] ";
        std::cin >> dummy;
        if (dummy == "n" || dummy == "N") {
            dealt_cards.clear();
            std::cout << "Please re-enter your cards.";
            while (true) {
                std::cout << "\nFirst card: ";
                std::cin >> suit >> val;
                first = Card(suit,val);
                if (first.valid) {
                    dealt_cards[0] = first;
                    break;
                }
            }
            while (true) {
                std::cout << "\nSecond card: ";
                std::cin >> suit >> val;
                second = Card(suit,val);
                if (second.valid) {
                    dealt_cards[1] = second;
                    break;
                }
            }
        }
    }
    std::cout << '\n';
    analyze_dealt_cards(dealt_cards, num_players);
    return 0;
}
