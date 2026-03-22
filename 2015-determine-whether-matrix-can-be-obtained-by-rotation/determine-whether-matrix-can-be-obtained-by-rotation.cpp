class Solution {
public:
    void rotate(vector<vector<int>> &mat){
        int n = mat.size();
        // we need to rotate max 4 times
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                swap(mat[i][j], mat[j][i]);
            }
        }
        for(int i = 0; i < n; i++){
            reverse(mat[i].begin(), mat[i].end());
        }
    }
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        
        // now we reverse the col
        int n = mat.size();
        for(int i = 0; i < 4; i++){
            if(mat == target) return 1;
            else rotate(mat);
        }
        return 0;
    }
};