class Solution {
public:
    bool isVowel(char c){
        c = tolower(c);
        return c == 'a' or c == 'e' or c=='i' or c=='o' or c=='u';
    }
    string reverseVowels(string s) {
        int n = s.size();
        int l = 0, r = n - 1;
        while(l < r){
            while(l < r and !isVowel(s[l])) l++;
            while(l < r and !isVowel(s[r])) r--;
            if(l < r){
                swap(s[l], s[r]);
                l++;
                r--;
            }
        }
        return s;
    }
};