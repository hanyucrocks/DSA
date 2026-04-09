class Solution {
public:
    static constexpr long long MOD = 1'000'000'007LL;

    struct Query {
        int l, r, v;
    };

    long long modPow(long long a, long long e) {
        long long res = 1;
        while (e) {
            if (e & 1) res = (res * a) % MOD;
            a = (a * a) % MOD;
            e >>= 1;
        }
        return res;
    }

    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = (int)nums.size();
        int B = (int)sqrt(n) + 1;

        vector<long long> mult(n, 1);

        // small k queries grouped by (k, remainder)
        vector<vector<vector<Query>>> bucket(B + 1);
        for (int k = 1; k <= B; ++k) bucket[k].resize(k);

        for (auto &q : queries) {
            int l = q[0], r = q[1], k = q[2], v = q[3];
            if (k <= B) {
                bucket[k][l % k].push_back({l, r, v});
            } else {
                // large k => few touched indices, safe to apply directly
                for (int idx = l; idx <= r; idx += k) {
                    mult[idx] = (mult[idx] * v) % MOD;
                }
            }
        }

        // process small k in compressed form
        for (int k = 1; k <= B; ++k) {
            for (int rem = 0; rem < k; ++rem) {
                auto &vec = bucket[k][rem];
                if (vec.empty()) continue;

                int m = (n - 1 - rem) / k + 1;   // number of indices: rem, rem+k, ...
                vector<long long> diff(m + 1, 1);

                for (auto &qq : vec) {
                    int L = (qq.l - rem) / k;
                    int R = (qq.r - rem) / k;

                    diff[L] = (diff[L] * qq.v) % MOD;
                    diff[R + 1] = (diff[R + 1] * modPow(qq.v, MOD - 2)) % MOD;
                }

                long long cur = 1;
                int idx = rem;
                for (int i = 0; i < m; ++i, idx += k) {
                    cur = (cur * diff[i]) % MOD;
                    mult[idx] = (mult[idx] * cur) % MOD;
                }
            }
        }

        int ans = 0;
        for (int i = 0; i < n; ++i) {
            ans ^= (int)(1LL * nums[i] * mult[i] % MOD);
        }
        return ans;
    }
};