class Solution {
public:
    string removeStars(string s) {
        int n = s.size();
        // stack
        // a counter to notice the movements
        string ans = "";
        // int j = 0;
        for(int i = 0; i < n; i++){
            if(s[i] != '*') ans.push_back(s[i]);
            else ans.pop_back();
        }
        return ans;
    }
};