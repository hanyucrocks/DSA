class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        int n = arr.size();
        vector<pair<int, int>> ans(n);
        for(int i = 0; i < n; i++){
            int num = __builtin_popcount(arr[i]);
            ans[i] = {num, arr[i]};
        }
        sort(ans.begin(), ans.end());
        vector<int> woah;
        for(int i = 0; i < n; i++){
            woah.push_back(ans[i].second);
        }
        return woah;
    }
};