class Solution {
    vector<int> segTree;
    int n;
    void buildTree(int i, int l, int r, vector<int> &arr){
        if(l == r){
            segTree[i] = l; // storing the index itself.
            return;
        }
        int mid = (l+r)/2;
        buildTree(2*i+1, l, mid, arr);
        buildTree(2*i+2, mid+1, r, arr);

        // segTree[i] = max(segTree[2*i+1], segTree[2*i+2]);
         int leftIdx  = segTree[2*i+1];
    int rightIdx = segTree[2*i+2];

    if(arr[leftIdx] >= arr[rightIdx])
        segTree[i] = leftIdx;
    else
        segTree[i] = rightIdx;
    }
    int query(int start, int end, int i, int l, int r, vector<int> &arr){
        if(l > end or r < start) return -1;
        if(l >= start and r <= end) return segTree[i];
        int mid = (l+r)/2;
        int LMI = query(start, end, 2*i+1, l, mid, arr);
        int RMI=query(start,end,2*i+2,mid+1,r, arr);
        if(LMI == -1) return RMI;
        if(RMI==-1) return LMI;
        if(arr[LMI] >= arr[RMI])
        return LMI;
    else
        return RMI;
    }
public:
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        // RMIQ variant 3
        n = heights.size();
        segTree.resize(4*n, 0);
        vector<int> ans;
        buildTree(0, 0, n - 1, heights);
        // the tree is here.
        for(auto &q : queries){
            int start = q[0];
            int end = q[1];
            if(start > end) swap(start, end);
            if(start == end){
                ans.push_back(start);
                continue;
            }
            if(heights[end] > heights[start]){
                ans.push_back(end);
                continue;
            }
            // what is L and R here, toh end + 1 wala idx is L and heights[n-1] = R;
            int L = end + 1;
            int R = n - 1;
            if(L > R) {
                ans.push_back(-1);
                continue;
            }

            int threshold = max(heights[end], heights[start]);
            int RMIQ = query(L, R, 0, 0, n - 1, heights);
            if(heights[RMIQ] <= threshold) ans.push_back(-1);
            else{
                // now the binary search begins
                // L to R me binary search
                // int low = L;
                // int high = R;
                int firstIdx = -1;
                while(L <= R){
                    int mid = (L + R)/2;
                    int idx = query(L, mid, 0, 0, n - 1, heights);
                    if(idx != -1 and heights[idx]>threshold){
                        firstIdx = idx;
                        R = mid-1;
                    }
                    else L = mid + 1;
                }
                ans.push_back(firstIdx);
            }
        }
        return ans;
    }
};