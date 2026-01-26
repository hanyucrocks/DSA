class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int V = numCourses;
        vector<vector<int>> adj(V);
        for(auto &edge : prerequisites){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
        }
        // add a check that if uv and vu exist then output nothing
        
        // adj list done
        vector<int> list;
        queue<int> q;
        // indegree
        vector<int> indegree(V, 0);
        for(int i = 0;i<V;i++){
            for(auto it : adj[i]) indegree[it]++;
        }
        for(int i = 0; i <V;i++){
            if(indegree[i] == 0) q.push(i);
        }
        while(!q.empty()){
            int top = q.front();
            q.pop();
            list.push_back(top);
            for(auto it : adj[top]){
                indegree[it]--;
                if(indegree[it] == 0){
                    q.push(it);
                }
            }
        }
        vector<int> ans = list;
        reverse(ans.begin(), ans.end());
        if((int)ans.size() == numCourses){
            return ans;
        }
        return {};
    }
};