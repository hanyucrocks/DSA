class Solution {
public:
    int R, C;
    vector<vector<int>> dirs = {{-1, 0}, {+1, 0}, {0, 1}, {0, -1}};
    bool canCross(int day, vector<vector<int>> &cells){
        vector<vector<int>> grid(R, vector<int> (C, 0));
        queue<pair<int, int>> q;
        vector<vector<bool>> vis(R, vector<bool> (C, false));
        // flood till day.
        for(int i = 0; i < day; i++){
            int r = cells[i][0] - 1;
            int c = cells[i][1] - 1;
            grid[r][c] = 1;
        }
        // bfs from all top row cells
        for(int j = 0; j < C; j++){
            if(grid[0][j] == 0){
                q.push({0, j});
                vis[0][j] = 1;
            }
        }
        while(!q.empty()){
            auto [r, c] = q.front(); q.pop();
            // if reached bottom ROw
            if(r == R - 1) return 1;
            for(auto &d : dirs){
                int nr = r + d[0];
                int nc  = c + d[1];
                if(nr >= 0 and nr < R and nc >= 0 and nc < C and !vis[nr][nc] and grid[nr][nc] == 0){
                    q.push({nr, nc});
                    vis[nr][nc] = 1;
                }
            }
        }
        return 0;
    }
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        /*
        possible to walk from top to bottom by only walking on 0, if cells[i][j] == 0 then yes
        left, right up down
        binary search///>>>??

        */
        R = row, C = col;
        int left = 0, right = row * col;
        int ans = 0;
        while(left <= right){
            int mid = left + ((right-left)/2);
            if(canCross(mid, cells)){
                ans = mid;
                left = mid+1;
            }
            else right = mid-1;
        }
        return ans;
    }
};