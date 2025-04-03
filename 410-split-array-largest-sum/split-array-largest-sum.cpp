class Solution {
public:
    int func(vector<int> &arr, int pages){
    int student = 1, pagesstudent = 0;
    for(int i = 0; i < arr.size(); i++){
        if(pagesstudent +arr[i] <= pages) pagesstudent += arr[i];
        else{
            student++;
            pagesstudent = arr[i];
        }
    }
    return student;
}

int findPages(vector<int>& arr, int n, int m) {
    if(m > n) return -1;
    int low = *max_element(arr.begin(), arr.end());
   // int n = arr.size(); //
    int sum = 0;
    for(int i = 0; i < n; i++){
        sum += arr[i];
    }
    int high = sum;
    while(low <= high){
        int mid = (low + high)/2;
        if(func(arr, mid) <= m) high = mid-1;
        else low = mid+1;
    }
    return low;
    // Write your code here.
}
    int splitArray(vector<int>& nums, int k) {
        return findPages(nums, nums.size(), k);
    }
};