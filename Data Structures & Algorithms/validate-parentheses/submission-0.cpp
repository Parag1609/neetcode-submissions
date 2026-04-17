class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        char b;
        for(char a:s){
            if(a=='('|| a=='{' || a=='[')st.push(a);
            else{
                if(st.empty())return false;
                b=st.top();
                st.pop();
                if(a==')' && b!='(')return false;
                if(a==']' && b!='[')return false;
                if(a=='}' && b!='{')return false;
            }
        }
        return st.empty();
    }
};
