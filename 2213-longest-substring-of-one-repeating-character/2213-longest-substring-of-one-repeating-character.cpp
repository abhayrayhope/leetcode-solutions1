class Solution {
public:
    struct Node {
        int l, r;
        int lmx, rmx, mx;

        Node() {}

        Node(int _l, int _r) {
            l = _l;
            r = _r;
            lmx = rmx = mx = 1;
        }
    };

    vector<Node> tree;
    string s;

    void build(int u, int l, int r) {
        tree[u] = Node(l, r);

        if (l == r)
            return;

        int mid = (l + r) / 2;

        build(u * 2, l, mid);
        build(u * 2 + 1, mid + 1, r);

        pushup(u);
    }

    void pushup(int u) {
        Node &root = tree[u];
        Node &left = tree[u * 2];
        Node &right = tree[u * 2 + 1];

        root.mx = max(left.mx, right.mx);
        root.lmx = left.lmx;
        root.rmx = right.rmx;

        if (s[left.r - 1] == s[right.l - 1]) {
            int leftLength = left.r - left.l + 1;
            int rightLength = right.r - right.l + 1;

            if (left.lmx == leftLength)
                root.lmx += right.lmx;

            if (right.rmx == rightLength)
                root.rmx += left.rmx;

            root.mx = max(root.mx, left.rmx + right.lmx);
        }
    }

    void update(int u, int pos, char c) {
        if (tree[u].l == tree[u].r) {
            s[pos - 1] = c;
            tree[u].lmx = 1;
            tree[u].rmx = 1;
            tree[u].mx = 1;
            return;
        }

        int mid = (tree[u].l + tree[u].r) / 2;

        if (pos <= mid)
            update(u * 2, pos, c);
        else
            update(u * 2 + 1, pos, c);

        pushup(u);
    }

    vector<int> longestRepeating(
        string s,
        string queryCharacters,
        vector<int>& queryIndices
    ) {
        this->s = s;

        int n = s.size();

        tree.resize(4 * n + 5);

        build(1, 1, n);

        vector<int> ans;

        for (int i = 0; i < queryIndices.size(); i++) {
            int pos = queryIndices[i] + 1;
            char c = queryCharacters[i];

            update(1, pos, c);

            ans.push_back(tree[1].mx);
        }

        return ans;
    }
};