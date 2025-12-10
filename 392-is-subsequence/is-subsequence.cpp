class Solution {
public:
    bool isSubsequence(string s, string t) {
        // two pointer approach
        int n = s.size();
        int m = t.size();
        int i, j;
        i = 0, j = 0;
        while(i < n and j < m){
            if(s[i] == t[j]){
                i++, j++;
            }
            else{
                j++;
            }
        }
        return i == n;
    }
};