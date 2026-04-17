class MyQueue {
public:
    stack<int>input;
    stack<int>output;
    int peek_ele;
    MyQueue() {
        
    }
    
    void push(int x) {
        if(input.empty()) peek_ele=x;
        input.push(x);
    }
    
    int pop() {
        if(!output.empty()){
            int x=output.top();
            output.pop();
            return x;
        }
        else{
            while(!input.empty()){
            int x=input.top();
            input.pop();
            output.push(x);
            }
        }
        int x =output.top();
        output.pop();
        return x;
    }
    
    int peek() {
        if(!output.empty())return output.top();
        else return peek_ele;
    }
    
    bool empty() {
        return input.empty() && output.empty();
    }
    
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */