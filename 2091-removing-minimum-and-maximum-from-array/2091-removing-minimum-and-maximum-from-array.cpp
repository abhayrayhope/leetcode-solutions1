class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        auto mx = max_element(nums.begin(), nums.end());
        auto mi = min_element(nums.begin(), nums.end());

        int p1, p2;
        int l = nums.size();

        for (int i = 0; i < l; i++) {
            if (nums[i] == *mx) {
                p1 = i + 1;
            }

            if (nums[i] == *mi) {
                p2 = i + 1;
            }
        }

        int front = max(p1, p2);

        int back = max(l - p1 + 1, l - p2 + 1);

        int both;

        if (p1 < p2) {
            both = p1 + (l - p2 + 1);
        } else {
            both = p2 + (l - p1 + 1);
        }

        return min({front, back, both});
    }
};