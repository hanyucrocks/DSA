class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        // sabka value minus one first;
        for(int x : nums){
            int best = -1;
            for(int a = 0; a < x; a++){
                if((a | (a+1)) == x){
                    best = a;
                    break;
                }
            }
                ans.push_back(best);
        }
        return ans;
    }
};