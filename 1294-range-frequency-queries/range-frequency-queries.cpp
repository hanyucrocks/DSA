class ST{
    vector<unordered_map<int, int>> st;
    int n;
    void buildTree(int i, int l, int r, vector<int> &arr){
        if(l == r){
            st[i][arr[l]]++;
            return;
        }
        int mid = (l+r)/2;
        buildTree(2*i+1, l, mid, arr);
        buildTree(2*i+2, mid+1, r, arr);
        for(auto [k, val] : st[2*i+1]){
            st[i][k] += val;
        }
        for(auto [k, val] : st[2*i+2]){
            st[i][k] += val;
        }
    }
    public:
    ST(vector<int> &nums){
        n = nums.size();
        st.resize(4*n);
        buildTree(0, 0, n - 1, nums);
    }
    int Query(int start, int end, int i, int l, int r, int val){
        if(l > end or r < start) return 0;
        if(l >= start and r <= end) return st[i].count(val) ? st[i][val] : 0;
        int mid = (l+r)/2;
        return Query(start, end, 2 * i+ 1, l, mid, val) + Query(start, end, 2 * i + 2, mid+1, r, val);
    }
};

class RangeFreqQuery {
public:
    ST* st;
    int n;
    RangeFreqQuery(vector<int>& arr) {
        n = arr.size();
        st = new ST(arr);
    }
    int query(int left, int right, int value) {
        return st->Query(left, right, 0, 0, n - 1, value);
    }
};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */