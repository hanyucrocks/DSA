class Solution {
public:
    vector<int> transformArray(vector<int>& nums) {
        int n = nums.size();
       for(int &num : nums){
        num = (num % 2 == 0) ? 0 : 1; 
       }
       sort(nums.begin(), nums.end());
       return nums;
    }
};