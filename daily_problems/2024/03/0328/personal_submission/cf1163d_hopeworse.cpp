struct AC {
    struct node {
        vector<int> child;
        int fail{};
        int sums{};
        node() {
            child.resize(26);
            fail = 0, sums = 0;
        }
    };
    vector<node> tree;
    int tot = 2;
    explicit AC(int n) : tree(n) {
        tot = 2;
        ranges::fill(tree[0].child, 1);
    }

    void insert(string&s,int k) {
        int now = 1;
        for (auto j: s) {
            int i = j - 'a';
            if (!tree[now].child[i]) {
                tree[now].child[i] = tot++;
            }
            now = tree[now].child[i];
        }
        tree[now].sums += k;
    }

    void build() {
        queue<int> q;
        q.emplace(1);
        vector<int> ans;
        while (!q.empty()) {
            auto t = q.front();
            ans.emplace_back(t);
            q.pop();
            int fail = tree[t].fail;
            for (int i = 0; i < 26; i++) {
                if (!tree[t].child[i]) {
                    tree[t].child[i] = tree[fail].child[i];
                }
                else {
                    int next = tree[t].child[i];
                    tree[next].fail = tree[fail].child[i];
                    q.emplace(next);
                }
            }
        }
        for (auto i: ans) {
            tree[i].sums += tree[tree[i].fail].sums;
        }
    }

    int rundp(string&s) {
        int n = s.length();
        vector f(n + 10, vector(tot + 10, -inf));
        f[0][1] = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < tot; j++) {
                if (f[i][j] != -inf) {
                    for (int k = 0; k < 26; k++) {
                        if (k + 'a' == s[i] || s[i] == '*') {
                            int to = tree[j].child[k];
                            f[i + 1][to] = max(f[i + 1][to], f[i][j] + tree[to].sums);
                        }
                    }
                }
            }
        }
        int maxs = -inf;
        for (int i = 0; i < tot; i++) {
            maxs = max(f[n][i], maxs);
        }
        return maxs;
    }
};


void solve() {
    AC a(1000);
    string s, s1, s2;
    cin >> s >> s1 >> s2;
    a.insert(s1, 1);
    a.insert(s2, -1);
    a.build();
    int ans = a.rundp(s);
    cout << ans << endl;
}
