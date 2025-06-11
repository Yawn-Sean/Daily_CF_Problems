#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int mod = 1000000007;
constexpr int inf = 0x3f3f3f3f;
constexpr ll linf = 0x3f3f3f3f3f3f3f3f;

void solve() {
    int n;
    cin >> n;
    set<int> val;
    val.insert(1); val.insert(n+1);
    vector<vector<int>> qu;
    vector<vector<int>> res;
    int k = 0;
    do {
        auto p = val.begin(), q = next(p);
        while (q != val.end()) {
            val.insert(*p + (*q - *p) / 2);
            p = q;
            q = next(q);
        }
        p = val.begin(), q = next(p);
        int v = 0;
        qu.push_back(vector<int>(n+1));
        array<int, 2> cnt = {0};
        while (q != val.end()) {
            for (int i = *p; i < *q; ++i) qu[k][i] = v;
            cnt[v] += *q - *p;
            v = !v; p = q; q = next(q);
        }
        for (int j = 0; j <= 1; ++j) {
            cout << cnt[j] << endl;
            for (int i = 1; i <= n; ++i) if (qu[k][i] == j) cout << i << ' ';
            cout << endl;
            res.push_back(vector<int>(n+1));
            for (int i = 1; i <= n; ++i) cin >> res[k*2+j][i];
        }
        ++k;
    } while (val.size() <= n);
    cout << "-1\n";
    for (int i = 1; i <= n; ++i) {
        int ans = inf;
        for (int j = 0; j < k; ++j) ans = min(ans, res[j*2+!qu[j][i]][i]);
        cout << ans << " ";
    }
    cout << endl;
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
