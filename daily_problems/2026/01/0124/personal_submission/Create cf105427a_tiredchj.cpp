#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef __int128_t lll;
typedef pair<int,int> pii;
#define mem(a,b) memset(a,b,sizeof(a))
#define x first
#define y second
constexpr ll inf = 1e18;
constexpr ll mod = 998244353;
constexpr ll MOD = 1e9 + 7;

void solve() {
    ll n, k;
    cin >> n >> k;
    ll ans = 0;
    while(n > k) {
        for (ll x = k + 1, y = 1, i = 1; ;i++) {
            if (i == k) {
                ans += y + n - x;
                n = 0;
                break;
            }
            if (n < k * x + 1) {
                ans += y * (n / x);
                n %= x;
                break;
            }
            x = x * k + 1;
            y = y * k + 1;
        }
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0),cin.tie(0);
    int T = 1;
    //cin >> T;
    while(T--) {
        solve();
    }
    return 0;
}
