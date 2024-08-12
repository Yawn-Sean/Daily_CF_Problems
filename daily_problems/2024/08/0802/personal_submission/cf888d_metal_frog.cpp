#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
 
using ull = unsigned long long;
using ll = long long;
using pii = pair<int, int>;

ll C(int n, int m) {
    if (m > n) return 0;
    ll ans = 1;
    for (int i = 0; i < m; i++) {
        ans = ans * (n - i) / (i + 1);
    }
    return ans;
}

void solve() {
    int n, k;
    cin >> n >> k;
    
    ll p[] = {1, 0, 1, 2, 9};
    ll ans = 0;
    for (int i = 0; i <= k; i++) {
        ans += C(n, i) * p[i];
    }
    cout << ans << endl;
}
 
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
    solve();
}
