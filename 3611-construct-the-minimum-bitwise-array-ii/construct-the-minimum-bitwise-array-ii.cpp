class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        // sabka value minus one first;
        for(int x : nums){
            if((x & 1) == 0){
                ans.push_back(-1);
                continue;
            }
            int t = 0;
            int temp = x;
            while(temp > 0 and (temp & 1)){
                t++;
                temp >>= 1;
            }
            ans.push_back(x - (1 << (t - 1)));
        }
        return ans;
    }
};