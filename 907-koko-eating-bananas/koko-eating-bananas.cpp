class Solution {
public:
    int target(vector<int> &v, int mid){
        int th = 0;
        for(int i = 0; i < v.size(); i++){
            th += (v[i] + mid - 1) / mid;
        }
        return th;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int low = 1, high = *max_element(piles.begin(), piles.end());
        while(low < high){
            int mid = (low + ((high - low) >> 1));
            if(target(piles, mid) <= h){
                high = mid;
            }
            else low = mid+ 1;
        }
        return low;
    }
};