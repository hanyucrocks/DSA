class Solution {
public:
        int check(int target, vector<int>& tops, vector<int>& bottoms) {
        int topsrotation = 0, bottomsrotation = 0;
        for (int i = 0; i < tops.size(); i++) {
            if (tops[i] != target && bottoms[i] != target)
                return -1; 
            else if (tops[i] != target)
                topsrotation++;  
            else if (bottoms[i] != target)
                bottomsrotation++;  
        }
        return min(topsrotation, bottomsrotation);
    }
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        // the possible candidates are tops[0] and bottoms[0];
        // if(tops.size()!=bottoms.size()) return -1;
       int res = check(tops[0], tops, bottoms);
       if(res != -1 || tops[0] == bottoms[0]) return res;
       return check(bottoms[0], tops, bottoms);
    }
};