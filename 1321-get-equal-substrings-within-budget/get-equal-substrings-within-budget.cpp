class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        // s-> t
        int cnt = 0;
        // cost = ascii(s[i] - t[i]);
        // freq[s[a] - '0'];
        int maxcont = 0;
        int n = s.size();
        int start = 0;
        for(int i = 0; i < n; i++){
            int diff = abs(s[i] - t[i]);
            cnt += diff;
            while(cnt > maxCost){
                cnt -= abs(s[start] - t[start]);
                start++;
            }
            maxcont=max(maxcont, i -start+1);
        }
        return maxcont;
    }
};