class Solution {
public:
    double dfs(string curr, string target, unordered_map<string, vector<pair<string, double>>> &adj, unordered_set<string> &vis){
        if(curr == target) return 1.0;
        vis.insert(curr);
        // now fort the neighbour nodes
        for(auto it : adj[curr]){
            if(!vis.count(it.first)){
                double res = dfs(it.first, target, adj, vis);
                if(res != -1.0) return it.second * res;
            }
        }
        return -1.0;
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int n = equations.size();
        unordered_map<string, vector<pair<string, double>>> adj;
        vector<double> ans;
        for(int i = 0; i < n; i++){
            string u = equations[i][0];
            string v = equations[i][1];
            double val = values[i];
            adj[u].push_back({v, val});
            adj[v].push_back({u, 1.0/val});
        }
        // now queryes
        for(auto &q : queries){
            string u = q[0];
            string v = q[1];
            if(adj.find(u) == adj.end() or adj.find(v) == adj.end()) ans.push_back(-1.0);
            else{
                unordered_set<string> vis;
                ans.push_back(dfs(u, v, adj, vis));
            }
        }
        return ans;
    }
};