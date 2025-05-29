class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        // n -1 jayega 0 pe, 0 jayega n- 1 pe
        // 0, 0 goes to 0, n-1 pe
        // 0, 1 goes to 1, 3 

        // i will go to n - 1 -1
        // transpose karo. coloumn becomes row, row becomes coloumn

        for(int i = 0; i <= n - 2; i++){
            for(int j = i +1; j <= n -1; j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        for(int i = 0; i < n; i++){
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};