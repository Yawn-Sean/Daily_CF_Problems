#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
#define int long long
void solve() {
    int n, m;
    cin >> n >> m;
    struct node {
        int f, s;
        int id;
        bool operator<(const node &x) const {
            return f - s < x.f - x.s;
        }
    };
    vector<node> a(n);
    vector<pair<int, int>> b(n);
    int sum1 = 0, sum2 = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i].f >> a[i].s;
        b[i] = {a[i].f, a[i].s};
        a[i].id = i;
        sum2 += a[i].s;
    }
    sort(a.begin(), a.end());
    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
        sum2 -= a[i].s;
        ans[a[i].id] = sum1 + a[i].s * i + a[i].f * (n - i - 1) + sum2;
        sum1 += a[i].f;
    }
    while (m--) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        int tmp = min(b[x].first + b[y].second, b[x].second + b[y].first);
        ans[x] -= tmp;
        ans[y] -= tmp;
    }
    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T = 1;
    while (T--) {
        solve();
    }
    return 0;
}