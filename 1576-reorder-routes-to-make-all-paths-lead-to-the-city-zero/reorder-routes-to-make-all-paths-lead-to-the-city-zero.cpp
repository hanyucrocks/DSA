class Solution {
public:
    int dfs(int node, vector<vector<pair<int, int>>> &adj, vector<int> &vis){
        vis[node] = 1;
        int cnt = 0;
        for(auto it : adj[node]){
            if(!vis[it.first]){
                int childcount = dfs(it.first, adj, vis);
                cnt += childcount;
                if(it.second == 1) cnt++;
            }
        }
        return cnt;
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        // 0 to n - 1 se hai....
        vector<vector<pair<int, int>>> adj(n);
        for(const auto &edge : connections){
            int u = edge[0], v = edge[1];
            adj[u].push_back({v, 1});
            adj[v].push_back({u, 0});
        }
        // adj list done
        // dfs from 0
        vector<int> vis(n, 0);
        return dfs(0, adj, vis);
    }
};