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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==nullptr || head->next==nullptr){
            return head;
        }
        ListNode*temp=head;
        int l=1;
        while(temp->next!=nullptr){
            l++;
            temp=temp->next;
        }
        temp->next=head;
        
        k=k%l;
        int moves=l-k-1;
        ListNode* h=head;
        for(int i=0;i<moves;i++){
            h=h->next;
        }
        ListNode* newHead=h->next;
        h->next=nullptr;
        return newHead;

    }
};