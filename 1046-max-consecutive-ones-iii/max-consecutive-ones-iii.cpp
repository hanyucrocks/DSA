class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int start = 0, track = 0;
        int ans = 0;
        for(int end = 0; end < n; end++){
            if(nums[end] == 0) track++;
            while(track > k){
                if(nums[start]==0) track--;
                start++;
            }
            ans = max(ans, end - start + 1);

        }
        return ans;
    }
};