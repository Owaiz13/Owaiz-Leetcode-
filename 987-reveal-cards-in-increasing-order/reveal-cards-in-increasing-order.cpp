class Solution {
public:
    std::vector<int> deckRevealedIncreasing(std::vector<int>& deck) {
        // Step 1: Sort the deck
        std::sort(deck.begin(), deck.end());
        
        // Step 2: Initialize a deque
        std::deque<int> queue;
        
        // Step 3: Iterate through the sorted deck
        for (int i = deck.size() - 1; i >= 0; --i) {
            if (!queue.empty()) {
                // Pop an element from the back of the queue and push it to the front
                int back = queue.back();
                queue.pop_back();
                queue.push_front(back);
            }
            // Push the current card to the front of the queue
            queue.push_front(deck[i]);
        }
        
        // Step 4: Convert the deque to a vector and return it
        return std::vector<int>(queue.begin(), queue.end());
    }
};
