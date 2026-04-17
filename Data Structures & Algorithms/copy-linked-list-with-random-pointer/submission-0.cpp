/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        map<Node*, Node*>mp;
        Node* temp=head;
        Node* dummy=new Node(0);
        Node* newHead=dummy;
        while(temp){
            Node* newNode=new Node(temp->val);
            newHead->next=newNode;
            mp[temp]=newNode;
            temp=temp->next;
            newHead=newHead->next;
        }
        temp=head;
        while(temp){
            Node* curr=mp[temp];
            curr->random=(temp->random) ? mp[temp->random] : NULL;
            temp=temp->next;
        }
        return dummy->next;

    }
};
