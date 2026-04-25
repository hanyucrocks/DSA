class Solution {
public:
    bool validDigit(int n, int x) {
        // kya hseekhna haio
        // valid if atleast one occurence of digit x and doesnt start with x
        string s = to_string(n);
        char xx = '0' + x;
        if(s[0] == xx) return false;
        bool ok = false;
        for(char c : s){
            if(c == xx){
                ok = true;
                break;
            }
        }
        return ok;
    }
};