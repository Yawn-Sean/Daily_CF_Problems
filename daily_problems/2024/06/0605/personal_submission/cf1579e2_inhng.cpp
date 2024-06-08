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
    int N;
    
    Tree() {}
    Tree(int n) {
        tree.resize(n + 11);
        N = n + 10;
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
};

void solve() {
    int n, ans = 0;
    cin >> n;
    Tree tree(n);
    vector<int> a(n);
    for (int &ai : a) {
        cin >> ai;
    }
    vector<int> b(a);
    ranges::sort(b);
    b.erase(unique(b.begin(), b.end()), b.end());
    map<int, int> idx;
    for (int i = 0; i < b.size(); ++i) {
        idx[b[i]] = i + 1;
    }
    for (int i = 0; i < n; ++i) {
        ans += min(tree.query(idx[a[i]] - 1), tree.query(n) - tree.query(idx[a[i]]));
        tree.update(idx[a[i]], 1);
    }
    cout << ans << endl;
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(15);
    time_t begin = clock();
    int Test; cin >> Test; while (Test--)
    solve();
    time_t end = clock();
    double solve_time = double(end - begin) / CLOCKS_PER_SEC;
    // cout << "runtime: " << solve_time << endl;
    return 0;
}
