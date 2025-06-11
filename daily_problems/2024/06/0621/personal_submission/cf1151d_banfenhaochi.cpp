#include <bits/stdc++.h>
using namespace std;
using LL=long long;
constexpr int N=2e5+10;
struct Person
{
	LL a,b;
}a[N];

void solve()
{
	int n;cin>>n;
	LL ans=0;
	for(int i=1;i<=n;++i) cin>>a[i].a>>a[i].b;

	// ai*(j-1)+bi*(n-j)
	// (ai-bi)*j-ai+(bi*n)
	// 对(ai-bi)*j排序
	// ai-bi大的排前面

	sort(a+1,a+1+n,[&](Person& pa,Person& pb)
		{
			return pa.a-pa.b > pb.a-pb.b;
		});
	
	for(int i=1;i<=n;++i)
	{
		ans+=(a[i].a-a[i].b)*i-a[i].a+(n*a[i].b);
	}
	cout<<ans<<endl;
}

int main()
{
	ios::sync_with_stdio(false),cin.tie(nullptr);
	solve();

	return 0;
}
