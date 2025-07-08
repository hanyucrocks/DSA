class Solution {
public:
    bool possible(vector<int> &weights, int days, int cap){
        int reqdays = 1, load = 0;
        for(int weight : weights){
            if(weight > cap) return 0;
            if(load + weight > cap){
                reqdays++;
                load = weight;
            }
            else load += weight;
        }
        return reqdays <= days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);
        while(low <= high){
            int mid = low + (high-low)/2;
            int noOfDays = possible(weights, days, mid);
            if(noOfDays) high = mid-1;
            else low = mid+1;
        }
        return low;
    }
};