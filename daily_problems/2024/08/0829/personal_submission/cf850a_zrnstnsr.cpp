#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int mod = 998244353;
constexpr int inf = 0x3f3f3f3f;
constexpr ll linf = 0x3f3f3f3f3f3f3f3f;

void solve() {
    int n;
    cin >> n;
    if (n == 2) { println("2\n1\n2"); return; }
    else if (n > 11) { println("0"); return; }
    vector<vector<int>> a(n, vector<int>(5));
    for (int i = 0; i < n; ++i) for (int j = 0; j < 5; ++j) cin >> a[i][j];
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int suc = true;
        for (int j = 0; j < n && suc; ++j) if (j != i)
            for (int k = 0; k < n && suc; ++k) if (k != i && k != j) {
                int dot = 0;
                for (int x = 0; x < 5; ++x) dot += (a[j][x] - a[i][x]) * (a[k][x] - a[i][x]);
                if (dot > 0) suc = false;
            }
        if (suc) { ans = i + 1; break; }
    }
    if (ans) println("1\n{}", ans);
    else println("0");
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
