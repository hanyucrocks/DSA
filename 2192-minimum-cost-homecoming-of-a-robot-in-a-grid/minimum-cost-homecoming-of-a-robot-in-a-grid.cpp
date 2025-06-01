class Solution {
public:
    int minCost(vector<int>& startPos, vector<int>& homePos, vector<int>& rowCosts, vector<int>& colCosts) {
        int cost= 0;
        if(startPos[0] < homePos[0]){ // move along rows
            for(int r = startPos[0] + 1; r <= homePos[0]; r++) cost += rowCosts[r];
        } else {
            for(int r = startPos[0] - 1; r >= homePos[0]; r--) cost += rowCosts[r];
        }
        // move along columns
        if(startPos[1] < homePos[1]){
            for(int c = startPos[1] +1; c <= homePos[1]; c++) cost += colCosts[c];
        }
        else{
            for(int c = startPos[1] - 1; c >= homePos[1]; c--) cost += colCosts[c];
        }
        return cost;
            
    }
};