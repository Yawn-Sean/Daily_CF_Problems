#include <bits/stdc++.h>
using namespace std;
const int N=2e4+10;
const int mod = 998244353;
typedef long long ll;
typedef unsigned long long ull;
int n;


void solve()
{
    ll a,b,c;
    cin>>a>>b>>c;
    ll g = __gcd(a,b);
    ll d = a*b/g;
    ll g2 = __gcd(d,c);
    ll ans = (c-1)/g2*g2;
    cout<<ans<<'\n';
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    cin>>t;
    while(t--)
    {
        solve();

    }


    return 0;
}
