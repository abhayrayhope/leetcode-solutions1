class Solution {
public:
    bool uniformArray(vector<int>& nums) {
        int mn = nums[0];
        bool odd = false;

        for (int x : nums) {
            mn = min(mn, x);

            if (x % 2 != 0)
                odd = true;
        }

        if (mn % 2 != 0)
            return true;

        if (odd)
            return false;

        return true;
    }
};