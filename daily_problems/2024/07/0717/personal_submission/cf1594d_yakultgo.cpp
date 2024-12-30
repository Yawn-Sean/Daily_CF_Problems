#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> fa(2 * n + 1), sz(2 * n + 1);
    for (int i = 1; i <= 2 * n; i++) {
        fa[i] = i;
        sz[i] = i <= n ? 1 : 0;
    }
    function<int(int)> find = [&](int x) {
        if (fa[x] == x) return x;
        fa[x] = find(fa[x]);
        sz[fa[x]] += sz[x];
        sz[x] = 0;
        return fa[x];
    };
    function<void(int, int)> merge = [&](int x, int y) {
        int fx = find(x), fy = find(y);
        if (fx != fy) {
            fa[fx] = fy;
            sz[fy] += sz[fx];
            sz[fx] = 0;
        }
    };
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        string s;
        cin >> s;
        if (s == "crewmate") {
            merge(u, v);
            merge(u + n, v + n);
        } else {
            merge(u + n, v);
            merge(u, v + n);
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (find(i) == find(i + n)) {
            ans = -1;
            break;
        }
        ans += max(sz[find(i)], sz[find(i + n)]);
        sz[find(i)] = sz[find(i + n)] = 0;
    }
    cout << ans << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}