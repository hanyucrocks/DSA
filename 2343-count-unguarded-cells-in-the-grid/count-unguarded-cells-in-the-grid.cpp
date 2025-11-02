class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> grid(m, vector<int> (n, 0));
        // how do i mark the tiles that have been seen by a guard?
        for(auto &w : walls){
            int r=w[0],c=w[1];
            grid[r][c]=1;
        }
        for(auto &g : guards){
            int r=g[0],c=g[1];
            grid[r][c]=2;
        }
        int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        for(auto &g : guards){
            int gr=g[0],gc=g[1];
            for(int d =0; d < 4; d++){
                // all four directionsd
                int r = gr + dir[d][0];
                int c = gc + dir[d][1];
                while(r >= 0 and r < m and c >=0 and c < n){
                    if(grid[r][c] == 1 or grid[r][c] == 2) break;
                    if(grid[r][c] == 0) grid[r][c] = 3;
                    r += dir[d][0];
                    c += dir[d][1];
                }
            }
        }
        int cnt = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 0) cnt++;
            }
        }
        return cnt;
    }
};