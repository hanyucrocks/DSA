class Solution {
public:
    string addBinary(string a, string b) {
        // new me, i know things
        // im running things, im running thingssssss
        int n = a.size();
        int m = b.size();
        string ans = "";
        int carry = 0;
        // last se chalu karenge na dono
        int i = n - 1, j = m - 1;
        while(i >= 0 or j >= 0 or carry){
            int sum = carry;
            if(i >=0) sum += a[i] - '0';
            if(j >= 0) sum += b[j] - '0';
            ans += (sum % 2) + '0';
            carry = sum/2;
            i--;
            j--;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};