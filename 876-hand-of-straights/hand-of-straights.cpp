#include <vector>
#include <map>
#include <algorithm>

class Solution {
public:
    bool isNStraightHand(std::vector<int>& hand, int groupSize) {
        // Step 1: Check if the total number of cards is divisible by groupSize
        if (hand.size() % groupSize != 0) {
            return false;
        }

        // Step 2: Count the occurrences of each card
        std::map<int, int> cardCount;
        for (int card : hand) {
            cardCount[card]++;
        }

        // Step 3: Sort the unique card values
        std::vector<int> uniqueCards;
        for (const auto& pair : cardCount) {
            uniqueCards.push_back(pair.first);
        }
        std::sort(uniqueCards.begin(), uniqueCards.end());

        // Step 4: Form groups starting from the smallest card
        for (int card : uniqueCards) {
            while (cardCount[card] > 0) {
                // Try to form a group starting from this card
                for (int i = 0; i < groupSize; ++i) {
                    if (cardCount[card + i] > 0) {
                        cardCount[card + i]--;
                    } else {
                        return false;
                    }
                }
            }
        }

        return true; // All groups are successfully formed
    }
};
