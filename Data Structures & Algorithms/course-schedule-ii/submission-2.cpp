class Solution {
public:
    void dfs(vector<bool>&visited, vector<bool>&rec,vector<vector<int>>&adj,stack<int>&st,int node,bool &hasCycle){
        visited[node]=true;
        rec[node]=true;

        for(auto &v:adj[node]){
            if(!visited[v]){
                dfs(visited,rec,adj,st,v,hasCycle);
            }
            else if(rec[v]){
                hasCycle=true;
            }
        }
        st.push(node);
        rec[node]=false;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        bool hasCycle = false;
        vector<bool>visited(numCourses,false);
         vector<bool>rec(numCourses,false);
        vector<vector<int>>adj(numCourses);
        stack<int>st;
        vector<int>res;
        for(auto a:prerequisites){
            int prereq=a[1];
            int course=a[0];
            adj[prereq].push_back(course);
    
        }
        
        for(int i=0;i<numCourses;i++){
            if(!visited[i] ){
               dfs(visited,rec,adj,st,i,hasCycle);
            }
        }
        if(hasCycle){
            return {};
        }
        while(!st.empty()){
            int a=st.top();
            st.pop();
            res.push_back(a);
        }
        return res;  
    }
};
