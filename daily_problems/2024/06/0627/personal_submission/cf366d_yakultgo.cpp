#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
struct node {
    int u, v, l, r;
    bool operator<(const node& other) const {
        if (l != other.l)
            return r < other.r;
        return l < other.l;
    }
};
struct dsu {
    vector<int> pa, size;
    explicit dsu(int size_) : pa(size_), size(size_, 1) {
        iota(pa.begin(), pa.end(), 0);
    }
    void unite(int x, int y) {
        x = find(x), y = find(y);
        if (x == y) return;
        if (size[x] < size[y]) swap(x, y);
        pa[y] = x;
        size[x] += size[y];
    }
    int find(int x) {
        return pa[x] == x ? x : pa[x] = find(pa[x]);
    }
};
void solve() {
    int n, m;
    cin >> n >> m;
    vector<node> a(m);
    for (int i = 0; i < m; i++) {
        cin >> a[i].u >> a[i].v >> a[i].l >> a[i].r;
        a[i].u--, a[i].v--;
    }
    sort(a.begin(), a.end());
    auto check = [&](int x, int y) {
        dsu d(n);
        for (int i = 0; i < m; i++) {
            if (a[i].l <= x && y <= a[i].r) {
                d.unite(a[i].u, a[i].v);
            }
        }
        return d.find(0) == d.find(n - 1);
    };
    int ans = 0;
    for (int i = 0; i < m; i++) {
        int L = a[i].l;
        int left = L, right = 1e6 + 1;
        while (left < right) {
            int mid = (left + right) / 2;
            if (check(L, mid))
                left = mid + 1;
            else
                right = mid;
        }
        int R = left - 1;
        ans = max(ans, R - L + 1);
    }
    if (ans == 0)
        cout << "Nice work, Dima!";
    else
        cout << ans << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T = 1;
    while (T--) {
        solve();
    }
    return 0;
}