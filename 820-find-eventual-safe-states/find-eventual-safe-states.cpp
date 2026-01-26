class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V= graph.size();
        vector<int>indegree(V, 0);
        vector<vector<int>> adjRev(V);
        for(int i = 0; i < V; i++){
            for(int v : graph[i]){
                adjRev[v].push_back(i);
                indegree[i]++;
            }
        }
        queue<int> q;
        vector<int> list;
        for(int i = 0; i <V;i++){
            if(indegree[i] == 0) q.push(i);
        }
        while(!q.empty()){
            int top = q.front();
            q.pop();
            list.push_back(top);
            for(auto it : adjRev[top]){
                indegree[it]--;
                if(indegree[it] == 0) q.push(it);
            }
        }
        sort(list.begin(), list.end());
        return list;
        // compute indegree
    }
};