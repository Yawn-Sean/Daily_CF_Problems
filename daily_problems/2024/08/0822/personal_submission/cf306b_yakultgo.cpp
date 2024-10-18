#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;

void solve() {
    int n, k;
    cin >> n >> k;
    if (k >= n - 1) {
        cout << 0 << endl;
        return;
    }
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    auto check = [&](ll x) {
        vector<int> dp(n, 1);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (abs(a[i] - a[j]) <= x * (i - j)) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            if (dp[i] + k >= n) {
                return true;
            }
        }
        return false;
    };
    ll left = 0, right = 2e9;
    while (left < right) {
        ll mid = (left + right) / 2;
        if (check(mid))
            right = mid;
        else
            left = mid + 1;
    }
    cout << left << endl;
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