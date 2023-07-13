class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        //kahn's Algorithm for toposort using bfs 
         unordered_map<int,list<int>>adj;
         for(int i = 0;i<prerequisites.size();i++){
             int u = prerequisites[i][0];
             int v = prerequisites[i][1];

             adj[v].push_back(u);
         }

         vector<int>indegree(numCourses,0);
         for(auto i:adj){
             for(auto j:i.second){
                 indegree[j]++;
             }
         }

         queue<int>q;
         for(int i = 0;i<indegree.size();i++){
             if(indegree[i]==0){
                 q.push(i);
             }
         }
         int cnt = 0;
         while(!q.empty()){
             int front = q.front();
             q.pop();

             cnt++;
             for(auto neighbour:adj[front]){
                 indegree[neighbour]--;
                 if(indegree[neighbour]==0){
                     q.push(neighbour);
                 }
             }
         }
         if(cnt==numCourses){
            return true;
         }
         else 
         return false;
    }
};