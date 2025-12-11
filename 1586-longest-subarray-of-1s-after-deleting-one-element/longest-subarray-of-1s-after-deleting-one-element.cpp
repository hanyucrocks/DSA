class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        // sliding window.... zyada se zyada ek zero hai waha pe
        int k = 1;
        int track = 0, ans =0, start = 0;
        for(int end = 0; end < n; end++){
            if(nums[end] == 0) track++;
            while(track > k){
                if(nums[start] == 0) track--;
                start++;
            }
            ans = max(ans, end - start + 1);
        }
        return ans - 1;

    }
};