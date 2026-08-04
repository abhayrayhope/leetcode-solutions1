class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {

        sort(nums.begin(), nums.end());

        auto M = max_element(nums.begin(), nums.end());
        auto m = min_element(nums.begin(), nums.end());

        vector<int> ans;

        int x = *m;
        int i = 0;

        while (x <= *M && i < nums.size()) {

            if (nums[i] == x) {
                x++;
                i++;
            }
            else if (nums[i] > x) {
                ans.push_back(x);
                x++;
            }
            else {              
                i++;
            }
        }

        return ans;
    }
};