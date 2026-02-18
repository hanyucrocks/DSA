class Solution {
    void buildTree(int i, int l ,int r, int st[], vector<int> &heights){
        if(l==r){
            st[i] = l;
            return;
        }
        int mid = (l+r)/2;
        buildTree(2*i+1, l, mid, st, heights);
        buildTree(2*i+2, mid+1, r,st, heights);
        int leftIdx = st[2*i+1];
        int rightIdx = st[2*i+2];
        if(heights[leftIdx] >= heights[rightIdx]) st[i] = leftIdx;
        else st[i] = rightIdx;
    }
    int* constructST(vector<int> &heights, int n){
        int *segTree = new int[4*n];
        buildTree(0, 0, n - 1, segTree, heights);
        return segTree;
    }
    int RMIQ(int st[], vector<int> &heights, int n, int start, int end){
        return query(start, end, 0, 0, n - 1, st, heights);
    }
    int query(int start, int end, int i, int l, int r, int st[], vector<int> &heights){
        if(l > end or r < start) return -1;
        if(l >= start and r <= end) return st[i]; // it will return idx of max element
        int mid = (l+r)/2;
        int LMI = query(start, end, 2 * i + 1, l, mid, st, heights);
        int RMI = query(start, end, 2 * i + 2, mid+1, r, st, heights);
        if(LMI == -1) return RMI;
        if(RMI == -1) return LMI;
        if(heights[LMI] >= heights[RMI]) return LMI;
        else return RMI;
    }
public:
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        int n = heights.size();
        int *segTree = constructST(heights, n);
        vector<int> ans;
        for(auto &q : queries){
            int min_idx = min(q[0], q[1]);
            int max_idx = max(q[0], q[1]);
            if(min_idx == max_idx){
                ans.push_back(min_idx);
                continue;
            }
            else if(heights[max_idx] > heights[min_idx]){
                ans.push_back(max_idx);
                continue;
            }
            // dono hints wale done
            else{
                int l = max_idx + 1;
                int r = n - 1;
                int firstIdx = -1;
                while(l <= r){
                    int mid = (l+r)/2;
                    int idx = RMIQ(segTree, heights, n, l, mid);
                    if(idx != -1 and heights[idx] > max(heights[min_idx], heights[max_idx])){
                        firstIdx = idx;
                        r = mid-1;
                    }
                    else l = mid+1;
                }
                ans.push_back(firstIdx);
            }
        }
        return ans;
    }
};