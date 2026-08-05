class Solution {
public:
    void dfs(int node, vector<vector<int>>& graph, vector<int>& vis)
    {
        vis[node] = 1;

        for (int next : graph[node])
        {
            if (vis[next] == 0)
            {
                dfs(next, graph, vis);
            }
        }
    }

    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {

        vector<vector<int>> graph(n);

        for (auto x : invocations)
        {
            graph[x[0]].push_back(x[1]);
        }

        vector<int> vis(n, 0);

        dfs(k, graph, vis);

        for (auto x : invocations)
        {
            int u = x[0];
            int v = x[1];

            if (vis[u] == 0 && vis[v] == 1)
            {
                vector<int> ans;

                for (int i = 0; i < n; i++)
                {
                    ans.push_back(i);
                }

                return ans;
            }
        }

        vector<int> ans;

        for (int i = 0; i < n; i++)
        {
            if (vis[i] == 0)
            {
                ans.push_back(i);
            }
        }

        return ans;
    }
};