#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    const unordered_map<int, vector<int>> kFactorCounts = {
        {1, {}}, {2, {2}}, {3, {3}}, {4, {2, 2}}, {5, {5}},
        {6, {2, 3}}, {7, {7}}, {8, {2, 2, 2}}, {9, {3, 3}}
    };

    pair<unordered_map<int, int>, bool> getPrimeCount(long long t) {
        unordered_map<int, int> count = {{2, 0}, {3, 0}, {5, 0}, {7, 0}};
        for (const int prime : {2, 3, 5, 7}) {
            while (t % prime == 0) {
                t /= prime;
                ++count[prime];
            }
        }
        return {count, t == 1};
    }

    unordered_map<int, int> getFactorCount(unordered_map<int, int> primeCount) {
        int rem2 = primeCount[2];
        int rem3 = primeCount[3];
        int count8 = rem2 / 3;
        rem2 %= 3;
        int count9 = rem3 / 2;
        rem3 %= 2;
        int count4 = rem2 / 2;
        rem2 %= 2;
        int count6 = 0;
        if (rem2 == 1 && rem3 == 1) {
            rem2 = 0;
            rem3 = 0;
            count6 = 1;
        }
        if (rem3 == 1 && count4 == 1) {
            rem2 = 1;
            count6 = 1;
            rem3 = 0;
            count4 = 0;
        }
        return {
            {2, rem2}, {3, rem3}, {4, count4}, {5, primeCount[5]},
            {6, count6}, {7, primeCount[7]}, {8, count8}, {9, count9}
        };
    }

    int sumValues(const unordered_map<int, int>& count) {
        int sum = 0;
        for (const auto& [key, value] : count) sum += value;
        return sum;
    }

    unordered_map<int, int> getPrimeCount(const string& s) {
        unordered_map<int, int> count = {{2, 0}, {3, 0}, {5, 0}, {7, 0}};
        for (char c : s) {
            int d = c - '0';
            for (int prime : {2, 3, 5, 7}) {
                while (d > 0 && d % prime == 0) {
                    d /= prime;
                    ++count[prime];
                }
            }
        }
        return count;
    }

    unordered_map<int, int> subtract(unordered_map<int, int> a, const unordered_map<int, int>& b) {
        for (const auto& [key, value] : b) {
            a[key] = max(0, a[key] - value);
        }
        return a;
    }

    bool isSubset(const unordered_map<int, int>& a, const unordered_map<int, int>& b) {
        for (const auto& [key, value] : a) {
            if (b.at(key) < value) return false;
        }
        return true;
    }

    string construct(const unordered_map<int, int>& factorCount) {
        string s = "";
        for (int d = 2; d <= 9; ++d) {
            auto it = factorCount.find(d);
            if (it != factorCount.end()) {
                s += string(it->second, '0' + d);
            }
        }
        return s;
    }

public:
    string smallestNumber(string num, long long t) {
        auto [primeCount, isDivisible] = getPrimeCount(t);
        if (!isDivisible) return "-1";

        auto factorCount = getFactorCount(primeCount);
        if (sumValues(factorCount) > num.length()) {
            return construct(factorCount);
        }

        auto primeCountPrefix = getPrimeCount(num);
        int firstZeroIndex = num.find('0');
        if (firstZeroIndex == string::npos) {
            firstZeroIndex = num.length();
            if (isSubset(primeCount, primeCountPrefix)) return num;
        }

        for (int i = num.length() - 1; i >= 0; --i) {
            int d = num[i] - '0';
            for (int prime : {2, 3, 5, 7}) {
                int temp = d;
                while (temp > 0 && temp % prime == 0) {
                    temp /= prime;
                    primeCountPrefix[prime]--;
                }
            }

            int spaceAfterThisDigit = num.length() - 1 - i;
            if (i > firstZeroIndex) continue;

            for (int biggerDigit = d + 1; biggerDigit < 10; ++biggerDigit) {
                unordered_map<int, int> digitFactors = {{2, 0}, {3, 0}, {5, 0}, {7, 0}};
                int temp = biggerDigit;
                for (int prime : {2, 3, 5, 7}) {
                    while (temp > 0 && temp % prime == 0) {
                        temp /= prime;
                        digitFactors[prime]++;
                    }
                }

                auto needed = subtract(primeCount, primeCountPrefix);
                needed = subtract(needed, digitFactors);
                auto factorsAfterReplacement = getFactorCount(needed);

                if (sumValues(factorsAfterReplacement) <= spaceAfterThisDigit) {
                    int fillOnes = spaceAfterThisDigit - sumValues(factorsAfterReplacement);
                    string suffix = construct(factorsAfterReplacement);
                    suffix = string(fillOnes, '1') + suffix;
                    return num.substr(0, i) + to_string(biggerDigit) + suffix;
                }
            }
        }

        int length = num.length() + 1;
        auto factors = getFactorCount(primeCount);
        int fillOnes = length - sumValues(factors);
        return string(fillOnes, '1') + construct(factors);
    }
};