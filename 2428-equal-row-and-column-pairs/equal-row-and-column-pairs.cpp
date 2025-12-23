class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        map<vector<int>, int> freq;
        for(auto &row : grid){
            freq[row]++;
        }
        int n = grid.size();
        int ans = 0;

        for(int c = 0; c < n; c++){
            vector<int> col;
            for(int row = 0; row < n; row++){
                col.push_back(grid[row][c]);
            }
            ans += freq[col];
        }
        return ans;
    }
};