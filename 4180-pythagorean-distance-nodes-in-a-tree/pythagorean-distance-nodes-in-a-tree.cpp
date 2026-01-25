class Solution {
public:
    vector<int> bfs(int start, vector<vector<int>> &adj){
        int n = adj.size();
        vector<int> dist(n, -1);
        queue<int> q;
            dist[start] = 0;
            q.push(start);
        while(!q.empty()){
            int u = q.front();
            q.pop();
            for(int v : adj[u]){
                if(dist[v] == -1){
                    dist[v] = dist[u] + 1;
                    q.push(v);
                }
            }
        }
        return dist;
    }
    int specialNodes(int n, vector<vector<int>>& edges, int x, int y, int z) {
        // x y z are distinct nodes
        vector<vector<int>> adj(n);
        for(auto &edge : edges){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // adj list done tmkc...
        vector<int> distx = bfs(x, adj);
        vector<int> disty = bfs(y, adj);
        vector<int> distz = bfs(z, adj);
        int ans = 0;
        for(int i= 0; i < n; i++){
            vector<int> d = {distx[i], disty[i], distz[i]};
            sort(d.begin(), d.end());
            long long a = d[0];
            long long b = d[1];
            long long c = d[2];
            if(a*a + b*b == c*c) ans++;
        }
        return ans;
    }
};