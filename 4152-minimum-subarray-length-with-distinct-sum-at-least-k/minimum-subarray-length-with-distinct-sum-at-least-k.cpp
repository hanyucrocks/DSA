class Solution {
public:
    int minLength(vector<int>& nums, int k) {
        // sliding window
        int n = nums.size();
        int distinctSum = 0;
        int ans = INT_MAX;
        unordered_map<int, int> freq;
        int l = 0, r = 0;
        while (r < n) {
            // window
            freq[nums[r]]++;
            if (freq[nums[r]] == 1) {
                distinctSum += nums[r];
            }
            while (distinctSum >= k) {
                freq[nums[l]]--;
                if (freq[nums[l]] == 0) {
                    distinctSum -= nums[l];
                }
                int window = r-l+1;
                ans = min(ans, window);
                l++;
            }
            r++;
        }
        return (ans == INT_MAX ? -1 : ans);
    }
};