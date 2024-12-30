#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;

void solve() {
    int n, d;
    cin >> n >> d;
    vector<int> fa(n + 1);
    iota(fa.begin(), fa.end(), 0);
    vector<int> sz(n + 1, 1);
    function<int(int)> find = [&](int x) {
        return fa[x] == x ? x : fa[x] = find(fa[x]);
    };
    function<void(int, int)> merge = [&](int x, int y) {
        int fx = find(x), fy = find(y);
        if (fx == fy) return;
        if (sz[fx] < sz[fy])
            swap(fx, fy);
        fa[fy] = fx;
        sz[fx] += sz[fy];
    };
    int cnt = 0;
    for (int i = 0; i < d; i++) {
        int x, y;
        cin >> x >> y;
        if (find(x) == find(y)) {
            cnt++;
        } else {
            merge(x, y);
        }
        int ans = 0;
        vector<int> tmp;
        for (int i = 1; i <= n; i++) {
            if (fa[i] == i) {
                tmp.push_back(sz[i]);
            }
        }
        sort(tmp.begin(), tmp.end(), greater<int>());
        for (int i = 0; i < min((int)tmp.size(), cnt + 1); i++)
            ans += tmp[i];
        cout << ans - 1 << endl;
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