class Solution {
public:
    bool isVowel(char c){
        return c == 'a' or c == 'e' or c == 'i' or c =='o' or c == 'u';
    }
    int maxVowels(string s, int k) {
        int n = s.size();
        int cur = 0;
        // o  to k, phir k se n and count?
        for(int i = 0; i < k; i++){
            if(isVowel(s[i])) cur++;
        }
        int ans = cur;
        for(int i = k; i < n; i++){
            if(isVowel(s[i])) cur++;
            if(isVowel(s[i-k])) cur--;
            ans = max(ans, cur);
        }
        return ans;
    }
};