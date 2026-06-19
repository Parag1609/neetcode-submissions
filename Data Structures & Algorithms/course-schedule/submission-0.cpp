class Solution {
public:
    bool dfs( vector<vector<int>>& adj, vector<bool>& visited,vector<bool>& rec,int node){
       visited[node]=true;
       rec[node]=true;

       for(int &v:adj[node]){
        if(!visited[v]){
            if(dfs(adj,visited,rec,v))return true;
        }
        else if(rec[v])return true;
       }
       rec[node]=false;
       return false;
    }
    bool canFinish(int numCourses,vector<vector<int>>& prerequisites) {
        
        vector<int>v;
        vector<bool>visited(numCourses,false);
        vector<bool>rec(numCourses,false);
        vector<vector<int>>adj(numCourses);
        for(auto a:prerequisites){
            int prereq=a[1];
            int course=a[0];
            adj[prereq].push_back(course);
        }

        for(int i=0;i<numCourses;i++){
            if(!visited[i]){
               if( dfs(adj,visited,rec,i)) return false;
            }
        }
       return true;
    }
};
