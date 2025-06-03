class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        // status is 1 if ith is open and 0 if ith is closed
        // candides
        // traverse all possible boxes
        // bfs
        int n = status.size();
        queue<int> q;
        vector<bool> vis(n, 0);
        vector<bool> haveKey(n, 0);
        vector<bool> seen(n, 0);

        for(int box : initialBoxes){
            seen[box] = true;
            if(status[box] == 1) q.push(box);
        }
        int totalcandies = 0;

        while(!q.empty()){
            int curr = q.front(); q.pop();
            if(vis[curr]) continue;
            vis[curr] = true;

            totalcandies += candies[curr];;
             // collect keys and try to open new boxes
            for(int key : keys[curr]){
                haveKey[key] = true;
                if(seen[key] && !vis[key] && status[key] == 0){
                    q.push(key); // push key unlocked box to queue
                    status[key] = 1;
                }
            }
            for(int box : containedBoxes[curr]){
                seen[box] = true;
                if((status[box] == 1 || haveKey[box]) && !vis[box]) {
                    q.push(box); status[box] = 1;
                }
            }
        }


        return totalcandies;
    }
};