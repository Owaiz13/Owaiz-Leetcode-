class Solution {
public:
    void deleteNode(ListNode* node) {
        // Check if the given node or its next node is nullptr
        if (node == nullptr || node->next == nullptr)
            return;

        // Copy the value of the next node to the given node
        node->val = node->next->val;

        // Delete the next node
        ListNode* temp = node->next;
        node->next = node->next->next;
        delete temp;
    }
};
