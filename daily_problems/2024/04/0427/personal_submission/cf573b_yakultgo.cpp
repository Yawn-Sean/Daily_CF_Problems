#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
const int N = 1e5 + 10;
int a[N], l[N];
void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    l[1] = 1;
    for (int i = 2; i <= n; i++) {
        l[i] = min(l[i - 1] + 1, a[i]);
    }
    l[n] = min(l[n], 1);
    int ans = l[n];
    for (int i = n - 1; i >= 1; i--) {
        l[i] = min(l[i], l[i + 1] + 1);
        ans = max(ans, l[i]);
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