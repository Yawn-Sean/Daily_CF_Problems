#include <bits/stdc++.h>
using namespace std;
const int N=1e6+10;
const int mod = 1e9+7;

typedef long long ll;
int n;
ll fac[N];
ll fac2[N];

ll qpow(ll a,ll b,ll p )
{
    ll res =1;
    for(;b;b>>=1)
    {
        if(b&1)res =res*a%p;
        a = a*a%p;
    }
    return res;
}

void solve()
{
    cin>>n;
    ll res = (fac[n]-fac2[n-1]+mod)%mod;
    cout<<res<<'\n';

}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    for(int i=1;i<=N-10;i++)
    {
        fac[i] = (fac[i-1]+(qpow(i,mod-2,mod))%mod)%mod;
    }

    for(int i=1;i<N-10;i++)
    {
        fac2[i] = (fac2[i-1]+qpow(i,mod-2,mod)%mod*qpow(i+1,mod-2,mod)%mod)%mod;

    }

    int t=1;
    cin>>t;
    while(t--)
    {
        solve();

    }


    return 0;
}
