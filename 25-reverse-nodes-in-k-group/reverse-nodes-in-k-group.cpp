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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode*dummy=new ListNode(0);
        dummy->next=head;
        ListNode*p=head;
        int l=1;
        while(p->next!=nullptr){
            l++;
            p=p->next;
        }
        ListNode*groupPrev=dummy;
        while(l>=k){
            ListNode* kth=groupPrev;
            for(int i=0;i<k;i++){
                kth=kth->next;
            }
            ListNode* groupNext=kth->next;
            ListNode*prev=groupNext;
            ListNode*curr=groupPrev->next;
            ListNode*groupStart=groupPrev->next;
            while(curr!=groupNext){
                ListNode*next=curr->next;
                curr->next=prev;
                prev=curr;
                curr=next;
            }
            groupPrev->next = prev; 
            groupPrev = groupStart;
            l=l-k;
        }
        return dummy->next;
    }
};