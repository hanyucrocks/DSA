class Solution {
public:
    int minimumDeletions(string s) {
        int bcount = 0;
        int dels=0;
        for(char c : s){
            if(c=='b') bcount++;
            else dels = min(dels+1, bcount);
        }
        return dels;
    }
};