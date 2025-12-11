class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int write = 0, start = 0;
        for(int i = 0; i <= n; i++){
            if(i == n or chars[start] != chars[i]){
                chars[write++] = chars[start];
                int count = i-start;
                if(count > 1){
                    string s = to_string(count);
                    for(char c : s) chars[write++] = c;
                }
            start = i;
            }
        }
        return write;
    }
};