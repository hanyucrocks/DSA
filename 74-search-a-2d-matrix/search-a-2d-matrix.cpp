class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(); // row
        int n = matrix[0].size();
        // but you... boy you wanna come to my motel hoey... trash magic lana del rey i fucking love tyouuuuuuuuuuuuuu
        int low = 0, high = m * n - 1;
        while(low <= high){
            int mid = low + (high-low)/2;
            // yaawr what is the use of mid here....
            int row = mid/n;
            int col = mid % n;
            if(matrix[row][col] == target){
                return true;
                break;
            }
            else if(matrix[row][col] > target){
                high = mid-1;
            }
            else low = mid+1;
        }
        return false;
    }
};