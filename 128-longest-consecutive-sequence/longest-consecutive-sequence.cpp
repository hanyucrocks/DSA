class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // sort kare toh gaye, O(NLogN) ho jayega
        // int longest = 1;
        // int cnt = 0;
        // int lastSmaller = INT_MIN;
        // sort(nums.begin(), nums.end());
        // for(int i = 0; i < nums.size(); i++){
        //     if(nums[i] - 1 == lastSmaller){
        //         lastSmaller=nums[i];
        //         cnt++;
        //     }
        //     else if(nums[i] != lastSmaller){
        //         cnt = 1;
        //         lastSmaller = nums[i];
        //     }
        //     longest = max(longest, cnt);
        // }
        // return longest;

        // Optimal Solution
        int n = nums.size();
        unordered_set<int> st(nums.begin(), nums.end());
        int cnt = 0;
        int longest = 1;
        // start looking for the first element of the sequence
        if(n == 0) return 0;
        for(auto it : st){
            if(st.find(it-1) == st.end()){
                int cnt = 1;
                int x = it;
                while(st.find(x+1) != st.end()){
                    x = x+1;
                    cnt++;
                }
                longest= max(longest, cnt);
            }
        }
        return longest;
    }
};