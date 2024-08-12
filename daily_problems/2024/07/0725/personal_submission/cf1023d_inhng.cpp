#include <bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define endl '\n'
#define int long long
#define lowbit(x) x & -x
#define PII pair<int, int>
#define PIII pair<int, PII>

const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7; // 998244353;

struct Tree {
    vector<int> tree;
    
    Tree() {}
    Tree(int n) {
        tree.resize(n + 10);
    }
    
    void update(int i, int x) {
        while (i < tree.size()) {
            tree[i] += x;
            i += lowbit(i);
        }
    }
    
    int query(int i) {
        int ans = 0;
        while (i) {
            ans += tree[i];
            i -= lowbit(i);
        }
        return ans;
    }

    int sum(int left, int right) {
        return query(right) - query(left);
    }
};

void solve() {
    int n, q, zero_idx = -1, last = 1, mx = 0;
    cin >> n >> q;
    vector<int> a(n + 1);
    vector<vector<int>> idx(q + 1);
    Tree tree(n);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        idx[a[i]].emplace_back(i);
        mx = max(mx, a[i]);
        if (a[i] == 0) {
            a[i] = last;
            zero_idx = i;
        } else {
            last = a[i];
        }
    }
    if (mx < q) {
        if (zero_idx != -1) {
            a[zero_idx] = q;
        } else {
            cout << "NO";
            return;
        }
    }
    for (int i = 1; i <= q; ++i) {
        if (idx[i].empty()) {
            continue;
        }
        if (tree.sum(idx[i][0] - 1, idx[i].back())) { // 有更小的数出现在中间
            cout << "NO";
            return;
        }
        for (int i : idx[i]) {
            tree.update(i, 1);
        }
    }
    a.erase(a.begin());
    cout << "YES" << endl;
    for (int ai : a) {
        cout << ai << " ";
    }
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
    return 0;
}
