#include <bits/stdc++.h>
using namespace std;
using LL=long long;
constexpr int N=2e5+10;
int a[N];

void solve()
{
	unordered_map<int,int> cnt;
	unordered_map<int,int> times;
	int n,ans=2;
	int mx=0;
	cin>>n;
	for(int i=1;i<=n;++i)
	{
		cin>>a[i];
		if(cnt.count(a[i]) && times.count(cnt[a[i]]) )
		times[cnt[a[i]]]--;
		cnt[a[i]]++;
		times[cnt[a[i]]]++;
		mx=max(mx,cnt[a[i]]);

		if(mx==1 || times[mx]*mx==i-1 || (times[mx-1]+1)*(mx-1)==i-1)
		ans=i;
	}

	cout<<ans<<endl;
}

int main()
{
	ios::sync_with_stdio(false),cin.tie(nullptr);
	solve();

	return 0;
}
