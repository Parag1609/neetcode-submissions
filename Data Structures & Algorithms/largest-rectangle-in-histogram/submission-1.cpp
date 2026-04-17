class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int>st;
        int max_area=0;
        for(int i=0;i<heights.size();i++){
            while(!st.empty() && heights[st.top()]>heights[i]){
                int a=st.top();
                st.pop();
                int nse=i;
                int pse=st.empty()?-1: st.top();
                max_area=max(heights[a]*(nse-pse-1),max_area);
            }
            st.push(i);
        }
        while(!st.empty()){
            int a=st.top();
            st.pop();
            int pse=st.empty()?-1:st.top();
            int nse=heights.size();
            max_area=max(heights[a]*(nse-pse-1),max_area);
        }
        return max_area;
    }
};
