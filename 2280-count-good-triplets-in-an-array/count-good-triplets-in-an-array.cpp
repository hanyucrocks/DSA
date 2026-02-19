class Solution {
    vector<long long> segTree;
    int n;
    // void buildTree(int i, int l, int r, vector<int> &arr){
    //     if(l==r){
    //         segTree[i] = arr[l];
    //         return;
    //     }
    //     int mid = (l+r)/2;
    //     buildTree(2*i+1, l, mid, arr);
    //     buildTree(2*i+2, mid+1, r, arr);
    //     segTree[i] = segTree[2*i+1] + segTree[2*i+2];
    // }
    int query(int start, int end, int i, int l, int r){
        if(l > end or r < start) return 0;
        if(l >= start and r <= end) return segTree[i];
        int mid = (l+r)/2;
        return query(start, end, 2*i+1, l, mid) + query(start, end, 2*i+2, mid+1, r);
    }
    void updateST(int i, int l, int r, int idx){
        if(l == r){
            segTree[i] = 1;
            return;
        }
        int mid = (l+r)/2;
        if(idx <= mid){
            updateST(2*i+1, l, mid, idx);
        }
        else updateST(2*i+2, mid+1, r, idx);
        segTree[i] = segTree[2*i+1] + segTree[2*i+2];
    }
public:
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        // good questions, thought process.
        // the dumbest bruteforces
        //segtree in nums2, range queries chalega usme, while nums1 me i.
        // nums1 me i toh wo element nums2 ka idx hoga..
        unordered_map<int, int> m;
        for(int i = 0; i < n; i++){
            m[nums2[i]] = i; // store hogya nums2 wala, ek ek idx

        }
        // sT code...
        segTree.assign(4*n, 0);
        long long res = 0;
        updateST(0, 0, n - 1, m[nums1[0]]); // ye update kardega segtree ko
        for(int i = 1; i < n; i++){
            int idx = m[nums1[i]]; // idx in nums2
            long long leftCommonCount = query(0, idx, 0, 0, n - 1);
            long long leftUnCommonCount = i - leftCommonCount;
            long long elementsAfterIdxNums2 = (n - 1 -idx);
            long long rightCommonCount = elementsAfterIdxNums2-leftUnCommonCount;
            // okay now
            res += leftCommonCount * rightCommonCount;
            updateST(0, 0, n - 1, idx);
        }
        return res;
    }
};