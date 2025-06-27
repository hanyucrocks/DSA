class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<vector<pair<int, int>>> adj(n);
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                int x1 = points[i][0], y1 = points[i][1];
                int x2 = points[j][0], y2 = points[j][1];
                int wt = abs(x1 - x2) + abs(y1-y2);
                adj[i].push_back({j, wt});
                adj[j].push_back({i, wt});
            }
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        int sum = 0;
        vector<int> vis(n, 0);
        pq.push({0, 0}); // wt and the node
        while(!pq.empty()){
            auto it = pq.top(); pq.pop();
            int node = it.second;
            int wt = it.first;
            
            if(vis[node]==1) continue;
            // visited set karna hai
            vis[node] = 1;
            sum += wt;
            
            for(auto it : adj[node]){
                int adjnode = it.first;
                int edW = it.second;
                if(!vis[adjnode]){
                    pq.push({edW, adjnode});
                }
            }
        }
        return sum;
    }
};