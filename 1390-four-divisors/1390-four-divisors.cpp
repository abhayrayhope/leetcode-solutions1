class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {

        int ans = 0;

        for (int num : nums) {

            int count = 0;
            int sum = 0;

            for (int i = 1; i * i <= num; i++) {

                if (num % i == 0) {

                    int d = num / i;

                    if (i == d) {
                        count++;
                        sum += i;
                    } else {
                        count += 2;
                        sum += i + d;
                    }

                    if (count > 4)
                        break;
                }
            }

            if (count == 4)
                ans += sum;
        }

        return ans;
    }
};