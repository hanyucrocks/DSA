class Solution {
public:
    int evenSumSubgraphs(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size();
        // node i has value of nums[i] 0 -> 1, 1 -> 0, 2 -> 1
        // what is success, if not me
        vector<int> adj(n, 0);
        for(auto &e : edges){
            adj[e[0]] |= (1 << e[1]);
            adj[e[1]] |= (1 << e[0]);
        }
        int ans = 0;
        for(int mask = 1; mask < (1 << n); mask ++){
            int sum = 0;
            for(int i = 0; i < n; i++) if(mask & (1 << i)) sum += nums[i];
            if(sum % 2 != 0) continue;
            int start = __builtin_ctz(mask);
            int vis = (1 << start);
            queue<int> q;
            q.push(start);
            while(!q.empty()){
                int node = q.front();
                q.pop();
                int newNeighbours = adj[node] & mask & ~vis;
                vis |= newNeighbours;
                int temp = newNeighbours;
                // int lsb = __builtin_ctz(temp);
                while(temp){
                    q.push(__builtin_ctz(temp));
                    temp &= temp - 1;
                }
            }
            if(vis == mask) ans++;
        }
        return ans;
    }
};