class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
       int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dist(n, vector<int> (m, 1e9));
        priority_queue<
            pair<int, pair<int, int>>, 
            vector<pair<int, pair<int, int>>>, 
            greater<pair<int, pair<int, int>>>>
        pq;
        pq.push({grid[0][0], {0, 0}});
         dist[0][0] = grid[0][0];

        int delRow[] = {-1, 0, +1, 0};
        int delCol[] = {0, +1, 0, -1};
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int diff = it.first;
            int row = it.second.first;
            int col = it.second.second;
            if(row == n - 1 && col == m -1) return diff;
            for(int i = 0; i <4; i++){
                int newr = row + delRow[i];
                int newc = col + delCol[i];
                if(newr >= 0 && newr < n && newc >= 0 && newc < m){
                    int newEffort = max(diff, grid[newr][newc]);
                    if(newEffort < dist[newr][newc]){
                        dist[newr][newc] = newEffort;
                        pq.push({newEffort, {newr, newc}});
                    }
                }
            }
        }
        return 0; 
    }
};