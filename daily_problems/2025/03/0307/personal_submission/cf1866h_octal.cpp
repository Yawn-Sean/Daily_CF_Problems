#include<bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
#define pdd pair<double, double>
#define pll pair<ll, ll>
#define debug(x) cerr << #x << ": " << x << '\n';
#define endl '\n'
typedef long long ll;
typedef unsigned long long ull;
const int mod = 998244353;
ll qmi(ll a, ll b, ll mod)
{
	ll res = 1;
	while(b) {
		if(b & 1) res = res*a%mod;
		a = a*a%mod;
		b >>= 1;
	}
	return res;
}
inline void solve()
{
    int n, k;
    cin >> n >> k;
    ll res = 1, t = 1;
    for(int x=1; x<=min(n, k); x++) {
        t = t * x % mod * (n-x+1) % mod;
        res += t * (qmi(x+1, k-x+1, mod) - qmi(x, k-x+1, mod)) % mod;
        res %= mod;
    }
    cout << (res + mod) % mod << endl;
}
int main()
{
    cout << fixed << setprecision(10);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t;
    t = 1;
    while(t --)
        solve();
    return 0;
}
