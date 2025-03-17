#include <iostream>
#include <algorithm>
#include "poker.hpp"

void analyze_dealt_cards(std::vector<Card> cards) {
    std::sort(cards.begin(),cards.end(),[](Card a, Card b) {
        return a.val > b.val;
    });
    printf("Current High Card: %zu of %c",cards[0].val,cards[0].suit);
}

int main() {
    int bank = 0; // this will serve as a counter to tell the user how much money they've won or lost
    /*
    a poker game has several phases that repeat themselves each hand.
    First, we are dealt two cards. We can analyze how much we like our hand, and depending on what others bet,
    check, fold, or raise.


    */
    std::cout << "Hey there! I'm Pobi. Let's win some poker!\n";
    std::cout << "First, can you tell me how many players are playing?";
    while (true) {

    }
    Card card = Card('H',9);
    card.output();
    return 0;
}
