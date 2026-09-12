class Solution {
public:

    struct Node {
        int l, r, w, idx;
    };

    vector<Node> a;
    vector<vector<pair<long long, vector<int>>>> dp;

    pair<long long, vector<int>> solve(int i, int k) {

        if (i >= a.size() || k == 0)
            return {0, {}};

        if (dp[i][k].first != -1)
            return dp[i][k];

        auto skip = solve(i + 1, k);

        int lo = i + 1;
        int hi = a.size();

        while (lo < hi) {
            int mid = (lo + hi) / 2;

            if (a[mid].l > a[i].r)
                hi = mid;
            else
                lo = mid + 1;
        }

        auto take = solve(lo, k - 1);

        take.first += a[i].w;
        take.second.push_back(a[i].idx);

        sort(take.second.begin(), take.second.end());
        sort(skip.second.begin(), skip.second.end());

        if (take.first > skip.first)
            return dp[i][k] = take;

        if (take.first < skip.first)
            return dp[i][k] = skip;

        return dp[i][k] = min(take, skip);
    }

    vector<int> maximumWeight(vector<vector<int>>& intervals) {

        int n = intervals.size();

        a.resize(n);

        for (int i = 0; i < n; i++) {
            a[i] = {
                intervals[i][0],
                intervals[i][1],
                intervals[i][2],
                i
            };
        }

        sort(a.begin(), a.end(), [](Node& x, Node& y) {
            return x.l < y.l;
        });

        dp.assign(n, vector<pair<long long, vector<int>>>(5, {-1, {}}));

        return solve(0, 4).second;
    }
};