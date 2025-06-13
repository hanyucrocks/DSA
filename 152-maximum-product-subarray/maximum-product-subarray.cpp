class Solution {
public:
    int f(int i, vector<int> &nums, vector<int> &dpMax, vector<int> &dpMin) {
        if(i == 0) {
            dpMax[0] = dpMin[0] = nums[0];
            return nums[0];
        }

        if(dpMax[i] != INT_MIN) return dpMax[i];

        f(i - 1, nums, dpMax, dpMin); // calculate i-1

        int curr = nums[i];
        int tempmax = max({curr, curr * dpMax[i - 1], curr * dpMin[i - 1]});
        int tempmin = min({curr, curr * dpMax[i - 1], curr * dpMin[i - 1]}); // FIXED

        dpMax[i] = tempmax;
        dpMin[i] = tempmin;

        return dpMax[i];
    }

    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        vector<int> dpMax(n, INT_MIN), dpMin(n, INT_MAX);

        int ans = nums[0];
        for(int i = 0; i < n; i++)
            ans = max(ans, f(i, nums, dpMax, dpMin)); // FIXED: call f(i), not f(i+1)

        return ans;
    }
};
