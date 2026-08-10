class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {

        vector<int> x = score;
        sort(x.begin(), x.end(), greater<int>());

        vector<string> ans(score.size());

        map<int, string> m;

        for(int i = 0; i < x.size(); i++)
        {
            if(i == 0)
                m[x[i]] = "Gold Medal";
            else if(i == 1)
                m[x[i]] = "Silver Medal";
            else if(i == 2)
                m[x[i]] = "Bronze Medal";
            else
                m[x[i]] = to_string(i + 1);
        }

        for(int i = 0; i < score.size(); i++)
        {
            ans[i] = m[score[i]];
        }

        return ans;
    }
};