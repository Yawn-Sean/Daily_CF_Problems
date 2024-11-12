#include <bits/stdc++.h>
using namespace std;
using ll = long long;
//#define int ll
void solve()
{
	int n,m;
	cin>>n>>m;
	int ans;
	vector<vector<char>>a(n,vector<char>(m));
	int f1=0,f2=0;
	vector<int>cnt1(n),cnt2(m);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin>>a[i][j];
			 cnt1[i]+=a[i][j]=='A';
			 cnt2[j]+=a[i][j]=='A';
			 if(a[i][j]=='A')
			 {
			 	f1=1;
			 }
			 else
			 {
			 	f2=1;
			 }
		}
	}
	int x=*max_element(cnt1.begin(),cnt1.end());
	int y=*max_element(cnt2.begin(),cnt2.end());
	if(!f1)
	{
		cout<<"MORTAL\n";
	}
	else if (!f2)
	{
		cout<<0<<"\n";
	}
	else if(cnt1[0]==m||cnt1[n-1]==m||cnt2[0]==n||cnt2[m-1]==n)
	{
		cout<<1<<"\n";
	}
	else if(a[0][0]=='A'||a[0][m-1]=='A'||a[n-1][0]=='A'||a[n-1][m-1]=='A'||x==m||y==n)
	{
		cout<<2<<"\n";
	}
	else  if(cnt1[0]||cnt1[n-1]||cnt2[0]||cnt2[m-1])
	{
		cout<<3<<"\n";
	}
	else
	{
		cout<<4<<"\n";
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
