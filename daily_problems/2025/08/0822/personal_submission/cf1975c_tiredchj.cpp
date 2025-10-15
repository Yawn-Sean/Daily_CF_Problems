#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
#ifdef __GNUC__
typedef __int128_t lll;
#endif
typedef pair<int,int> pii;
#define mem(a,b) memset(a,b,sizeof(a))
#define x first
#define y second
constexpr ll inf = 1e18;
constexpr int maxn = 3e5 + 5; 
constexpr int mod = 1e9 + 7; 

vector<ll>dp(maxn);

void solve() {
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < k; i++) {
        int a, b;
        cin >> a >> b;
        if (a == b) {
            n--;
        } else {
            n -= 2;
        } 
    }
    cout << dp[n] << '\n';
}

int main() {
    ios::sync_with_stdio(0),cin.tie(0);
    int T = 1;
    cin >> T;
    dp[0] = dp[1] =1;
    for (int i = 2;i < maxn; i++) {
        dp[i] = (dp[i - 1] + (2ll * (i - 1) * dp[i - 2] )% mod) % mod;
    }
    while(T--) {
        solve();
    }
    return 0;
}
