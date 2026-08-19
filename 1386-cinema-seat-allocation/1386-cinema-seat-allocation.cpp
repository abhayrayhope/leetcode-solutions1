class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, int> mp;

        for (auto x : reservedSeats) {
            int row = x[0];
            int seat = x[1];

            mp[row] |= (1 << (seat - 1));
        }

        int ans = (n - mp.size()) * 2;

        for (auto [row, seats] : mp) {

            bool left = (seats & (1 << 1)) ||
                        (seats & (1 << 2)) ||
                        (seats & (1 << 3)) ||
                        (seats & (1 << 4));

            bool middle = (seats & (1 << 3)) ||
                          (seats & (1 << 4)) ||
                          (seats & (1 << 5)) ||
                          (seats & (1 << 6));

            bool right = (seats & (1 << 5)) ||
                         (seats & (1 << 6)) ||
                         (seats & (1 << 7)) ||
                         (seats & (1 << 8));

            if (!left && !right)
                ans += 2;
            else if (!left || !middle || !right)
                ans += 1;
        }

        return ans;
    }
};