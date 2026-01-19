class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int m = mat.size();
        int n = mat[0].size();
        // bool found = true;
        vector<vector<int>> pref(m+1, vector<int> (n+1, 0));
        // pref[0][0] = mat[0][0];
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                pref[i+1][j+1] = pref[i][j+1] + pref[i+1][j] - pref[i][j] + mat[i][j];
            }
        }
        int ans = 0;
        // prefix 2d aray done
        for(int k = 1; k <= min(m, n); k++){
            for(int i = 0; i + k <= m; i++){
                for(int j = 0; j + k <= n; j++){
                    // now sum
                    int sum = pref[i+k][j+k] - pref[i+k][j] - pref[i][j+k] + pref[i][j];
                    if (sum <= threshold){
                        // this is the k i need
                        ans = max(ans, k);
                    }
                }
            }
        }
        return ans;
    }
};