class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2,
                                       int k) {
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>,
                       greater<>>
            pq;
        for (int i = 0; i < min(k, (int)nums1.size()); i++) {
            pq.push({nums1[i] + nums2[0], i, 0});
        }
        vector<vector<int>> ans;
        for (int i = 0; i < k and !pq.empty(); i++) {
            // smallest eleme t from heap
            auto top = pq.top();
            auto [sum, r, c] = top;
            pq.pop();
            ans.push_back({nums1[r], nums2[c]});
            if(c + 1 < nums2.size()) pq.push({nums1[r] + nums2[c+1], r, c+1});
            // smallest elemet gone

        }
        return ans;
    }
};