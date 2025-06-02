class Solution {
public:
    void f(int ind, vector<int>& a, vector<int>& ds, vector<vector<int>> &ans, int n) {
        if(ind == n){
            ans.push_back(ds);
            return;
        }
        ds.push_back(a[ind]);
        f(ind+1, a, ds, ans, n);
        ds.pop_back();
        f(ind+1, a, ds, ans, n);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> ds;
        f(0, nums, ds, ans, n);
        return ans;
    }
};