class Solution {
public:
    const int INF = 1e9;
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        long long dist[26][26];
        // int n = source.size();
        // 2d array, lets go
        for(int i = 0; i < 26; i++){
            for(int j = 0; j < 26; j++){
                if(i!=j) dist[i][j] = INF;
                else dist[i][j] = 0;
            }
        }
        // add edges
        for(int i = 0; i < original.size(); i++){
            int u = original[i] - 'a';
            int v = changed[i] - 'a';
            dist[u][v] = min(dist[u][v], (long long)cost[i]);
        }
        // floyd
        for(int k = 0; k < 26; k++){
            for(int i = 0; i < 26; i++){
                for(int j = 0; j < 26; j++){
                    if(dist[i][k] < INF and dist[k][j] < INF){
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }
        }
        //
        long long ans = 0;
        for(int i = 0; i < source.length(); i++){
            int s = source[i] - 'a';
            int t = target[i] - 'a';
            if(dist[s][t] == INF) return -1;
            ans += dist[s][t];

        }
        return ans;
    }
};