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
    void updateST(int idx, int val,int i,int l, int r){
        if(l == r){
            segTree[i] = val;
            return;
        }
        int mid = (l+r)/2;
        if(idx <= mid) updateST(idx, val, 2*i+1, l, mid);
        else updateST(idx, val, 2*i+2, mid+1, r);
        segTree[i] = segTree[2*i+1] +segTree[2*i+2];
    }
    NumArray(vector<int>& nums) {
        n = nums.size();
        segTree.assign(4*n, 0);
        buildTree(0, 0, n -1, nums, segTree);
    }
    int Query(int start, int end, int i, int l, int r, vector<int> &SegTree){
        if(l > end or r < start) return 0;
        if(l >= start and r <= end) return SegTree[i];
        int mid = (l+r)/2;
        return Query(start, end, 2 * i+ 1, l, mid, SegTree) + Query(start, end, 2 * i + 2, mid+1, r, SegTree);
    }
    void update(int index, int val) {
        updateST(index, val, 0, 0, n - 1);
    }
    
    int sumRange(int left, int right) {
        return Query(left, right, 0, 0, n - 1, segTree);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */