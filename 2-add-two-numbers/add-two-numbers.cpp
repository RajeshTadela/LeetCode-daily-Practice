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
        ListNode*head1=l1;
        ListNode*head2=l2;
        ListNode* dummy = new ListNode(0);
        ListNode*curr=dummy;
        int carry=0;
        while(head1!=nullptr || head2!=nullptr || carry!=0){
            int x1 = (head1 != nullptr) ? head1->val : 0;
            int x2 = (head2 != nullptr) ? head2->val : 0;
            int sum=x1 + x2+carry;
            carry=sum/10;
            curr->next=new ListNode(sum % 10);
            curr=curr->next;
            if(head1){head1=head1->next;}
            if(head2){head2=head2->next;}
        }
        return dummy->next;
    }
};