class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> ans(2, vector<int>());
        // ans.reserve(2, 2);
        unordered_set<int> s1;
        unordered_set<int> s2;
        for (int x : nums1) {
            s1.insert(x);
        }
        for (int x : nums2) {
            s2.insert(x);
        }
        for (int x : s1) {
            if (s2.find(x) == s2.end()) {
                ans[0].push_back(x);
            }
        }
        for (int x : s2) {
            if (s1.find(x) == s1.end()) {
                ans[1].push_back(x);
            }
        }
        // yehi chahiye na
        return ans;
    }
};