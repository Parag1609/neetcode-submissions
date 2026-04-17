class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int open=0;
        int close=0;
        string res="";
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]==')')close++;
            else if(s[i]=='(' && close>0)close--;
            else if(s[i]=='(' && close<=0)continue;
            res+=s[i];
        }
        reverse(res.begin(),res.end());
        string res2="";
        for(char a:res){
            if(a=='(')open++;
            else if(a==')'&& open>0){
                open--;
            }
            else if(a==')'&& open<=0){
                continue;
            }
            res2+=a;
        }
           return res2;     
    }
};