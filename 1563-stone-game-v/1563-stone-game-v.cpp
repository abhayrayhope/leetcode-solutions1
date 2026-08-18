class Solution {
public:
    int dp[501][501];

    int solve(vector<int>& a, vector<int>& pre, int l, int r) {
        if (l == r)
            return 0;

        if (dp[l][r] != -1)
            return dp[l][r];

        int ans = 0;

        for (int k = l; k < r; k++) {
            int left = pre[k + 1] - pre[l];
            int right = pre[r + 1] - pre[k + 1];

            if (left < right)
                ans = max(ans, left + solve(a, pre, l, k));

            else if (left > right)
                ans = max(ans, right + solve(a, pre, k + 1, r));

            else
                ans = max(ans, max(
                    left + solve(a, pre, l, k),
                    right + solve(a, pre, k + 1, r)
                ));
        }

        return dp[l][r] = ans;
    }

    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();

        vector<int> pre(n + 1, 0);

        for (int i = 0; i < n; i++)
            pre[i + 1] = pre[i] + stoneValue[i];

        memset(dp, -1, sizeof(dp));

        return solve(stoneValue, pre, 0, n - 1);
    }
};