class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        // if(n <= 2) return nums;
    
        vector<int> ans;
        unordered_map<int, int> freq;
        for(int i = 0; i < n; i++){
            freq[nums[i]]++;
            if(freq[nums[i]] == (n / 3) + 1){
                ans.push_back(nums[i]);
            }
        }
        return ans;
    }
};