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
    bool isPalindrome(ListNode* head) {
        if(!head||!head->next)return true;
        //if(!head->next->next)return (head->val==head->next->val);
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast->next && fast->next->next){
            fast=fast->next->next;
            slow=slow->next;
        }
        ListNode* curr=slow->next;
        ListNode* prev=NULL;
    
        while(curr){
            ListNode* nex=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nex;
        }
        slow=head;       
        while(prev){
            if(slow->val!=prev->val)return false;
            slow=slow->next;
            prev=prev->next;
        }
        return true;
    }
};