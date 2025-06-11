#include <bits/stdc++.h>
using namespace std;
const int N=3e5+10,mod=1e9+7,M=30,inf=0x3f3f3f3f;
#define endl '\n'
//#define int long long 
typedef pair<int,int> PII;
int n,cnt[N],m,s[N],f[M][M],k;
char g[M][M];
string a,b;
void solve()
{
	cin>>a>>b;
	memset(f,0x3f,sizeof f);
	cin>>n;
	for(int i=0;i<26;i++) f[i][i]=0;
	for(int i=1;i<=n;i++)
	{
		char x,y;int w;
		cin>>x>>y>>w;
		int xx=x-'a',yy=y-'a';
		if(f[xx][yy]>w)
		{
			f[xx][yy]=w;
			//g[xx][yy]=y;
		}
	}
	for(int k=0;k<26;k++)
	{
		for(int i=0;i<26;i++)
		{
			for(int j=0;j<26;j++)
			{
				
				if(f[i][j]>f[i][k]+f[k][j])
				{
					f[i][j]=f[i][k]+f[k][j];
					//g[i][j]=(char)k+'a';
				}
			}
		}
	}
	if(a.size()!=b.size()) 
	{
		cout<<-1;return;
	}
	m=a.size();
	bool ok=1;
	int ans=0;
	for(int i=0;i<m;i++)
	{
		int x=a[i]-'a',y=b[i]-'a';
		if(x!=y)
		{
			char c;int maxn=inf;
			for(int j=0;j<26;j++)
			{
				if(f[x][j]!=inf&&f[y][j]!=inf) 
				{
					int s=f[x][j]+f[y][j];
					if(s<maxn)
					{
						maxn=s;c=j+'a';
					}
				} 
			}
			if(maxn==inf)
			{
				ok=0;break;
			}
			else ans+=maxn,a[i]=c;
		}
	}
	cout<<(ok?ans:-1)<<endl;
	if(ok) cout<<a;
}
signed main()
{
	//ios::sync_with_stdio(0);cin.tie(0);
	int T=1;//cin>>T;
	while(T--) solve();
	return 0;
 } 
