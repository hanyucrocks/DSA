class Solution {
public:
    vector<int> merge(vector<int> &arr, int low, int mid, int high){
        int n = arr.size();
        vector<int> ans;
        int left = low;
        int right = mid+1;
        while(left <= mid && right <= high){
            if(arr[left]<=arr[right]){
                ans.push_back(arr[left]);
                left++;
            }
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
            ans.push_back(arr[right]);
                right++;
        }
        for(int i = low; i <= high; i++){
            arr[i] = ans[i-low];
        }
        return ans;
    }
    void mergeSort(vector<int> &arr, int low, int high){
        if(low==high) return;
        int mid = (low + high) / 2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid+1, high);
        merge(arr, low, mid, high);
    }
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        mergeSort(nums, 0, n-1);
        return nums;
    }
};