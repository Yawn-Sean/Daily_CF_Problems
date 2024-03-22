#include <bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define endl '\n'
#define int long long
#define lowbit(x) x & -x
#define PII pair<int, int>
#define PIII pair<int, PII>
#define ctzll(x) __builtin_ctzll(x)
#define popcount(x) __builtin_popcount(x)

const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7; // 998244353;

void solve() {
    int n, ans = 1;
    cin >> n;
    vector<int> cnt(1e6 + 1), dp(1e6 + 1);
    while (n--) {
        int x;
        cin >> x;
        cnt[x]++;
    }
    for (int i = 1; i <= 1e6; ++i) {
        dp[i] += cnt[i];
        for (int j = i; j <= 1e6; j += i) {
            dp[j] = max(dp[j], dp[i]);
        }
    }
    cout << *max_element(dp.begin(), dp.end()) << endl;
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
    return 0;
}
