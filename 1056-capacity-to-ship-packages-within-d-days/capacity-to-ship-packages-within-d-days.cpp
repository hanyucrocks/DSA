class Solution {
public:
    int FindDays(vector<int> &weights, int cap){
        int days = 1, load = 0;
        for(int i = 0;i < weights.size(); i++){
            if(weights[i]+load > cap){
                days++;
                load = weights[i];
            }
            else load += weights[i];
        }
        return days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        int sum = 0;
        for(int i =0; i < n; i++) sum += weights[i];
        int low = *max_element(weights.begin(), weights.end());
        int high = sum;
        while(low <= high){
            int mid = (low + high)/2;
            int nod = FindDays(weights, mid);
            if(nod <= days) high = mid-1;
            else low = mid+1;
        }
        return low;
    }
};