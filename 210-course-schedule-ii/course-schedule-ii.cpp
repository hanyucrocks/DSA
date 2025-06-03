class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int V = numCourses;
        vector<int> indegree(V, 0);
        vector<vector<int>> adj(V);
        
        // Build the adjacency list and compute indegrees
        for(auto& edge : prerequisites){
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            indegree[v]++;
        }
        
        queue<int> q;
        for(int i= 0; i < V; i++){
            if(indegree[i] == 0) q.push(i);
        }
        vector<int> topo;
        while(!q.empty()){
            int node = q.front(); q.pop();
            topo.push_back(node);
            for(auto it : adj[node]){
                indegree[it]--;
                if(indegree[it] == 0) q.push(it);
            }
        }
        reverse(topo.begin(), topo.end());
        if(topo.size() == V) return topo;
        else return {};
    }
};