class Solution {
public:
        void findcombo2(int ind, vector<int> &arr, vector<vector<int>> &ans, vector<int> &ds, int target){
        if(target == 0){
            ans.push_back(ds);
            return;
        }
        for(int j = ind; j < arr.size(); j++){
            if(j > ind && arr[j] == arr[j-1]) continue;
            if(arr[j] > target) break;
            ds.push_back(arr[j]);
            findcombo2(j+1, arr, ans, ds, target - arr[j]);
            ds.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        sort(candidates.begin(), candidates.end());
        findcombo2(0, candidates, ans, ds, target);
        return ans;
    }
};