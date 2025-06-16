class Solution {
public:
    int cnt = 0;
    void merge(vector<int> &arr, int low, int mid, int high){
        int left = low;
        int right = mid+1;
        vector<int> ans;
        while(left <= mid && right <= high){
            if(arr[left] <= arr[right]){
                ans.push_back(arr[left]);
                left++;
            }
            // right is smaller
            else{
                ans.push_back(arr[right]); 
                right++;
            }
        }
        while(left <= mid){
            ans.push_back(arr[left]);
                left++;
        }
        while(right <= high){
            ans.push_back(arr[right]); right++;
        }
         for(int i = low; i <= high; i++){
            arr[i] = ans[i-low];
        }
    }
void countPairs(vector<int> &arr, int low, int mid, int high){
    int right = mid+1;
    for(int i = low; i<= mid;i++){
        while(right <= high && (long)arr[i] > 2LL * arr[right]) right++;
        cnt += (right - (mid+1));
    }
}
void mergeSort(vector<int> &arr, int low, int high){
        if(low==high) return;
        int mid = (low + high) / 2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid+1, high);
        countPairs(arr, low, mid, high);
        merge(arr, low, mid, high);
}
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
     mergeSort(nums, 0, n-1);
     return cnt;
    }
};