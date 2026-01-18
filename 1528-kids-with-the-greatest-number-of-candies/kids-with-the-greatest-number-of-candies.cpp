class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int n = candies.size();
        vector<bool> ans;
        ans.reserve(n);
        int maxi = *max_element(candies.begin(), candies.end());
        // just give the extracandies to each kid
        for(int i = 0; i  < n; i++){
            candies[i] += extraCandies;
            if(candies[i] >= maxi){
                ans.push_back(true);
            }
            else ans.push_back(false);
        }
        return ans;
    }
};