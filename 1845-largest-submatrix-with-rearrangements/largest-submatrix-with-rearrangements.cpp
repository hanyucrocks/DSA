class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<int> height(n, 0);
        int ans = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 1)
                    height[j]++;
                else
                    height[j] = 0;
            }
            vector<int> temp = height;
            sort(temp.rbegin(), temp.rend());
            for (int j = 0; j < n; j++) {
                ans = max(ans, temp[j] * (j + 1));
            }
        }

        return ans;
    }
};