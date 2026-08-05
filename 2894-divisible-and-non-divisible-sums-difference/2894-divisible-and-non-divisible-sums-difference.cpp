class Solution {
public:
    int differenceOfSums(int n, int m) {

        int total = n * (n + 1) / 2;

        int c = n / m;

        int d = m * c * (c + 1) / 2;

        return total - 2 * d;
    }
};