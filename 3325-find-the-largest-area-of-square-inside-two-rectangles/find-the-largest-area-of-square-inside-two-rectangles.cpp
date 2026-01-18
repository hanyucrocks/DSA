class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {
        int n = bottomLeft.size();
        int m = bottomLeft[0].size();
        long long ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = i+ 1; j < n; j++){
                // x1 y1 bottomleft, x2 ye topright, x3 y3 bottomleft, x4 y4 top right
                int x1 = bottomLeft[i][0];
                int y1 = bottomLeft[i][1];
                int x2 = topRight[i][0];
                int y2 = topRight[i][1];
                int x3 = bottomLeft[j][0];
                int y3 = bottomLeft[j][1];
                int x4 = topRight[j][0];
                int y4 = topRight[j][1];
                int left = max(x1, x3);
                int right = min(x2, x4);
                int bottom = max(y1, y3);
                int top = min(y2, y4);
                if(right > left and top > bottom){
                    // overlap
                    int width = right - left;
                    int h = top - bottom;
                    int side = min(width, h);
                    long long area = 1LL * side * side;
                    ans = max(ans, area);
                }
            }
        }
        return ans;
    }
};