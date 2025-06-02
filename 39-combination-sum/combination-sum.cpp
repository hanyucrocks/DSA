class Solution {
public:
    void findsum(int i, int target, vector<int> &arr, vector<vector<int>> &ans, vector<int> &ds){
        int n = arr.size();
        if(i == n){
            if(target == 0){
                ans.push_back(ds);
            }
                return;
            }
            if(arr[i] <= target){
                ds.push_back(arr[i]);
                findsum(i, target - arr[i], arr, ans, ds);
                ds.pop_back();
            }
            findsum(i+1, target, arr, ans, ds);

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        int n = candidates.size();
        findsum(0, target, candidates, ans, ds);
        return ans;
    }
};