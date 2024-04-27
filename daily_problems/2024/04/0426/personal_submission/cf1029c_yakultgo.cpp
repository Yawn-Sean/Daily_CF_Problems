#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;

void solve() {
    int n;
    cin >> n;
    vector<pair<int, int>> v(n);
    int l[2] = {-1, -1};
    int r[2] = {INT_MAX, INT_MAX};
    for (int i = 0; i < n; i++) {
        cin >> v[i].first >> v[i].second;
        if (v[i].first >= l[0]) {
            l[1] = l[0];
            l[0] = v[i].first;
        } else if (v[i].first >= l[1]) {
            l[1] = v[i].first;
        }
        if (v[i].second <= r[0]) {
            r[1] = r[0];
            r[0] = v[i].second;
        } else if (v[i].second <= r[1]) {
            r[1] = v[i].second;
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int a, b;
        if (v[i].first == l[0]) {
            a = l[1];
        } else {
            a = l[0];
        }
        if (v[i].second == r[0]) {
            b = r[1];
        } else {
            b = r[0];
        }
        ans = max(ans, b - a);
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