#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> dis(n + 1, 1e5);
    vector<int> cnt(n + 1, 0);
    for (int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        dis[x] = min(dis[x], (y - x + n) % n);
        cnt[x]++;
    }
    for (int i = 1; i <= n; i++) {
        int ans = 0;
        for (int j = 1; j <= n; j++) {
            if (!cnt[j]) continue;
            ans = max(ans, (cnt[j] - 1) * n + dis[j] + (j - i + n) % n);
        }
        cout << ans << " \n"[i == n];
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