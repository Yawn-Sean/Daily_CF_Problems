#include <bits/stdc++.h>
using namespace std;
using LL=long long;
constexpr int N=2e5+10;
int a[N];
int n,k;
 
void solve()
{
	cin>>n>>k;
	for(int i=0;i<n;++i)
	{	
		cin>>a[i];
	}
	
	int res=INT_MAX,ans=0;
	for(int i=0;i+k<n;++i) // 枚举所有长度为k的子序列
	{
		if(a[i+k]-a[i]<res) 
		{
			res=a[i+k]-a[i]; // 递增序列如果左右端点差值变小说明最大值M也能变小，
			ans=(a[i+k]+a[i])/2; // x只需要求中点取到最小的最大值M
		}
	}
 
	cout<<ans<<endl;
}
 
int main()
{
	ios::sync_with_stdio(false),cin.tie(nullptr);
	int t;cin>>t;
	while(t--)
	solve();
 
	return 0;
}
