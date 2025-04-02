#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MOD = 1e9+7;
int n, cnts[26];
string s;

bool check(int start, int end) {
    int len = end - start + 1;
    start--;
    end--;
    for (int i = start; i <= end; ++i) {
        if (len > cnts[s[i] - 'a']) {
            return false;
        }
    }
    return true;
}

void solve() {
    cin >> n;
    cin >> s;
    for (int& cnt : cnts) {
        cin >> cnt;
    }
    vector<int> dp(n+1, 0), a(n+1, INT_MAX);
    dp[0] = 1;
    a[0] = 0;
    int mx = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (dp[j] && check(j+1, i)) {
                mx = max(mx, i-j);
                dp[i] = (dp[i] + dp[j]) % MOD;
                a[i] = min(a[i], a[j]+1);
            }
        }
    }
    cout << dp[n] << '\n';
    cout << mx << '\n';
    cout << a[n];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T = 1;
//    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
