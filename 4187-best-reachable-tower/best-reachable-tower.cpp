class Solution {
public:
    int manhattan(int x1, int y1, int x2, int y2) {
        return abs(x2 - x1) + abs(y2 - y1);
    }
    vector<int> bestTower(vector<vector<int>>& towers, vector<int>& center,
                          int radius) {
        // x y coordinates and q is quality
        // find the distance from center to the towers.
        int bestQ = -1;
        vector<int> best = {-1, -1};
        // return best;
        int cx = center[0];
        int cy = center[1];
        for (auto& t : towers) {
            int currQ = 0;
            int x2 = t[0];
            int y2 = t[1];
            int q = t[2];
            if (manhattan(x2, y2, cx, cy) <= radius){
                if(q > bestQ or (q == bestQ and (x2 < best[0] or (x2 == best[0] and y2 < best[1])))){
                    bestQ = q;
                    best = {x2, y2};
                } 
            }
        }
        return best;
    }
};