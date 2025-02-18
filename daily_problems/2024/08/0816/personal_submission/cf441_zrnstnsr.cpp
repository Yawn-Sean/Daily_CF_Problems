#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int mod = 1000000007;
constexpr int inf = 0x3f3f3f3f;

#define Fa(x) find(find, x)

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1), fa(n+1);
    int tot = 0;
    
    iota(fa.begin(), fa.end(), 0);
    auto find = [&](auto &&self, int u) -> int { return fa[u] == u ? fa[u] : fa[u] = self(self, fa[u]); };
    auto merge = [&](int u, int v) { u = Fa(u); v = Fa(v); if (u < v) swap(u, v); if (u != v) fa[u] = v, ++tot; };

    for (int i = 1; i <= n; ++i) cin >> a[i], merge(i, a[i]);
    int m; cin >> m;
    if (tot < m) {
        cout << m - tot << '\n';
        for (int i = 2; i <= n && tot < m; ++i) if (Fa(1) != Fa(i)) {
            merge(1, i); cout << "1 " << i << ' ';
        }
    } else if (tot > m) {
        int k = tot - m;
        cout << k << '\n';
        while (k--) {
            for (int i = 1; i <= n; ++i) if (a[i] != i) {
                int u = a[i], v = a[i];
                while ((u = a[u]) != i) v = min(v, u);
                swap(a[i], a[v]);
                cout << i << ' ' << v << ' ';
                break;
            }
        }
    } else cout << "0";
    end: cout << '\n';
}

int main() {
    int T;
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // cin >> T;
    T = 1;
    while (T--) {
        solve();
    }
    return 0;
}
