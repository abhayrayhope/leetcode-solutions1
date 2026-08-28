class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {
        vector<int> cnt(26);

        for (char c : s)
            cnt[c - 'a']++;

        int odd = 0;
        char mid = 0;

        for (int i = 0; i < 26; i++) {
            if (cnt[i] % 2) {
                odd++;
                mid = 'a' + i;
            }
        }

        if (odd > 1)
            return "";

        vector<int> half(26);

        for (int i = 0; i < 26; i++)
            half[i] = cnt[i] / 2;

        string left;
        int halfLen = s.size() / 2;

        for (int pos = 0; pos < halfLen; pos++) {
            bool found = false;

            for (int c = 0; c < 26; c++) {
                if (half[c] == 0)
                    continue;

                half[c]--;
                left.push_back('a' + c);

                string temp = left;

                for (int j = 25; j >= 0; j--)
                    temp += string(half[j], 'a' + j);

                string palindrome = temp;

                if (s.size() % 2)
                    palindrome += mid;

                string rev = temp;
                reverse(rev.begin(), rev.end());
                palindrome += rev;

                if (palindrome > target) {
                    found = true;
                    break;
                }

                left.pop_back();
                half[c]++;
            }

            if (!found)
                return "";
        }

        string ans = left;

        if (s.size() % 2)
            ans += mid;

        string rev = left;
        reverse(rev.begin(), rev.end());
        ans += rev;

        return ans > target ? ans : "";
    }
};