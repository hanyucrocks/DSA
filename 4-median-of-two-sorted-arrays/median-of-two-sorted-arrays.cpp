class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        int i = 0, j = 0, n = (n1 +n2), ind2=n/2, ind1=ind2-1, cnt=0,ind1el=-1,ind2el=-1;
        while(i<n1&&j<n2){
            if(nums1[i]<nums2[j]){
                if(cnt==ind1) ind1el=nums1[i];
                if(cnt==ind2) ind2el=nums1[i];
                cnt++; i++;
            }
            else{
                if(cnt==ind1) ind1el=nums2[j];
                if(cnt==ind2) ind2el=nums2[j];
                cnt++; j++;
            }
        }
        while(i<n1){
            if(cnt==ind1) ind1el=nums1[i];
            if(cnt==ind2) ind2el=nums1[i];
            cnt++;i++;
        }
        while(j<n2){
            if(cnt==ind1) ind1el=nums2[j];
            if(cnt==ind2) ind2el= nums2[j];
            cnt++; j++;
        }
        if(n % 2 == 1) return ind2el;
        return (double)((double)(ind1el+ind2el)) / 2.0;
    }
};