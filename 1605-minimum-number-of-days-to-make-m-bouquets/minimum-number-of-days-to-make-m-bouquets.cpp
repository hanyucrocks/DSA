class Solution {
public:
    bool possible(vector<int> &bloomDay, int day, int m, int k){
        int cnt = 0, nob = 0;
        for(int i = 0; i < bloomDay.size(); i++){
            if(bloomDay[i]<=day) cnt++;
            else{
                nob += (cnt / k);
                cnt=0;
            }
        }
        nob += (cnt / k);
        return nob >= m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        if(1LL *m * k > n) return -1;
        int low = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());
        while(low <= high){
            int mid = (low + high)/2;
            if(possible(bloomDay, mid, m, k)) high = mid-1;
            else low = mid +1;
        }
        return low;
    }
};