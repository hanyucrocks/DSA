class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        unordered_map<int, int> mp;
        // heights[st.top] >= heights[i]
        stack<int> st;
        // vector<int> nge(m);
        for(int i = m - 1; i>=0; i--){
            while(!st.empty() and st.top() <= nums2[i]) st.pop();
            if(st.empty()){
                mp[nums2[i]] = -1;
            }
            else mp[nums2[i]] = st.top();
            st.push(nums2[i]); // hhere the nge is completeled, it will output 3 4 -1 -1..
        }
        vector<int> ans;
        for(int num : nums1){
            ans.push_back(mp[num]);
        }
        return ans;
    }
};