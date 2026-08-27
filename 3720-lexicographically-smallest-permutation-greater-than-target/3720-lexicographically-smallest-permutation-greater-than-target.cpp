class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.size();
        vector<int> cnt(26, 0);

        for (char c : s)
            cnt[c - 'a']++;

        int pos = -1;
        int bigger = -1;
        vector<int> saved;

        for (int i = 0; i < n; i++) {
            int x = target[i] - 'a';

            for (int c = x + 1; c < 26; c++) {
                if (cnt[c] > 0) {
                    pos = i;
                    bigger = c;
                    saved = cnt;
                    break;
                }
            }

            if (cnt[x] == 0)
                break;

            cnt[x]--;
        }

        if (pos == -1)
            return "";

        string ans = target.substr(0, pos);

        ans += char('a' + bigger);
        saved[bigger]--;

        for (int c = 0; c < 26; c++) {
            while (saved[c] > 0) {
                ans += char('a' + c);
                saved[c]--;
            }
        }

        return ans;
    }
};