#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;

void solve() {
    int n;
    cin >> n;
    vector<pair<int, int>> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i].first >> a[i].second;
    }
    int cur = 1;
    vector<bool> vis(n + 1);
    for (int i = 1; i <= n; i++) {
        cout << cur << " ";
        vis[cur] = true;
        int p = a[cur].first, q = a[cur].second;
        if ((a[p].first == q || a[p].second == q) && !vis[p]) {
            cur = p;
        } else {
            cur = q;
        }
    }
    cout << endl;
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