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
    ListNode* partition(ListNode* head, int x) {
        if(head==nullptr || head->next==nullptr){
            return head;
        }
        ListNode*temp=head;
        ListNode*dummy1=new ListNode(0);
        ListNode*dummy2=new ListNode(0);
        ListNode*d1=dummy1;
        ListNode*d2=dummy2;
        while(temp!=nullptr){
            ListNode* next=temp->next;
            if(temp->val < x){
                d1->next=temp;
                d1=d1->next;
            }
            else{
                d2->next=temp;
                d2=d2->next;
            }
            temp->next=nullptr;
            temp=next;
        }
        d1->next=dummy2->next;
        return dummy1->next;
    }
};