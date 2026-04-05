class Solution {
public:
    int n;
    bool judgeCircle(string moves) {
        n = moves.size();
        int u = 0, d = 0, l = 0, r = 0;
        for(char c : moves){
            if(c == 'U') u++;
            else if(c == 'D') d++;
            else if(c == 'L') l++;
            else r++;
        }
        return ((u == d) and (l == r));
    }
};