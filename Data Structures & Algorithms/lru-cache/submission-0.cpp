class LRUCache {
public:
    class Node{
        public:
            int key,val;
            Node* prev;
            Node* next;

            Node(int k,int v){
            key=k;
            val=v;
            prev=next=NULL;
            }
    };

    unordered_map<int,Node*> mp;
    int cap;
    Node* head= new Node(-1,-1);
    Node* tail= new Node(-1,-1);

    LRUCache(int capacity) {
        cap=capacity;
        head->next=tail;
        tail->prev=head;
    }
    
    void deleteNode(Node* node){
        Node* prevNode = node->prev;
        Node* nextNode = node->next;

        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }

    void insertAfterHead(Node* node){
        Node* nextNode = head->next;

        head->next = node;
        node->prev = head;

        node->next = nextNode;
        nextNode->prev = node;
    }

    int get(int key) {
        if(mp.find(key)==mp.end()) return -1;

        Node* node = mp[key];
        int value = node->val;

        deleteNode(node);
        insertAfterHead(node);

        return value;
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end()){

        Node* node = mp[key];
        node->val = value;

        deleteNode(node);
        insertAfterHead(node);
        }
        else{
            if(mp.size()==cap){
                Node * lru = tail->prev;
                mp.erase(lru->key);
                deleteNode(lru);
            }
            Node* newNode = new Node(key,value);
            mp[key] = newNode;
            insertAfterHead(newNode);
            
        }
    }
};