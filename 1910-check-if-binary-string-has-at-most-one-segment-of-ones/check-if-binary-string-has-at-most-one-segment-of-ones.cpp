class Solution {
public:
    bool checkOnesSegment(string s) {
        int n = s.size();
        // atmost one?
        bool ok = true;
        for(int i = 1; i < n; i++){
            if(s[i] == '1'){
                if(s[i - 1] == '1') continue;
                else{
                    ok = false;
                    break;
                }
            }
        }
        return ok;
    }
};