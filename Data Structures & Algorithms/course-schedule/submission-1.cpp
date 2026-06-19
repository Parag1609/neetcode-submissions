class Solution {
public:
    
    bool canFinish(int numCourses,vector<vector<int>>& prerequisites) {
        
        vector<bool>visited(numCourses,false);
        vector<int>indegree(numCourses,0);
        vector<vector<int>>adj(numCourses);
        queue<int>q;
        for(auto a:prerequisites){
            int prereq=a[1];
            int course=a[0];
            adj[prereq].push_back(course);
            indegree[course]++;
        }
        int count=0;
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int node=q.front();
            q.pop();
            count ++;
            for(int &v:adj[node]){
                indegree[v]--;
                if(indegree[v]==0)q.push(v);
            }
        }
        return count==numCourses;
        
    }
};
