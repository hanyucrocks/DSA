class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        // n + 2 horizontal bars, m + 2 vertical bars
        //ugh iski mkc
        sort(hBars.begin(), hBars.end());
        // remove horizontal bars, toh vert hiegh increase...
        // and same vice versa
        // sidelneght * sidelength == maximum
        sort(vBars.begin(), vBars.end());
        
            int current_run = 1;
            int best_run = 1;
        for(int i = 0; i < hBars.size() - 1; i++){
            if(hBars[i+1] == hBars[i] + 1) current_run++;
            else{
                best_run = max(best_run, current_run);
                current_run = 1;
            }
            best_run = max(best_run, current_run);
        }
        int h_best = best_run + 1;
        current_run = 1;
        best_run = 1;
        for(int i = 0; i < vBars.size() - 1; i++){
            if(vBars[i+1] == vBars[i] + 1) current_run++;
            else{
                best_run = max(best_run, current_run);
                current_run = 1;
            }
            best_run = max(best_run, current_run);
        }
        int v_best = best_run + 1;
        int side = min(h_best, v_best);
    return side * side;
    }
};