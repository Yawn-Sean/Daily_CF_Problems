#include <bits/stdc++.h>
using namespace std;
const int N=1010,mod=998244353,M=2010;
#define endl '\n'
#define int long long 
typedef pair<int,int> PII;
int n,k;
int f[2][4][M];
void solve()
{
	cin>>n>>k; // bb bw wb ww
	f[1][0][1]=1;f[1][1][2]=1;
	f[1][2][2]=1;f[1][3][1]=1;
	for(int i=2;i<=n;i++)
	{
		int x=i%2,y=(i+1)%2;
		for(int j=1;j<=k;j++)
		{
			int s=max(j-2,0LL);
			f[x][0][j]=(f[y][0][j]+f[y][1][j]+f[y][2][j]+f[y][3][j-1])%mod;
			f[x][1][j]=(f[y][0][j-1]+f[y][1][j]+f[y][2][s]+f[y][3][j-1])%mod;
			f[x][2][j]=(f[y][0][j-1]+f[y][1][s]+f[y][2][j]+f[y][3][j-1])%mod;
			f[x][3][j]=(f[y][0][j-1]+f[y][1][j]+f[y][2][j]+f[y][3][j])%mod;
		}
	}
	int ans=0;
	for(int i=0;i<4;i++) ans=(ans+f[n%2][i][k])%mod;
	cout<<ans;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	int T=1;//cin>>T;
	while(T--) solve();
	return 0;
 } 
