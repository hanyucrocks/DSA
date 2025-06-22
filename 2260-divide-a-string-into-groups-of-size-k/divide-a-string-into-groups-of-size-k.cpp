class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        int n = s.size();
        // if n % k == 0 then no use of fill
        vector<string> ans;
        for(int i = 0; i < n; i = i + k){
            string chunk = s.substr(i, k);
            if(chunk.size() < k) chunk += string(k - chunk.size(), fill);
            ans.push_back(chunk);
        }
        return ans;
    }
};