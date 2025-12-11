class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        int ans = 0;
        unordered_map<int, pair<int, int>> row;
        unordered_map<int, pair<int, int>> col;
        for(auto &b : buildings){
            int x = b[0], y = b[1];
            if(!row.count(y)) row[y] = {x, x};
            else{
                row[y].first = min(row[y].first, x);
                row[y].second = max(row[y].second, x);
            }
            if(!col.count(x)) col[x] = {y, y};
            else{
                col[x].first = min(col[x].first, y);
                col[x].second = max(col[x].second, y);
            }
        }
        for(auto &b : buildings){
            int x = b[0], y = b[1];
            if(row[y].first < x and x < row[y].second and col[x].first < y and y < col[x].second) ans++;
        }
        return ans;
    }
};