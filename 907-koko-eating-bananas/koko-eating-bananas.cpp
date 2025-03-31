class Solution {
public:
    int calth(vector<int> &v, int hourly){
        int th = 0;
        int n = v.size();
        for(int i = 0; i < n; i++){
            th += (v[i] + hourly - 1) / hourly;  // Efficient integer ceiling
        }
        return th;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1, high = *max_element(piles.begin(), piles.end());

        while (low < high) {  // Alternative to prevent unnecessary iterations
            int mid = low + ((high - low) >> 1);  // Prevent overflow

            if (calth(piles, mid) <= h) 
                high = mid;
            else 
                low = mid + 1;
        }
        return low;  // Minimum valid speed
    }
};
