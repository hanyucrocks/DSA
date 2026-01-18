class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        // getline?... magic hour
        vector<string> words;
        int i = 0;
        while(i < n){
            while(i < n and s[i] == ' ') i++;
            if(i >= n) break;
                string word = "";
            while(i < n and s[i] != ' '){
                word.push_back(s[i]);
                i++;
            }
            words.push_back(word);
        }
        reverse(words.begin(), words.end());
        string ans = "";
        for(int i = 0; i < (int)words.size(); i++){
            ans += words[i];
            if(i != words.size() - 1) ans += " "; 
        }
        return ans;
    }
};