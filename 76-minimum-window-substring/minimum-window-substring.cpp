class Solution {
public:
    string minWindow(string s, string t) {
        int left = 0, right = 0;
        int minLen = INT_MAX;
        int sindex = -1;
        int cnt = 0;
        int n = s.size();
        int m = t.size();
        vector<int> hash(256);
        for(int i = 0; i < m; i++) hash[t[i]]++;
        while(right < n){
            if(hash[s[right]]> 0) cnt++;
            hash[s[right]]--;
            while(cnt == m){
                if(right - left + 1 < minLen){
                    minLen = right - left + 1;
                    sindex = left;
                }
                hash[s[left]]++;
                if(hash[s[left]] > 0) cnt--;
                left++;
            }
            right++;
        }
        return sindex == - 1 ? "" : s.substr(sindex, minLen);
    }
};