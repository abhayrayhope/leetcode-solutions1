class Solution {
public:
    int distinctSubseqII(string s) {
        const int MOD = 1e9 + 7;
        vector<long long> dp(26, 0);

        long long total = 0;

        for(char c : s)
        {
            int x = c - 'a';

            long long newSub = (total + 1) % MOD;

            total = (total + newSub - dp[x] + MOD) % MOD;

            dp[x] = newSub;
        }

        return total;
    }
};