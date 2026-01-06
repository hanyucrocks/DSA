class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();
        // such that nums[i] == nums[j] and abs(i -j) indexes <= k
        unordered_set<int> seen;
        for(int i = 0; i < n; i++){
            // if duplicate then true
            if(seen.count(nums[i])) return true;
            seen.insert(nums[i]);
            if(seen.size() > k){
                seen.erase(nums[i-k]);
            }
        }
        return false;
    }
};