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
    ListNode* removeNodes(ListNode* head) {
        ListNode*curr=head;
        stack<ListNode*> st;
        while(curr!=nullptr){
            while(!st.empty() && st.top()->val < curr->val){
                st.pop();
            }
            st.push(curr);
            curr=curr->next;
        }
        vector<ListNode*> nodes;
        while(!st.empty()){
            nodes.push_back(st.top());
            st.pop();
        }
        reverse(nodes.begin(),nodes.end());
        ListNode*dummy=new ListNode(0);
        ListNode*tail=dummy;
        for(auto node : nodes){
            tail->next=node;
            tail=tail->next;
        }
        tail->next=nullptr;
        return dummy->next;
    }
};