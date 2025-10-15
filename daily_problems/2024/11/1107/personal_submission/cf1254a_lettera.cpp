#include <bits/stdc++.h>
using namespace std;
using ll = long long;
//#define int ll
void solve()
{
	 int n,m,k;
	cin>>n>>m>>k;
	int c=0;
	vector<string>a(n+1);
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		a[i]=" "+a[i];
		for(int j=1;j<=m;j++)
		{
			c+=a[i][j]=='R';
		}
	}
	int x=1,y=1,dx=1,dy=1;
	auto move=[&]()
	{
		if(y+dy<=m&&y+dy>=1)
		{
			y+=dy;
		}
		else
		{
			x++;
			dy*=-1;
		}
	};
	vector<vector<int>>ans(n+1,vector<int>(m+1,-1));
	int c1=c/k,c2=c%k;
	for(int i=1;i<=k;i++)
	{
		int cur=1;
		int target=c1+(c2>0);
		while(cur<=target)
		{
			 ans[x][y]=i;
			 cur+=(a[x][y]=='R');
			 move();  
		}
		c2--;
	}
	string t=" 0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cout<<(ans[i][j]==-1?t[k]:t[ans[i][j]]);
		}
		cout<<"\n";
	}
}
signed main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
}
