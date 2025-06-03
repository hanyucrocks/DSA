class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        //// reverse the edges
        int n = graph.size();
        vector<int> indegree(n, 0);
        vector<vector<int>> adjRev(n);
        // reverse the edges
        for(int u = 0; u < n; u++){
            for(int v : graph[u]){
                adjRev[v].push_back(u);
                indegree[u]++;
            }
        }
        queue<int> q;
        vector<int> safeNodes;
        for(int i = 0; i < n; i++){
            if(indegree[i] == 0) q.push(i);
        }
        while(!q.empty()){
            int node = q.front(); q.pop();
            safeNodes.push_back(node);
            for(auto it : adjRev[node]){
                indegree[it]--;
                if(indegree[it] == 0) q.push(it);
            }
        }
        sort(safeNodes.begin(), safeNodes.end());
        return safeNodes;
    }
};