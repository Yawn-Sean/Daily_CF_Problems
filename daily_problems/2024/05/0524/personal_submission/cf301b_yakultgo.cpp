#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;

void solve() {
    int n, d;
    cin >> n >> d;
    vector<int> a(n + 1);
    for (int i = 2; i <= n - 1; i++) cin >> a[i];
    vector<pair<int, int>> p(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> p[i].first >> p[i].second;
    }
    vector<vector<ll>> dist(n + 1, vector<ll>(n + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            dist[i][j] = 1ll * (abs(p[i].first - p[j].first) + abs(p[i].second - p[j].second)) * d - a[j];
            dist[j][i] = 1ll * (abs(p[i].first - p[j].first) + abs(p[i].second - p[j].second)) * d - a[i];
        }
    }
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    cout << dist[1][n] << endl;
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