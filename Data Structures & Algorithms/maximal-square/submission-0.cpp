class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
   if(matrix.empty()) return 0;
        int rows=matrix.size();
        int columns=matrix[0].size();
        vector<vector<int>>prefixsum(rows, vector<int>(columns, 0));
        int max_area=0;
        for(int i=0;i<columns;i++){
            for(int j=0;j<rows;j++){
               if(matrix[j][i] == '0') {
                    prefixsum[j][i] = 0;
                } else {
                    prefixsum[j][i] = (j == 0) ? 1 : prefixsum[j-1][i] + 1;
                }
            }
        }

        for(int i=0;i<rows;i++){
            stack<int>st;
            for(int j=0;j<columns;j++){
                while(!st.empty() && prefixsum[i][st.top()]>prefixsum[i][j]){
                    int a =st.top();
                    st.pop();
                    int nse=j;
                    int pse=st.empty()?-1:st.top();
                    int square=min(prefixsum[i][a],nse-pse-1);
                    max_area=max(max_area,square*square);
                }
                st.push(j);
            }
            while(!st.empty()){
                int a =st.top();
                    st.pop();
                    int nse=columns;
                    int pse=st.empty()?-1:st.top();
                    int square=min(prefixsum[i][a],nse-pse-1);
                    max_area=max(max_area,square*square);
            }
        }
        return max_area;
    }
};