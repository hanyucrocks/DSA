class Solution {
public:
    int reverseNum(int x) {
        int r = 0;
        while (x) {
            r = r * 10 + (x % 10);
            x /= 10;
        }
        return r;
    }

    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<int, int> lastIndex;
        int ans = INT_MAX;

        for (int i = 0; i < nums.size(); i++) {
           
            if (lastIndex.count(nums[i])) {
                ans = min(ans, i - lastIndex[nums[i]]);
            }
            int rev = reverseNum(nums[i]);
            lastIndex[rev] = i;
        }

        return (ans == INT_MAX) ? -1 : ans;
    }
};