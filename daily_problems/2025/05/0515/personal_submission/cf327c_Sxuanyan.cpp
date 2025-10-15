#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;
const ll N = 2e5 + 10;
const ll inf = 1e9;
typedef pair<int, int> pii;
ll dx[] = {1, 0, -1, 0};
ll dy[] = {0, 1, 0, -1};
ll power(ll base, ll exp, ll mod)
{
    ll result = 1;
    base %= mod;
    while (exp > 0)
    {
        if (exp & 1)
            result = (result * base) % mod;
        base = (base * base) % mod;
        exp >>= 1;
    }
    return result;
}
void solve()
{
    ll n = 0, cut = 0, k = 0;
    string s;
    cin >> s >> k;
    vector<ll> pos;
    // cout<<1<<endl;
    for (ll i = 0; i < s.length(); i++)
    {
        if (s[i] == '0' || s[i] == '5')
        {
            pos.push_back(i);
            if (s[i] == '0')
                cut++;
        }
    }
    // cout<<cut<<endl;
    //  for (auto x : pos)
    //  {
    //      cout << x << endl;
    //  }
    // ll sum = 0;

    // for (ll i = 0; i < k; i++)
    // {
    //     sum = (sum + power(2, i * (s.length()), mod)) % mod;
    // }
    ll L = s.length();
    ll r = power(2, L, mod);
    ll sum = 0;
    if (r == 1)
        sum = k % mod;
    else
        sum = ((power(r, k, mod) - 1 + mod) % mod * power(r - 1, mod - 2, mod)) % mod;//费马小定理

    ll ans = 0;
    for (auto x : pos)
    {
        ll len = x;
        ans = (ans + power(2, len, mod) % mod * sum) % mod;
    }

    // ans = cut;
    cout << ans % mod << endl;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll t = 1;
    // cin >> t;
    while (t--)
        solve();
}
