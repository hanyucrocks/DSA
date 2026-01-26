class Solution {
public:
    bool kahns(int V, vector<vector<int>> &edges){
        vector<vector<int>> adj(V);
        for(auto &edge : edges){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
        }
        // adj list done
        vector<int> list;
        queue<int> q;
        // indegree
        vector<int> indegree(V, 0);
        for(int i = 0;i<V;i++){
            for(auto it : adj[i]) indegree[it]++;
        }
        for(int i = 0; i <V;i++){
            if(indegree[i] == 0) q.push(i);
        }
        while(!q.empty()){
            int top = q.front();
            q.pop();
            list.push_back(top);
            for(auto it : adj[top]){
                indegree[it]--;
                if(indegree[it] == 0){
                    q.push(it);
                }
            }
        }
        return list.size() == V;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        return kahns(numCourses, prerequisites);
    }
};