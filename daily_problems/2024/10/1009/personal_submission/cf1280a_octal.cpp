#include<bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
#define pdd pair<double, double>
#define pll pair<ll, ll>
#define endl '\n'
typedef long long ll;
typedef unsigned long long ull;
const int mod = 1e9+7;
inline void solve()
{
    int x;
    cin >> x;
    string s;
    cin >> s;
    ll res = s.size();
    for(int i=0; i<min(x, (int)s.size()); i++) {
        string t = s.substr(i+1);
        for(int j=1; j<=s[i]-'1'; j++) {
            s += t;
            if(s.size() > x) break;
        }
        if(s.size() > x) break;
    }
    for(int i=0; i<x; i++) {
        res += 1ll*(res - i - 1 + mod) % mod * (s[i]-'1') % mod;
        res %= mod;
    }
    cout << res << endl;
}
int main()
{
    cout << fixed << setprecision(10);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t --)
        solve();
    return 0;
}
