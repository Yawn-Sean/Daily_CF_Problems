#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
struct dsu {
    vector<int> pa, end, nex;
    explicit dsu(int size_) : pa(size_), end(size_), nex(size_, -1) {
        iota(pa.begin(), pa.end(), 0);
        iota(end.begin(), end.end(), 0);
    }
    void unite(int x, int y) {
        x = find(x), y = find(y);
        if (x == y) return;
        pa[y] = x;
        nex[end[x]] = y;
        end[x] = end[y];
    }
    int find(int x) {
        return pa[x] == x ? x : pa[x] = find(pa[x]);
    }
};
void solve() {
    int n;
    cin >> n;
    dsu d(n);
    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        d.unite(x, y);
    }
    vector<int> ans = {d.find(0)};
    for (int i = 0; i < n - 1; i++) {
        ans.push_back(d.nex[ans.back()]);
    }
    for (int i = 0; i < n; i++) {
        cout << ans[i] + 1 << " \n"[i == n - 1];
    }
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