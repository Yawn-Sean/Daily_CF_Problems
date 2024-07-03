#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> v(m);
    int ans = 1e6;
    for (int i = 0; i < m; i++) {
        cin >> v[i].first >> v[i].second;
        ans = min(ans, v[i].second - v[i].first + 1);
    }
    cout << ans << endl;
    for (int i = 0; i < n; i++) {
        cout << i % ans << " ";
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