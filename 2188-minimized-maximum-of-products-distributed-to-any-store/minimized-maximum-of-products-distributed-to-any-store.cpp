class Solution {
public:
    bool isPosssible(vector<int> &quantities, int n, int x){
        int stores = 0;
        for(int q: quantities){
            stores += (q+x-1) / x;
        }
        return stores <= n;
    }
    int minimizedMaximum(int n, vector<int>& quantities) {
        int low = 1, high = *max_element(quantities.begin(), quantities.end());
        while(low<high){
            int mid = low + ((high - low) / 2);
            if(isPosssible(quantities, n, mid)) high = mid;
            else low = mid+1;
        }
        return low;
    }
};