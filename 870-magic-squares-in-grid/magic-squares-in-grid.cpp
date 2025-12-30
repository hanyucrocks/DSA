class Solution {
public:
    bool isMagic(int r, int c, vector<vector<int>> &grid){
        if (grid[r+1][c+1] != 5) return false;
        bool seen[10] = {false};
        for(int i = 0; i <  3; i++){
            for(int j = 0; j < 3; j++){
                int x = grid[r+i][c+j];
                if(x < 1 or x > 9 or seen[x]) return false;
                seen[x] = 1;
            }
        }
        // now check for the each row or column
        for(int i = 0; i < 3;i++){
            int rowsum = 0, colsum = 0;
            for(int j  = 0; j < 3; j++){
                rowsum += grid[r+i][c+j];
                colsum += grid[r+j][c+i];
            }
        if (colsum != 15 or rowsum != 15) return false;
        }
        int diag1 = 0, diag2 = 0;
        for(int i = 0; i < 3; i++){
            diag1 += grid[r+i][c+i];
            diag2 += grid[r+i][c+2-i];
        }
        return diag1 == 15 and diag2 == 15;
    }

    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        /*
        each row, column and both diagonals all have the same sum
        sum hamesha 15 hi aayega
        har ek row, ek column, aur dono diagonals me check karlo ki 15 aara hai ki ni
        then the center must also be 5.
        */
        int cnt = 0;
        for(int r = 0; r <= n - 3; r++){
            for(int c = 0; c <= m - 3;c++){
                if(isMagic(r, c, grid)) cnt++;
            }
        }
        return cnt;
    }
};