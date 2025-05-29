class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr(n+1);
        for(int i = 0; i <= n; i++) arr[i] = i;
        //now, compare
        int sum1 = accumulate(nums.begin(), nums.end(), 0);
        int sum2 = accumulate(arr.begin(), arr.end(), 0);
        return sum2-sum1;

    }
};