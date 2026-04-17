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
    ListNode* reversell(ListNode* l){
        if(!l||!l->next)return l;
        ListNode* newHead = reversell(l->next);
        l->next->next=l;
        l->next=NULL;

        return newHead;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
       if(!l1)return l2;
       if(!l2)return l1;
        ListNode* dummy = new ListNode(0);
        ListNode* temp=dummy;
       l1=reversell(l1);
       l2=reversell(l2);
       int carry=0;
       while(l1||l2||carry){
           int sum=0;
           if(l1){
               sum+=l1->val;
               l1=l1->next;
           }
           if(l2){
                sum+=l2->val;
                l2=l2->next;
           }
           sum+=carry;
           carry=sum/10;
           sum=sum%10;
           
           ListNode * newNode=new ListNode(sum);
           temp->next=newNode;
           temp=temp->next;
       }
        
        return reversell(dummy->next);        

    }
};