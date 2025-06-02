class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();        // rows
        int n = mat[0].size();     // cols

        queue<pair<pair<int, int>, int>> q;
        vector<vector<int>> vis(m, vector<int>(n, 0));
        vector<vector<int>> dist(m, vector<int>(n, 0));

        // Push all zero cells initially into the queue
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(mat[i][j] == 0){
                    q.push({{i, j}, 0});
                    vis[i][j] = 1;
                }
            }
        }

        vector<pair<int, int>> directions = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int steps = q.front().second;
            q.pop();

            dist[row][col] = steps;

            for(auto [dx, dy] : directions){
                int nr = row + dx;
                int nc = col + dy;

                if(nr >= 0 && nr < m && nc >= 0 && nc < n && vis[nr][nc] == 0){
                    vis[nr][nc] = 1;   
                    q.push({{nr, nc}, steps + 1});
                }
            }
        }
        return dist;
    }
};
