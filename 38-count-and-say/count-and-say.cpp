class Solution {
public:
    string encode(const string &s){
        string result;
        int i = 0, n = s.size();
        while(i < n){
            int count = 1;
            while(i+1 < n && s[i]==s[i+1]){
                count++;
                i++;
            }
            result += to_string(count) + s[i];
            i++;
        }
        return result;
    }
    string countAndSay(int n) {
        if(n==1) return "1";
        // string prev = countAndSay(n-1);
        return encode(countAndSay(n-1));
    }
};