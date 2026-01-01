#include <bits/stdc++.h>
using namespace std;
const int N=3e5+10;
const int mod = 998244353;
typedef long long ll;
typedef unsigned long long ull;
typedef __int128 i128;
ull x,k;
ll pw2[130];
void solve()
{
    cin>>x>>k;
    unordered_map<ll,ll>mp;
    ll x2 = x;
    for(ll i=2;i*i<=x2;i++)
    {
        if(x2%i==0)
        {
            mp[i]++;
            x2/=i;
            while(x2%i==0)
            {
                x2/=i;
                mp[i]++;
            }
        }
    }

    if(x2!=1)
    {
        mp[x2]++;
    }

    vector<ll>pcnt;
    for(auto xx:mp)
    {
        pcnt.push_back(xx.second);
    }
    int ans = 0;
    for(ll i=0;i<=63;i++)
    {
        ll mod = pw2[i];
        ll r = 0;
        for(ll x:pcnt)
        {
            ll r2 = (x%mod);
            r += (mod-r2)%mod;
        }
        if(r>k)break;
        else ans = i;  
    }
    cout<<ans<<'\n';
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    pw2[0]=1;
    for(ll i=1;i<=63;i++)pw2[i]=pw2[i-1]*2;
    int t=1;
    cin>>t;
    while(t--)
    {
        solve();

    }


    return 0;
}


