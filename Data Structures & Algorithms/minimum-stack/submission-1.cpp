class MinStack {
private:    
    vector<int>st;
    vector<int>minst;
public:
    MinStack() {
        
    }
    
    void push(int val) {
       minst.push_back((st.size()==0)? val:min(val,minst.back()));
       st.push_back(val);
    }
    
    void pop() {
        st.pop_back();
        minst.pop_back();
    }
    
    int top() {
        return st.back();
    }
    
    int getMin() {
        return minst.back();
    }
};
