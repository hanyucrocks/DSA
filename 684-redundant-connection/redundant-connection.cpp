class DisjointSet
{    vector<int> rank, parent, size;

public:
    DisjointSet(int n)
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
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        // DAG
        int n = edges.size();
        DisjointSet ds(n);

        for(auto& edge : edges){
            int u = edge[0], v = edge[1];
            if(ds.findPar(u) == ds.findPar(v)) return edge;
            ds.unionByRank(u, v);
        }
        return {};
    }
};