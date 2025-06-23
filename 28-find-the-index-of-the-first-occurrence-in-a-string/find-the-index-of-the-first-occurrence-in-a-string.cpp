#define ll long long int
#define MOD 1000000033

// e - a == 4, s[i] - 'a' is used

class Solution {
public:
    ll hashValue(string s, ll radix, ll m) {
        ll ans = 0, factor = 1;
        for (ll i = m - 1; i >= 0; i--) {
            ans += ((s[i] - 'a') * factor) % MOD;
            factor = (factor * radix) % MOD;
        }
        return ans % MOD;
    }
    int strStr(string haystack, string needle) {
        ll n = haystack.size(), m = needle.size();
        if (m > n)
            return -1;

        ll radix = 26, maxweight = 1; // MW = 26^m;
        for (ll i = 1; i <= m; i++)
            maxweight = (maxweight * radix) % MOD;

        ll hashNeedle = hashValue(needle, radix, m);
        ll hashHay = 0;

        for (ll i = 0; i <= n - m; i++) {
            if (i == 0)
                hashHay = hashValue(haystack, radix, m);
            else {
                hashHay = (( ( (hashHay * radix) % MOD - ((haystack[i - 1] - 'a') * maxweight) % MOD + MOD ) % MOD
             + (haystack[i + m - 1] - 'a') ) % MOD);

            }
            if (hashNeedle == hashHay) {
                for (ll j = 0; j < m; j++) {
                    if (needle[j] != haystack[j + i])
                        break;
                    if (j == m - 1)
                        return i;
                }
            }
        }
        return -1;
    }
};