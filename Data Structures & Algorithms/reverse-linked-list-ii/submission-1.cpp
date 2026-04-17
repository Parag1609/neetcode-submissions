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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(!head||!head->next)return head;
        ListNode* curr=head;
        ListNode* leftPrev=NULL;
        int idx=1;
        for(;idx<left;idx++){
            leftPrev=curr;
            curr=curr->next;
        }
        ListNode* prev=NULL;
        ListNode* leftN=curr;
        ListNode* next=NULL;
        while(curr && idx<=right ){
           
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
            idx++;
        }
        leftN->next=next;
        if(leftPrev)leftPrev->next=prev;
        else{
            head=prev;
        }
        return head;

    }
};