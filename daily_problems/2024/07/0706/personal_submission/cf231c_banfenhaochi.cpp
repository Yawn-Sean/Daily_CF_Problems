#include <bits/stdc++.h>
using namespace std;
using LL=long long;
using PII=pair<LL,LL>;
constexpr int N=2e5+10;
LL a[N],s[N];

void solve()
{
	int n,k;cin>>n>>k;
	for(int i=1;i<=n;++i) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;++i)
	{
		s[i]+=s[i-1]+a[i];
	}
	PII ans{0,0};
	for(int i=1,j=1;i<=n && j<=i;++i)
	{
		while(a[i]*(i-j+1)-(s[i]-s[j-1])>k)
			++j;

		if(i-j+1>ans.second)
		{
			ans.first=a[i];
			ans.second=i-j+1;
		}

	}
	
	cout<<ans.second<<" "<<ans.first<<endl;
}

int main()
{
	ios::sync_with_stdio(false),cin.tie(nullptr);
	solve();

	return 0;
}
