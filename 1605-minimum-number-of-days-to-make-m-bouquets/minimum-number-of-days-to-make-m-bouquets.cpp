class Solution {
public:
    // m bouqyetrs and but k adjacent flowers
    bool possible(vector<int> &bloomDay, int day, int m, int k){
        int cnt = 0, NoOfBokets = 0;
        for(int i = 0; i < bloomDay.size(); i++){
            if(bloomDay[i] <= day) cnt++;
            else{
                NoOfBokets += (cnt/k);
                cnt = 0;
            }
        }
        NoOfBokets += (cnt/k);
        return (NoOfBokets >= m);
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        if(1LL * m * k > bloomDay.size()) return -1;
        int low = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());
        while(low <= high){
            int mid = low + ((high - low)/2);
            if(possible(bloomDay, mid, m, k) == 1) high = mid-1;
            else low = mid+1;
        }
        return low;
    }
};