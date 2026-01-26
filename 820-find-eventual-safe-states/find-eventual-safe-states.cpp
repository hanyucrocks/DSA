class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();
        // jo touch nahi hua usko toh output karna hi hao
        // how do i build the adj list
        // you dont need the build the adj list here....
        queue<int> q;
        vector<int> ans;
        vector<int> outdegree(V, 0);
        for(int i = 0; i < V; i++){
            outdegree[i] = graph[i].size();
        }
        // outgrtee
        vector<vector<int>> rev(V);
        for(int i = 0; i <V;i++){
            for(int nei : graph[i]){
                rev[nei].push_back(i);
            }
        }
        // reversed the graph
        for(int i = 0; i < V; i++){
            if(outdegree[i] == 0) q.push(i);
        }
        vector<int> safe(V, 0);
        while(!q.empty()){
            int top = q.front();
            q.pop();
            safe[top] = 1;
            for(int parent : rev[top]){
                outdegree[parent]--;
                if(outdegree[parent] == 0) q.push(parent);
            }
        }
        for(int i = 0; i <V;i++){
            if(safe[i]) ans.push_back(i);
        }
        return ans;
        // i hope this is the adj

    }
};