class Solution {
public:
    int count(vector<vector<int>> &matrix, int mid){
        int n = matrix.size();
        int i = n - 1, j = 0;
        int cnt = 0;
        while(i >= 0 and j < n){
            if(matrix[i][j] <= mid){
                cnt += (i+1);
                j++;
            }
            else i--;
        }
        return cnt;
    }
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int lo = matrix[0][0], hi = matrix[n-1][n-1];
        int ans  = -1;
        while(lo < hi){
            int mid = lo + ((hi-lo)/2);
            if(count(matrix, mid) < k){
                lo = mid + 1;
            }
            else{
                hi = mid;
            }
        }
        return lo;
    }
};