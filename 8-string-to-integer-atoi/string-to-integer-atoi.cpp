class Solution {
public:
    int myAtoi(string s) {
        int n = s.size();
        int i = 0;
        while(i < n && s[i] == ' ') i++;
        int sign = 1;
        if(i < n && (s[i] == '-' || s[i] == '+')){
            if(s[i] == '-') sign = -1;
            i++;
        }
        // conert digits
        long long num = 0;
        while(i < n && isdigit(s[i])){
            num = num * 10 + (s[i] - '0');
            if(num * sign >= INT_MAX) return INT_MAX;
            if(num * sign <= INT_MIN) return INT_MIN;
            i++;
        }
        return (num * sign);
    }
};