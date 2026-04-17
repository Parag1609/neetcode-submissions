class Solution {
public:
    string minRemoveToMakeValid(string s) {
        unordered_set<int>idx;
        stack<int>st;
        for(int i=0;i<s.size();i++){
            if(st.empty()&&s[i]==')') idx.insert(i);
            else if(s[i]=='(')st.push(i);
            else if(!st.empty()&&s[i]==')')st.pop();
        }
        while(!st.empty()){
            int a= st.top(); st.pop();
            idx.insert(a);
        }
        string res="";
        for(int i=0;i<s.size();i++){
            if(idx.find(i)!=idx.end())continue;
            res+=s[i];
        }
        return res;
    }
};