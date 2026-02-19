class Solution {
    vector<int> segTree;
    int n;
    // L se R ka range me maximum chahiye,,,,
    void buildTree(int i, int l, int r, vector<int> &arr){
        if(l==r){
            segTree[i] = arr[l];
            return;
        }
        int mid = (l+r)/2;
        buildTree(2*i+1, l, mid, arr);
        buildTree(2*i+2, mid+1, r, arr);
        segTree[i] = max(segTree[2*i+1], segTree[2*i+2]);
    }
    void updateST(int i, int l, int r, int idx){
        if(l == r){
            segTree[i] = 0;
            return;
        }
        int mid = (l+r)/2;
        if(idx <= mid){
            updateST(2*i+1, l, mid, idx);
        }
        else updateST(2*i+2, mid+1, r, idx);
        segTree[i] = max(segTree[2*i+1], segTree[2*i+2]);
    }
    bool queryST(int i, int l, int r, int fruit){
        if(segTree[i] < fruit) return false;
        if(l==r){
            segTree[i] = -1;
            return true;
        }
        int mid = (l+r)/2;
        bool placed = false;
        if(segTree[2*i+1] >= fruit) placed = queryST(2*i+1, l, mid, fruit);
        else placed = queryST(2*i+2, mid+1, r, fruit);
        segTree[i] = max(segTree[2*i+1], segTree[2*i+2]);
        return placed;
    }
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        // optimal code dono me patak dungi hqhqhqhq
        n= fruits.size();
        segTree.assign(4*n, 0);
        // sT banega basket ka...
        buildTree(0, 0, n - 1, baskets);
        int ans = 0;
        for(int fruit : fruits){
            if(queryST(0, 0, n - 1, fruit) == false){
                ans++;
            }
        }
        return ans;
    }
};