#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
const int mod = 1?998244353:1e9+7;
const int N=1e5+5;
const int inf=1e9;
#define int ll
void solve()
{
    ll n;
    cin>>n;
  	//相当于二叉树的深度
  	int ans=0;
  	int cnt1=2,cnt2=1;
  	//f[1]=1 f[2]=2 
  	while(cnt1<=n)
  	{
  		ans++;
  		cnt1+=cnt2;
  		cnt2=cnt1-cnt2;
  	}
  	cout<<ans<<endl;

    
}
signed main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    int t = 1;
   // cin>>t;
    while (t--)
    {
        solve();
    }
}
