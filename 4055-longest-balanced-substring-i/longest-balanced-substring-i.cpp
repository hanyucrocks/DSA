class Solution {
public:
    int longestBalanced(string s) {
        int n = s.size();
        int ans = 0;
        for(int i = 0; i < n; i++){
            vector<int> freq(26, 0);
            for(int j = i; j < n; j++){
                freq[s[j] - 'a']++;
                // freq done
                bool ok = true;
                int val = 0;
                for(int k = 0; k < 26; k++){
                    if(freq[k] == 0) continue;
                    if(val == 0) val = freq[k];
                    else if(val != freq[k]) ok = false;
                }
                if(ok) ans = max(ans, j - i + 1);
            }
        }
            return ans;
    }
};