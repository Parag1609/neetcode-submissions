class Solution {
public:
    string simplifyPath(string path) {
        vector<string>st;
        string curr="";
        for(int i=0;i<=path.length();i++){
            if(path[i]=='/'|| i==path.size()){
                if(curr==".."){
                     if (!st.empty()) st.pop_back();
                }    
                else if(curr!="" && curr!=".")st.push_back(curr);                  
                curr="";
            }
            else curr+=path[i];           
        }
        string result="";
        while(!st.empty()){
            result='/'+st.back()+result;
            st.pop_back();
        }
        return result.empty()? "/" : result;

    }
};