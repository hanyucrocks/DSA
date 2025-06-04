class DisjoinSet
{

public:
    vector<int> rank, parent, size;
    DisjoinSet(int n)
    {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n+1);
        for (int i = 0; i <= n; i++){
            parent[i] = i;
            size[i] = i;
        }
    }
    int findPar(int node)
    {
        if (node == parent[node])
            return node;
        return parent[node] = findPar(parent[node]);
    }

    void unionByRank(int u, int v)
    {
        int ultp_u = findPar(u);
        int ultp_v = findPar(v);
        if (ultp_u == ultp_v)
            return;
        if (rank[ultp_u] < rank[ultp_v])
        {
            parent[ultp_u] = ultp_v;
        }
        else if (rank[ultp_v] < rank[ultp_u])
        {
            parent[ultp_v] = ultp_u;
        }
        else
        {
            parent[ultp_v] = ultp_u;
            rank[ultp_u]++;
        }
    }
    void unionBySize(int u, int v)
    {
        int ultp_u = findPar(u);
        int ultp_v = findPar(v);
        if (ultp_u == ultp_v)
            return;
        if (size[ultp_u] < size[ultp_v])
        {
            parent[ultp_u] = ultp_v;
            size[ultp_v] += size[ultp_u];
        }
        else
        {
            parent[ultp_v] = ultp_u;
            size[ultp_u] += size[ultp_v];
        }
    }
};


class Solution {
public:
    
    int makeConnected(int n, vector<vector<int>>& connections) {
        DisjoinSet ds(n);
        int cntextra=0;
        for(auto it : connections){
            int u = it[0];
            int v = it[1];
            if(ds.findPar(u)==ds.findPar(v)){
                cntextra++;
            }
            else{
                ds.unionBySize(u, v);
            }
        }
        int cntC = 0;
        for(int i = 0; i < n; i++){
            if(ds.parent[i] == i) cntC++;
        }
        int ans = cntC - 1;
        if(cntextra >= ans) return ans;
        return -1;
    }
};