class Solution {
public:
    bool canCross(vector<int>& stones) {
        int n = stones.size();
       unordered_map<int, unordered_set<int>> dp;
        unordered_set <int> stoneSet(stones.begin(), stones.end());
        dp[0].insert(0);
        for(int i = 0; i < n; i++){
            int pos = stones[i];
            for(int k : dp[pos]){
                for(int jump = k - 1; jump <= k + 1; jump++){
                    if(jump > 0 && stoneSet.count(pos+jump)){
                        dp[pos+jump].insert(jump);
                    }
                }
            }
        }
         return !dp[stones.back()].empty();
    }
};