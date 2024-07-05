/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
          if (!head || !head->next || !head->next->next) {
            // If there are less than 3 nodes, return [-1, -1]
            return {-1, -1};
        }
        vector<int>ans;
        vector<int>output;
        ListNode* temp=head;
        head=head->next;
        int count=2;
        while(head->next!=nullptr){

            if(temp->val<head->val && head->next->val<head->val || temp->val>head->val && head->next->val>head->val){
                ans.push_back(count);
            }
            
                head=head->next;
                temp=temp->next;
                count++;
            }
     if (ans.size() < 2) {
            // If there are less than 2 critical points, return [-1, -1]
            return {-1, -1};
        }
    int mini=INT_MAX;
    int start=0;
    int end=1;
    for(int i=0;i<ans.size()-1;i++){
        mini=min(mini,ans[end]-ans[start]);
        start++;
        end++;
    }
    output.push_back(mini);
    output.push_back(ans[ans.size()-1]-ans[0]);
    return output;;
    }
};