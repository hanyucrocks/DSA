class Solution {
public:
    bool check(vector<vector<int>> &pref, int k, int threshold){
        int m = pref.size();
        int n = pref[0].size();
        for(int i = 0; i + k< m; i++){
            for(int j = 0; j + k < n; j++){
                int sum = pref[i+ k][j+ k] - pref[i+k][j] - pref[i][j+k] + pref[i][j];
                if(sum <= threshold){
                    return true;
                }
            }
        }
        return false;
    }
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
        // lets go binary seach
        // alright how do i.. ugh, marty supreme n
       int low = 0;
       int high = min(m, n);
    //    int ans = 0;
       while(low <= high){
        int mid = low + (high-low)/2;
        if(check(pref, mid, threshold)){
            low = mid+1;
        }
        else high = mid-1;
       }
       return low - 1;
    }
};