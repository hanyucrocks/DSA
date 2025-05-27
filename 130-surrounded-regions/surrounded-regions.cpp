class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        queue<pair<int, int>> q;

        auto bfs = [&](int row, int col){
            q.push({row, col});
            board[row][col] = '#';
            
            int delRow [] = {-1, 0, +1, 0};
            int delCol [] = {0, +1, 0, -1};
            while(!q.empty()){
                auto [r, c] = q.front(); q.pop();
                for(int i = 0; i < 4; i++){
                    int nr = r+delRow[i];
                    int nc = c + delCol[i];
                    if(nr >= 0 && nr < m && nc>=0 && nc< n && board[nr][nc]=='O'){
                        q.push({nr, nc});
                        board[nr][nc] = '#';
                    }
                }
            }
        };
        // start bfs from border Os
        for(int i = 0; i < m; i++){
            if(board[i][0]=='O') bfs(i, 0); // first col
            if(board[i][n-1]=='O') bfs(i, n-1); // last col
        }
        for(int j = 0; j < n; j++){
            if(board[0][j] == 'O') bfs(0, j); // first row
            if(board[m-1][j] == 'O') bfs(m-1, j);
        }
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == 'O') board[i][j] ='X';
                else if(board[i][j] == '#') board[i][j] = 'O';
            }
        }
    }
};