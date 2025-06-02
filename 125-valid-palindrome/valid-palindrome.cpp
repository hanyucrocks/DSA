class Solution {
public:
    bool isPalindrome(string s) {
        //new string
       string cleaned = "";
        for (char c : s) {
            if (isalnum(c)) {
                cleaned += tolower(c);
            }
        }
        string reversed = cleaned;
        reverse(reversed.begin(), reversed.end());
        return (reversed == cleaned);
    }
};