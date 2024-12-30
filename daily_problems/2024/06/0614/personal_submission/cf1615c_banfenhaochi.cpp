#include <bits/stdc++.h>
using namespace std;
using LL=long long;
constexpr int N=2e5+10;
int a[N];

void solve()
{
	int n;cin>>n;
	string a,b;cin>>a>>b; // 规律:偶数次操作不同位即交换不同位
	int s1=0,s2=0;
	int ans=INT_MAX;
	for(int i=0;i<n;++i)
		s1+=a[i]-'0',s2+=b[i]-'0'; 

	int cnt=0; // 计不同个数
	for(int i=0;i<n;++i)
	{
		if(b[i]!=a[i])
			++cnt;
	}

	// 01个数不变，奇数次操作和偶数次操作取最小
	// 奇数次操作即全翻转一遍，然后进行偶数次操作，尽量选ab同为1的位能减少一次操作次数
	if(s1==s2) ans=min(ans,cnt); // 偶数次操作直接取不同位个数即可
	if(n-s1+1==s2) ans=min(ans,n-cnt); // 奇数次操作全部反转取不同位个数

	cout<<(ans==INT_MAX?-1:ans)<<endl;
}

int main()
{
	ios::sync_with_stdio(false),cin.tie(nullptr);
	int t;cin>>t;
	while(t--)
	solve();

	return 0;
}
