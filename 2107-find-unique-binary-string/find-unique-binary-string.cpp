class Solution {
public:
    void generate(int n, string curr, vector<string> &ans) {
    if(curr.size() == n) {
        ans.push_back(curr);
        return;
    }

    generate(n, curr + '0', ans);
    generate(n, curr + '1', ans);
}
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        // for n == 1, nums == 0, 1
        // for n == 2, nums == 00, 01, 10, 11, 
        // for n == 3, nums == 2 ka power n
        vector<string> all;
        generate(n, "", all);
        unordered_set<string> st(nums.begin(), nums.end());
        for(auto &s : all) if(st.count(s) == 0) return s;
        return "";
    }
};