class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<int>indegree(numCourses,0);
        vector<vector<int>>adj(numCourses);
        queue<int>q;
        vector<int>res;
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
            res.push_back(node);
            for(int &v:adj[node]){
                indegree[v]--;
                if(indegree[v]==0)q.push(v);
            }
        }
        return count==numCourses? res: vector<int>{};      
    }
};
