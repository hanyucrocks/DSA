class Solution {
public:
    int diff(int mid, vector<int> &arr, int target){
        int sum = 0;
        for(int i = 0; i < arr.size(); i++) sum += min(mid, arr[i]);
        return abs(target - sum);
    }
    int findBestValue(vector<int>& arr, int target) {
        int l = 0, h = *max_element(arr.begin(), arr.end());
        while(l < h){
            int mid = l +(h-l)/2;
            if(diff(mid, arr, target) <= diff(mid+1, arr, target)) h = mid;
            else l = mid + 1;
        }
        return l;
    }
};