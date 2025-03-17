#include <iostream>
#include <algorithm>
#include <iomanip>
#include "poker.hpp"

void analyze_dealt_cards(std::vector<Card> cards) {
    std::sort(cards.begin(),cards.end(),[](Card a, Card b) {
        return a.val > b.val;
    });
    Card low = cards[0];
    Card high = cards[1];
    std::vector<double> probabilities(9); // pair, two pair, three of a kind,
    printf("Current High Card: %zu of %c\n",cards[0].val,cards[0].suit);
    std::cout <<"-----Probabilities-----\n";
    // probability of pair
    if (low.val == high.val) {
        probabilities[0] = 1;
    }
    else {

    }
}

int main() {
    int bank = 0; // this will serve as a counter to tell the user how much money they've won or lost
    /*
    a poker game has several phases that repeat themselves each hand.
    First, we are dealt two cards. We can analyze how much we like our hand, and depending on what others bet,
    check, fold, or raise.
    */
    size_t players;
    std::cout << "Hey there! I'm Pobi. Let's win some poker!\n";
    std::cout << "Enter number of players: ";
    std::cin >> players;
    std::cout << "Okay great! For this game, we'll count face cards as their numeric value. That means that a K is 13, Q is 12, etc.\n";
    std::cout << R"(Go ahead and enter your first two cards in the format "Suit Value.")" << std::endl;
    char suit = (char)NULL;
    size_t val = 0;
    std::vector<Card> dealt_cards;
    std::cout << "First card: ";
    std::cin >> suit >> val;
    Card first = Card(suit,val);
    dealt_cards.push_back(first);
    std::cout << "Second card: ";
    std::cin >> suit >> val;
    Card second = Card(suit,val);
    dealt_cards.push_back(second);
    analyze_dealt_cards(dealt_cards);
    return 0;
}
