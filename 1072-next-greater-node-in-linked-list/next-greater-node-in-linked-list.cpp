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
    vector<int> nextLargerNodes(ListNode* head) {
        ListNode*curr=head;
        int k=0;
        vector<int> ans;
        while(curr!=nullptr){
            ListNode*temp=curr->next;
            while(temp!=nullptr){
                if(temp->val > curr->val){
                    ans.push_back(temp->val);
                    break;
                }
                else{
                    temp=temp->next;
                }
            }
            if(temp==nullptr) ans.push_back(0);
            curr=curr->next;
        }
        return ans;
    }

};