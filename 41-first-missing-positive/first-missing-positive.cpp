class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        // O1 space matlab inplace karna hai...
        int n = nums.size();
        int k = 1;
        // the answer lies between 1 to n.
        sort(nums.begin(), nums.end());
        for(int num : nums){
            if(num < k) continue;
            if(num == k) k = k + 1;
            else return k;
        }
        return k;
    }
};