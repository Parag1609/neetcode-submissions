class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int>days(n);
        stack<int>st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty()&&temperatures[st.top()]<=temperatures[i])st.pop();
            if(st.empty())days[i]=0;
            else days[i]=st.top()-i;
            st.push(i);
        }
        return days;
    }
};
