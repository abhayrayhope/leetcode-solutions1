class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {

        int sum = 0;

        for (int i = 0; i < nums.size(); i++) {

            int x = nums[i];
            int c = 0;
            int s = 0;

            for (int y = 1; y * y <= x; y++) {

                if (x % y == 0) {

                    int d = x / y;

                    if (y == d) {      
                        c++;
                        s += y;
                    } else {
                        c += 2;
                        s += y + d;
                    }

                    if (c > 4)
                        break;
                }
            }

            if (c == 4)
                sum += s;
        }

        return sum;
    }
};