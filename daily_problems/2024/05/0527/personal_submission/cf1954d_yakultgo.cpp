#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
int mod = 998244353;
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a) {
        cin >> x;
    }
    sort(a.begin(), a.end());
    int sum = accumulate(a.begin(), a.end(), 0);
    vector<ll> dp(sum + 1);
    dp[0] = 1;
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= sum; j++) {
            if (j <= a[i])
                ans = (ans + dp[j] * a[i] % mod) % mod;
            else {
                ans = (ans + 1ll * ((j + a[i] + 1) / 2) * dp[j] % mod) % mod;
            }
        }
        for (int j = sum; j >= a[i]; j--) {
            dp[j] = (dp[j] + dp[j - a[i]]) % mod;
        }
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