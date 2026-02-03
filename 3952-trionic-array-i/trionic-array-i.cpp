class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int i = 0;
        int n = nums.size();
        while(i < n - 1 and nums[i] < nums[i+1])i++;
        if(i == 0 or i == n -1) return false;
        int p = i;
        while(i < n - 1 and nums[i] > nums[i+1])i++;
        if(i==p or i == n -1) return false;
        while(i < n - 1 and nums[i] < nums[i+1]) i++;
        return i==n-1;
    }
};