class Solution {
public:
    void func(int ind, vector<vector<int>> &ans, vector<int> &arr, vector<int> &ds){
        int n = arr.size();
        ans.push_back(ds);
        for(int i = ind; i < n; i++){
            if(i!=ind && arr[i] == arr[i-1]) continue;
            ds.push_back(arr[i]);
            func(i+1, ans, arr, ds);
            ds.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        vector<int> ds;
        func(0, ans, nums, ds);
        return ans;
    }
};