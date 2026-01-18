class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        // is your threat not a promise.....
        // do not have to be distinct
        // so a k k grid in m n big brid
        // sdp interlude
        vector<vector<int>> rowpref(m, vector<int>(n + 1, 0));
        vector<vector<int>> colPref(m + 1, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                rowpref[i][j + 1] = rowpref[i][j] + grid[i][j];
                colPref[i + 1][j] = colPref[i][j] + grid[i][j];
            }
        }
        // prefix done
        // start with biggest k
        for (int k = min(m, n); k >= 1; k--) {
            for (int i = 0; i + k<= m; i++) {
                for (int j = 0; j +k<=n; j++) {
                    int targetsum =
                        rowpref[i][j + k] - rowpref[i][j]; // this is the target
                    bool found = true;
                    for (int r = i; r < i + k and found; r++) {
                        int sum = rowpref[r][j + k] - rowpref[r][j];
                        if (sum != targetsum)
                            found = false;
                    }
                    // now all cols
                    for (int c = j; c < j + k and found; c++) {
                        int sum = colPref[i + k][c] - colPref[i][c];
                        if (sum != targetsum)
                            found = false;
                    }
                    // diagonals
                    int diag1 = 0, diag2 = 0;
                    for (int d = 0; d < k; d++) {
                        diag1 += grid[i + d][j + d];
                        diag2 += grid[i + d][j + k - 1 -d];
                    }
                    if (diag1 != targetsum or diag2 != targetsum)
                        found = false;
                    if (found)
                        return k;
                }
            }
        }
        return -1;
    }
};