class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int n = nums.size();
        // int pairs = n/2;
        sort(nums.begin(), nums.end());
        // now two pointers
        int l = 0, r = n - 1;
        vector<int> pairs;
        while(l < r){
            int pair = nums[l] + nums[r];
            pairs.push_back(pair);
            l++;
            r--;
        }
        return *max_element(pairs.begin(), pairs.end());

    }
};