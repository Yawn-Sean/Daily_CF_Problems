#include<bits/stdc++.h>
using namespace std;
using ll = long long;
//#define int ll
void solve()
{
	int n;
	cin>>n;
	vector<array<int,3>>a(n);
	vector<int>ans(n,-1);
	for(int i=0;i<n;i++)
	{
		cin>>a[i][0]>>a[i][1];
		a[i][2]=i;
		if(a[i][0]>a[i][1])
		{
			swap(a[i][0],a[i][1]);
		}
	}
	sort(a.begin(),a.end(),[&](array<int,3>x,array<int,3>y){
		return x[0]!=y[0]?x[0]<y[0]:x[1]>y[1];
	});
	int mn=1e9+5,id=114514;
	for(int i=0;i<n;i++)
	{
		 if(a[i][1]<=mn)
		 {
		 	mn=a[i][1];
		 	id=a[i][2];
		 }
		 else{
		 	ans[a[i][2]]=id+1;
		 }
	}
	for(int i=0;i<n;i++)
	{
		cout<<ans[i]<<" \n"[i==n-1];
	}
}
signed main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
}
