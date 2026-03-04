class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        // override juice wrld i love youuuuuuuu
        vector<int> rows(m), cols(n);
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(mat[i][j] == 1){
                    rows[i]++;
                    cols[j]++;
                }
            }
        }
        int ans = 0;
        for(int i = 0;i < m; i++){
            for(int j = 0; j < n; j++){
                if(mat[i][j] == 1){
                    if(rows[i] == 1 and cols[j] == 1) ans++;
                }
            }
        }
        return ans;
    }
};