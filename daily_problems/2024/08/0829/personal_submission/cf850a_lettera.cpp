#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
//const int mod = 1 ? 998244353 : 1e9 + 7;
//#define int ll
void solve() 
{
	int n;
	cin>>n;
	vector<vector<int>>a(n,vector<int>(5));
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<5;j++)
		{
			cin>>a[i][j];
		}
	}
	
	vector<int>ans;
	
	if(n<=33)
	{
		for(int i=0;i<n;i++)
		{
			int flag=1;
			for(int j=0;j<n;j++)
			{
				for(int k=0;k<n;k++)
				{
					if(j==i||k==i||j==k)continue;
					ll mul=0;
					for(int l=0;l<5;l++)
					{
						mul+=1ll*(a[j][l]-a[i][l])*(a[k][l]-a[i][l]);
					}
					if(mul>0)
					{
						flag=0;
					}
				}
			}
			if(flag)
			{
				ans.push_back(i+1);
			}
		}
	}
	
	cout<<ans.size()<<"\n";
	for(auto x:ans)
	{
		cout<<x<<"\n";
	}
}
signed main() {
  ios::sync_with_stdio(false),cin.tie(0);
  int t;
  t = 1;
  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);
  //cin >> t;
  while (t--) {
    solve();
  }
}









