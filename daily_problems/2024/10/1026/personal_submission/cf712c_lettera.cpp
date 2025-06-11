#include<bits/stdc++.h>
using namespace std;
using ll = long long;
//#define int ll
void solve()
{
       int x,y;
       cin>>x>>y;
       int ans=2;
       int a,b,c;
       a=b=y;
       while(b<x)
       {
       	  a+=b-1;
       	  swap(a,b);
       	  ans++;
       }
       cout<<ans<<"\n";
}
signed main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int t = 1;
    //cin >> t;
    while (t--)
    {
        solve();
    }
}
