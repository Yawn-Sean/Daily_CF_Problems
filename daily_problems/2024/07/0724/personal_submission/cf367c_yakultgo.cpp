#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> a(m);
    for (int i = 0; i < m; i++) {
        cin >> a[i].first >> a[i].second;
    }
    sort(a.begin(), a.end(), [](pair<int, int> x, pair<int, int> y) {
        return x.second > y.second;
    });
    int ans = 0;
    for (int i = 1; i <= m; i++) {
        ll sum = 1ll * (i - 1) * i / 2;
        if (i % 2 == 0) {
            sum += (i - 2) / 2;
        }
        sum++;
        if (sum > n) {
            break;
        }
        ans += a[i - 1].second;
    }
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