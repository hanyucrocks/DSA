class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n+1);
        for(auto &p : times){
            int u = p[0];
            int v = p[1];
            int w = p[2];
            adj[u].push_back({v, w});
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> dist(n+1, 1e9);
        dist[k] = 0;
        pq.push({0, k});
        while(!pq.empty()){
            auto top = pq.top();
            pq.pop();
            int d = top.first;
            int u = top.second;
            if(d > dist[u]) continue;
            for(auto &p : adj[u]){
                int v = p.first;
                int w = p.second;
                if(dist[v] > w + dist[u]){
                    dist[v] = w + dist[u];
                    pq.push({dist[v], v});
                }
            }
        }
        int maxi = INT_MIN;
        for(int i = 1; i <= n; i++){
            if(dist[i] == 1e9) return -1;
            else maxi = max(maxi, dist[i]);
        }
        return maxi;
    }
};