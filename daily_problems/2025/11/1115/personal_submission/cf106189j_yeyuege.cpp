#include<bits/stdc++.h>
// #pragma GCC optimize(2)
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<int,ll> pil;
typedef pair<ll,int> pli;
typedef pair<ll,ll> pll;
#define endl "\n"

void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<vector<int>> dp(n, vector<int>(n, 0));

    for (int diff = 1; diff < n; diff++) {
        for (int l = 0; l + diff < n; l++) {
            int r = l + diff;

            dp[l][r] = dp[l + 1][r - 1];
            if (a[l] % a[r] == 0 || a[r] % a[l] == 0) {
                dp[l][r] += 2;
            }

            for (int seq = l; seq < r; seq++) {
                dp[l][r] = max(dp[l][seq] + dp[seq + 1][r], dp[l][r]);
            }
        }
    }

    std::vector<int> v(n, 0);
    auto dfs = [&](this auto&& self, int l, int r) -> void {
        if (l >= r) return;
        for (int seq = l; seq < r; seq ++) {
            if (dp[l][seq] + dp[seq + 1][r] == dp[l][r]) {
                self(l, seq);
                self(seq + 1, r);
                return;
            }
        }

        if (a[l] % a[r] == 0 || a[r] % a[l] == 0) {
            v[l] = 1;
            v[r] = 1;
        }
        self(l + 1, r - 1);
    };

    dfs(0, n - 1);

    cout << n - dp[0][n - 1] << endl;
    for (int i = 0; i < n; i ++) {
        if (!v[i]) cout << i + 1 << " ";
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
