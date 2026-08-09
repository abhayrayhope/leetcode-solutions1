class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {

        vector<int> ans(temperatures.size(), 0);
        stack<int> st;

        for(int i = 0; i < temperatures.size(); i++)
        {
            while(!st.empty() && temperatures[i] > temperatures[st.top()])
            {
                int x = st.top();
                st.pop();

                ans[x] = i - x;
            }

            st.push(i);
        }

        return ans;
    }
};