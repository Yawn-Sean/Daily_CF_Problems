#include <bits/stdc++.h>
using namespace std;
const int N=2e6+10,mod=1e9+7,M=30,inf=0x3f3f3f3f;
#define endl '\n'
#define int long long 
typedef pair<int,int> PII;
int n,cnt[N],m,s[N],f[M][M],k;
int a[N];
void solve()
{
	cin>>n;
	int ls=0,eq=0,gt=0;
	int id=0,ans=0;
	for(int i=1;i<=n;i++) 
	{
		cin>>a[i];
		if(a[i]>i) gt++,cnt[a[i]-i]++;
		else if(a[i]<i) ls++;
		else eq++,cnt[0]++;
		ans+=abs(a[i]-i);
	}
	int t=ans;
	for(int i=n,j=1;i>=2;i--,j++)
	{
		t+=eq+ls-gt;
		t--; //最后一个一定是小于等于n的，右移的时候算在eq或者ls里面
		ls+=eq;
		gt-=cnt[j];
		if(a[i]>=i) cnt[a[i]-i]--;
		cnt[a[i]-1+j]++;
		eq=cnt[j];
		if(a[i]>1) gt++;
		ls=n-eq-gt;
		t-=abs(a[i]-n)-abs(a[i]-1);
		if(t<ans) ans=t,id=j; 
	}
	cout<<ans<<" "<<id;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	int T=1;//cin>>T;
	while(T--) solve();
	return 0;
 } 
