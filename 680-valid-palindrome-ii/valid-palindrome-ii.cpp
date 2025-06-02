class Solution {
public:
     bool isPalindromeRange(const string& s, int l, int r) {
        while (l < r) {
            if (s[l] != s[r]) return false;
            l++;
            r--;
        }
        return true;
    }
    bool validPalindrome(string s) {
        // peace maker 
        int n = s.size();
        int l = 0, r = n -1;
        while(l < r){
            if(s[l] == s[r]){
                l++; r--;
            }
            else {
                return isPalindromeRange(s, l, r - 1) || isPalindromeRange(s, l+1, r);
            }
        }
        return true;
    }
};