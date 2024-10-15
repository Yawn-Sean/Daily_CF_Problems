#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
const int mod = 1 ? 998244353 : 1e9 + 7;
//#define int ll
void solve() 
{
	
	//一行能保留原来的颜色(k种选择)当且仅当后面没有一行覆盖且没有覆盖m列
	//一列能保留原来的颜色(k种选择)当且仅当后面没有一列覆盖且没有覆盖n行
	//确定是哪次操作造成的影响是持续到最后的(即涂的这一行/列至少有一个格子不会变色)
	ll ans=1;
	int n,m,k,q;
	cin>>n>>m>>k>>q;
	vector<bool>vis1(n),vis2(m);
	vector<int>xs(q),ys(q);
	for(int i=0;i<q;i++)
	{
		cin>>xs[i]>>ys[i];
		xs[i]--,ys[i]--;
	}
	int r=0,c=0;
	for(int i=q-1;i>=0;i--)
	{
		int x=xs[i],y=ys[i];
		if((!vis1[x]&&c<m)||!vis2[y]&&r<n)
		{
			ans=(1ll*ans*k)%mod;
		}
		if(!vis1[x])r++;
		if(!vis2[y])c++;
		vis1[x]=1;
		vis2[y]=1;
	}
	cout<<ans<<endl;
}
signed main() {
  ios::sync_with_stdio(false),cin.tie(0);
  int t;
  t = 1;
  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);
  cin >> t;
  while (t--) {
    solve();
  }
}









