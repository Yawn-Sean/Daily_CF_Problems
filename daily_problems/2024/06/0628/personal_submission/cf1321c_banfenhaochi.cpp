#include <bits/stdc++.h>
using namespace std;
using LL=long long;
constexpr int N=2e5+10;
int a[N];

void solve()
{
	int n;cin>>n;
	string s;cin>>s;
	int ans=0;
	for(int i='z';i>'a';--i)
	{
		for(int j=0;j<s.size();++j)
		{
			if(s[j]==i && ((j>0 && s[j-1]==i-1) || (j<s.size()-1 && s[j+1]==i-1) ))
			{
				++ans;
				s.erase(j,1);
				j=-1;
			}
		}
	}

	cout<<ans<<endl;
}

int main()
{
	ios::sync_with_stdio(false),cin.tie(nullptr);
	solve();

	return 0;
}
