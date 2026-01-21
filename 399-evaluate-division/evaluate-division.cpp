class Solution {
public:
    double dfs(string curr, string target, unordered_map<string, vector<pair<string, double>>> &adj, unordered_set<string> &vis){
        if(curr == target) return 1.0;
        // vis[curr] = 1;
        vis.insert(curr);
        for(auto it : adj[curr]){ // current pe khade hai
            if(!vis.count(it.first)){
                double res = dfs(it.first, target, adj, vis);

                // result != -1.0 try again
                if(res != -1.0) return it.second * res; 
            }
        }
        return -1.0;
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, vector<pair<string, double>>> adj;
        int n = equations.size();
        for(int i= 0; i < n; i++){
            string u = equations[i][0];
            string v = equations[i][1];
            double val = values[i];
            adj[u].push_back({v, val});
            adj[v].push_back({u, 1.0/val});
        }
        vector<double> ans;
        // adj list done
        // now queries
        for(auto &query : queries){
            string u = query[0];
            string v = query[1];
            // now just find it
            if(adj.find(u) == adj.end() or adj.find(v) == adj.end()){
                ans.push_back(-1.0); // nahi mila u or v dono me se koi
            }
            else{
                unordered_set<string> vis;
                ans.push_back(dfs(u, v, adj, vis));
            }
        }
        return ans;
    }
};