class Solution {
public:
    string reverseVowels(string s) {
        string ans;
        int n = s.size();
        ans.reserve(n);
        // reverse the a e i o u or A E I O U
        string vowels = "";
        for(int i = n - 1; i >= 0; i--){
            if(s[i] == 'a' or s[i] == 'e' or s[i] == 'i' or s[i] == 'o' or s[i] == 'u' or s[i] == 'A' or s[i] == 'E' or s[i] == 'I' or s[i] == 'O' or s[i] == 'U'){
                vowels.push_back(s[i]);
            } 
        }
        // AeeI
        int j = 0; // pointer for vowels
        for(int i = 0; i < n; i++){
            if(s[i] == 'a' or s[i] == 'e' or s[i] == 'i' or s[i] == 'o' or s[i] == 'u' or s[i] == 'A' or s[i] == 'E' or s[i] == 'I' or s[i] == 'O' or s[i] == 'U'){
                ans += vowels[j];
                j++;
            }
            else ans += s[i];
        }
        return ans;
    }
};