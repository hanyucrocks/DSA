class Solution {
public:
    vector<int> segMin, segMax, LazySeg;
    int n;
    // we need to assign all 3 of them to 4 * n
    // lets make the updateang3e
    void propogate(int i, int l, int r){
        if(LazySeg[i] != 0){
            segMin[i] += LazySeg[i];
            segMax[i] += LazySeg[i];
            if(l!=r){
                LazySeg[2 * i + 1] += LazySeg[i];
                LazySeg[2 * i + 2] += LazySeg[i];
            }
                LazySeg[i] = 0;
        }
    }
    void updateRange(int start, int end, int i, int l, int r, int val){
        // propogate too..
        propogate(i, l, r);
        if(r < start || l > end) return;
        if (l >= start and r <= end){
            LazySeg[i] += val;
            propogate(i, l, r);
            return;
        }
        int mid = (l+r)/2;
        updateRange(start, end, 2 * i + 1, l, mid, val);
        updateRange(start, end, 2 * i + 2, mid+1, r, val);
        segMin[i] = min(segMin[2*i+1], segMin[2*i+2]);
        segMax[i] = max(segMax[2*i+1], segMax[2*i+2]);
    }
    int findLeftMostZero(int i, int l, int r){
        propogate(i, l, r);
        if(segMin[i] > 0 or segMax[i] < 0) return -1;
        if(l == r) return l;
        int mid = l + (r-l)/2;
        int leftResult = findLeftMostZero(2*i+1, l, mid);
        if(leftResult != -1){
            return leftResult;
        }
        return findLeftMostZero(2*i+2, mid+1, r);
    }
    int longestBalanced(vector<int>& nums) {
        int n = nums.size();
        // longest balanced... subarray II
        // segment tree...
        segMin.assign(4 *n, 0);
        segMax.assign(4 *n, 0);
        LazySeg.assign(4 *n, 0);
        vector<int> cumSum(n, 0);
        int maxL = 0;
        unordered_map<int, int> m;
        for(int r = 0; r < n; r++){
            int val = (nums[r] % 2 == 0) ? 1 : -1;
            int prev = -1;
            if(m.count(nums[r])){
                prev = m[nums[r]];
            }
            if(prev != -1){
                updateRange(0, prev, 0, 0, n - 1, -val);
            }
            updateRange(0, r, 0, 0, n-1, val);
            int l = findLeftMostZero(0, 0, n - 1);
            if(l != -1){
                maxL = max(maxL, r - l + 1);
            }
            m[nums[r]] = r;
        }
        return maxL;
    }
};