#include <bits/stdc++.h>
using namespace std;
using ll = long long;
//#define int ll
void solve()
{
	 int n;
	 cin>>n;
	 const int inf =n;
	 vector<vector<int>>dis(n+1,vector<int>(n+1,inf));
	 for(int i=1;i<=n;i++)
	 {
	 	string s;
	 	cin>>s;
	 	s=" "+s;
	 	dis[i][i]=0;
	 	for(int j=1;j<=n;j++){
	 		if(s[j]=='1')
	 		{
	 			dis[i][j]=1;
	 		}
	 	}
	 }
	 for(int i=1;i<=n;i++)
	 {
	 	for(int j=1;j<=n;j++)
	 	{
	 		for(int k=1;k<=n;k++)
	 		{
	 			dis[j][k]=min({dis[j][k],dis[j][i]+dis[i][k]});
	 		}
	 	}
	 }
	 int m;
	 cin>>m;
	 vector<int>a(m+1);
	 for(int i=1;i<=m;i++)
	 {
	 	cin>>a[i];
	 }
	 int pos=1;
	 vector<int>ans;
	 ans.push_back(a[1]);
	 while(pos<m)
	 {
	 	int npos=pos;
	 	while(npos+1<=m&&dis[a[pos]][a[npos+1]]==dis[a[pos]][a[npos]]+1)
	 	{
	 		npos++;
	 	}
	 	pos=npos;
	 	ans.push_back(a[pos]);
	 }
	 cout<<ans.size()<<"\n";
	 for(auto x:ans)
	 {
	 	cout<<x<<" ";
	 }
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
