class Solution {
public:
    void dfs(int node, vector<vector<int>> &rooms, vector<int> &vis){
        vis[node] = 1;
        for(auto it : rooms[node]){
            if(!vis[it]){
                dfs(it, rooms, vis);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        // int m = rooms[0].size();
        // adjacentcy list?

        vector<int> vis(n, 0);
        dfs(0, rooms, vis);
        // if every vis is 1 then yes otherwise no
        for(int i = 0; i < n; i++){
            if(vis[i] != 1){
                return false;
                break;
            }
        }
        return true;
    }
};