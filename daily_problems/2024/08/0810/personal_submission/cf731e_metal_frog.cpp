#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

using ull = unsigned long long;
using ll = long long;
using pii = pair<int, int>;

void solve() {
    int n;
    cin >> n;
    vector<ll> num(n);
    for (int i = 0; i < n; i++) {
        cin >> num[i];
        if (i > 0) num[i] += num[i - 1];
    }
    ll ans = num[n - 1];
    for (int i = n - 2; i >= 1; i--) {
        ans = max(ans, num[i] - ans);
    }
    cout << ans << "\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    solve();
}
