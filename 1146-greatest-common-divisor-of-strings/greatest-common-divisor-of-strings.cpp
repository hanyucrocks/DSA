class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        // largest string x such that x divides both 
        int n = str1.size();
        int m = str2.size();
        if(str1 + str2 != str2 + str1) return "";
        int len = std::gcd(n, m);
        return str1.substr(0, len);
    }
};