#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> g[n + 1];
    int prime = 1e5 + 3;
    g[1].push_back({2, prime - (n - 2)});
    for (int i = 2; i < n; i++) {
        g[i].push_back({i + 1, 1});
    }
    m -= n - 1;
    while (true) {
        for (int i = 1; i <= n; i++) {
            if (m == 0) break;
            for (int j = i + 2; j <= n; j++) {
                if (m == 0) break;
                g[i].push_back({j, 1e6});
                m--;
            }
        }
        if (m == 0) break;
    }
    cout << prime << " " << prime << endl;
    for (int i = 1; i <= n; i++) {
        for (auto &x : g[i]) {
            cout << i << " " << x.first << " " << x.second << endl;
        }
    }
    return;
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