#include <bits/stdc++.h>
using namespace std;
const int N=3e5+10,mod=1e9+7;
#define endl '\n'
#define int long long 
typedef pair<int,int> PII;
int n;
string a,b; 
void solve()
{
	cin>>n>>a>>b;
	int s1=0,s2=0,s=0;
	for(int i=0;i<n;i++)
	{
		s+=a[i]!=b[i];
		s1+=a[i]=='1';
		s2+=b[i]=='1';
	}
	int ans=n+1;
	if(s1==s2) ans=s;
	if(n-s1+1==s2) ans=min(ans,n-s);
	if(ans>n) ans=-1;
	cout<<ans<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	int T=1;cin>>T;
	while(T--) solve();
	return 0;
 } 
