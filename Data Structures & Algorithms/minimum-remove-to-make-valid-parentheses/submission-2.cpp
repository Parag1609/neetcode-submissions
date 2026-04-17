class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int open=0;
        int close=0;
        string res="";
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]==')')close++;
            else if(s[i] == '(') {
                if (close > 0) close--;
                else continue;
            }
            res+=s[i];
        }
        reverse(res.begin(),res.end());
        string res2="";
        for(char a:res){
            if(a=='(')open++;
            else if(a== ')') {
                if (open > 0) open--;
                else continue;
                }
            res2+=a;
        }
           return res2;     
    }
};