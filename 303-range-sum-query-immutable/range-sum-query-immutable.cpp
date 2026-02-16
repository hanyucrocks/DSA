class NumArray {
public:
    vector<int> segTree;
    int n;
    void buildTree(int i, int l, int r, vector<int> &arr, vector<int> &segTree){
        if(l == r){
            segTree[i] = arr[l];
            return;
        }
        int mid = (l+r)/2;
        buildTree(2*i+1, l, mid, arr, segTree);
        buildTree(2*i+2, mid+1, r, arr, segTree);
        segTree[i] = segTree[2*i+1] +segTree[2*i+2];
    }
    int Query(int start, int end, int i, int l, int r, vector<int> &SegTree){
        if(l > end or r < start) return 0;
        if(l >= start and r <= end) return SegTree[i];
        int mid = (l+r)/2;
        return Query(start, end, 2 * i+ 1, l, mid, SegTree) + Query(start, end, 2 * i + 2, mid+1, r, SegTree);
    }
    NumArray(vector<int>& nums) {
        n = nums.size();
        segTree.assign(4*n, 0);
        buildTree(0, 0, n -1, nums, segTree);
    }
    
    int sumRange(int left, int right) {
        return Query(left, right, 0, 0, n - 1, segTree);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */