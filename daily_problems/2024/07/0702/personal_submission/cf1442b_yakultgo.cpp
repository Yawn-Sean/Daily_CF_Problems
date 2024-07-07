#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
int mod = 998244353;
void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1), b(k + 1);
    vector<int> pos(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        pos[a[i]] = i;
    }
    vector<int> flag(n + 1);
    for (int i = 1; i <= k; i++) {
        cin >> b[i];
        flag[pos[b[i]]] = i;
    }
    int ans = 1;
    for (int i = 1; i <= k; i++) {
        int cnt = 0;
        if (pos[b[i]] > 1 && flag[pos[b[i]] - 1] < flag[pos[b[i]]]) cnt++;
        if (pos[b[i]] < n && flag[pos[b[i]] + 1] < flag[pos[b[i]]]) cnt++;
        ans = (ans * cnt) % mod;
    }
    cout << ans << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}