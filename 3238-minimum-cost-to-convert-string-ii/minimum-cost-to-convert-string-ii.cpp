class Solution {
    typedef long long ll;
    typedef pair<ll, string> P;
    ll bada = 1e10;
    unordered_map<string, vector<pair<string, ll>>> adj; // graph
    vector<ll> dpMemo;
    string sourceStr;
    string targetStr;
    set<int> validLengths;

    ll dijkstra(string &start, string &end){
        priority_queue<P, vector<P>, greater<P>> pq;
        int n = start.size();
        // vector<int> result(n, INT_MAX);
        unordered_map<string, ll> result;
        result[start] = 0;
        pq.push({0, start});
        while(!pq.empty()){
            ll currCost = pq.top().first;
            string node = pq.top().second;
            pq.pop();
            if(node == end) break;
            for(auto &edge : adj[node]){
                string adjNode = edge.first;
                ll edgeCost = edge.second;
                if(!result.count(adjNode) or currCost + edgeCost < result[adjNode]){
                    result[adjNode] = currCost + edgeCost;
                    pq.push({currCost + edgeCost, adjNode});
                }
            }

        }
        ll finalCost = result.count(end) ? result[end] : bada;
        return finalCost;
    }

public:
    ll solve(int idx){
        if(idx >= sourceStr.length()) return 0;
        if(dpMemo[idx]!=-1) return dpMemo[idx];
        ll minCost = bada;
        if(sourceStr[idx] == targetStr[idx])
            minCost = solve(idx+1);
        
        for(auto &len : validLengths){
            if(idx + len > sourceStr.length()) break;
        string srcSub = sourceStr.substr(idx, len);
        string tgtSub = targetStr.substr(idx, len);

        if(!adj.count(srcSub)) continue;
        ll minPathCost = dijkstra(srcSub, tgtSub);
        if(minPathCost == bada) continue;
        minCost = min(minCost, minPathCost + solve(idx + len));
        }
        return dpMemo[idx] = minCost;
    }
    long long minimumCost(string source, string target,
                          vector<string>& original, vector<string>& changed,
                          vector<int>& cost) {
        sourceStr = source;
        targetStr = target;

        dpMemo.assign(10001, -1);

        for (int i = 0; i < original.size(); i++) {
            adj[original[i]].push_back({changed[i], cost[i]});
        }
        for(auto &s : original){
            validLengths.insert(s.length());
        }
        ll result = solve(0);
        return result == bada ? -1 : result;

    }
};