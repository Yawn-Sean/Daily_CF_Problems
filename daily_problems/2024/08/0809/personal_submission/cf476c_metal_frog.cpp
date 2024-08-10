#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
 
using ull = unsigned long long;
using ll = long long;
using pii = pair<int, int>;
 
const ll mod = 1e9 + 7;
 
void solve() {
    ll a, b;
    cin >> a >> b;
    ll part1 = b * (b - 1LL) / 2LL;
    part1 %= mod; 
    ll ans = 0;
    for (int k = 1; k <= a; k++) {
        ll tmp = k * b + 1LL;
        tmp %= mod;
        ans += (tmp * part1) % mod;
        ans %= mod;
    }
    cout << ans << endl;
}
 
int main() {
	  cin.tie(0)->sync_with_stdio(0);
	  cin.exceptions(cin.failbit);
    solve();
}
