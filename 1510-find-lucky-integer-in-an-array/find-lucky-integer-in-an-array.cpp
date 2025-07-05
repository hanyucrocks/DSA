class Solution {
public:
    int findLucky(vector<int>& arr) {
        int n = arr.size();
       vector<int> hash(501, 0);
       for(int num : arr){
        hash[num]++;
       }
       for(int i = 500; i >=1; i--){
        if(hash[i] == i) return i;
       }
        // calculate the number of lucky numbers
        return -1;
    }
};