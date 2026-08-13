class Solution {
public:
    struct Node {
        int len;      // length of this segment
        int pre;      // longest run of same char starting from left
        int suf;      // longest run of same char ending at right
        int best;      // best answer in this segment
        char leftCh, rightCh;
    };

    vector<Node> tree;
    string s;
    int n;

    Node merge(const Node& l, const Node& r) {
        Node res;
        res.len = l.len + r.len;
        res.leftCh = l.leftCh;
        res.rightCh = r.rightCh;
        res.best = max(l.best, r.best);

        res.pre = l.pre;
        if (l.pre == l.len && l.rightCh == r.leftCh)
            res.pre = l.len + r.pre;

        res.suf = r.suf;
        if (r.suf == r.len && l.rightCh == r.leftCh)
            res.suf = r.len + l.suf;

        if (l.rightCh == r.leftCh)
            res.best = max(res.best, l.suf + r.pre);

        return res;
    }

    void build(int node, int start, int end) {
        if (start == end) {
            tree[node] = {1, 1, 1, 1, s[start], s[start]};
            return;
        }
        int mid = (start + end) / 2;
        build(2*node, start, mid);
        build(2*node+1, mid+1, end);
        tree[node] = merge(tree[2*node], tree[2*node+1]);
    }

    void update(int node, int start, int end, int idx, char val) {
        if (start == end) {
            tree[node] = {1, 1, 1, 1, val, val};
            return;
        }
        int mid = (start + end) / 2;
        if (idx <= mid) update(2*node, start, mid, idx, val);
        else update(2*node+1, mid+1, end, idx, val);
        tree[node] = merge(tree[2*node], tree[2*node+1]);
    }

    vector<int> longestRepeating(string s_, string queryCharacters, vector<int>& queryIndices) {
        s = s_;
        n = s.size();
        tree.resize(4 * n);
        build(1, 0, n-1);

        int q = queryIndices.size();
        vector<int> ans(q);

        for (int i = 0; i < q; i++) {
            s[queryIndices[i]] = queryCharacters[i];
            update(1, 0, n-1, queryIndices[i], queryCharacters[i]);
            ans[i] = tree[1].best;
        }
        return ans;
    }
};