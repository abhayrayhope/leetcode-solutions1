class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        map<int, int> mp;

        for (int x : nums)
            mp[x]++;

        if (k == 1) {
            int ans = -1;
            for (auto p : mp) {
                if (p.second == 1)
                    ans = max(ans, p.first);
            }
            return ans;
        }

        if (k == n)
            return *max_element(nums.begin(), nums.end());

        int ans = -1;

        if (mp[nums[0]] == 1)
            ans = max(ans, nums[0]);

        if (mp[nums[n - 1]] == 1)
            ans = max(ans, nums[n - 1]);

        return ans;
    }
};