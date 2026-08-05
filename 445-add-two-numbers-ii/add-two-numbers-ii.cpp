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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        vector<int>s1;
        vector<int>s2;
        ListNode*head1=l1;
        ListNode*head2=l2;
        while(head1!=nullptr){
            s1.push_back(head1->val);
            head1=head1->next;
        }
        while(head2!=nullptr){
            s2.push_back(head2->val);
            head2=head2->next;
        }
        int carry=0;
        ListNode*dummy=new ListNode(0);
        
        while(!s1.empty() || !s2.empty() || carry){
            int x1= (!s1.empty()) ? s1.back() :0;
            int x2= (!s2.empty()) ? s2.back() :0;
            int sum=x1+x2+carry;
            carry=sum/10;
            ListNode* node=new ListNode(sum % 10);
            node->next=dummy->next;
            dummy->next=node;
            if(!s1.empty()) s1.pop_back();
            if(!s2.empty()) s2.pop_back();
        }
        return dummy->next;
    }
};