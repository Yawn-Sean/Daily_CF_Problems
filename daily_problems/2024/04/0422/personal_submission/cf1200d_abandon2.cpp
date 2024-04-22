// Problem: D. White Lines
// Contest: Codeforces - Codeforces Round 578 (Div. 2)
// URL: https://codeforces.com/problemset/problem/1200/D
// Memory Limit: 256 MB
// Time Limit: 1500 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
using namespace std;
const int N=2005;
int c[N][N],t[N][N],pre[N][N];
int n,k;
void solve(){
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++){
			char x;cin>>x;
			t[i][j]=(x=='B');
		}
	
	int ans=0;
	for(int i=1;i<=n;i++){
		int l=n+1,r=0,cnt=0;
		for(int j=1;j<=n;j++)
			if(t[i][j])
				l=min(l,j),r=max(r,j),cnt++;
		if(!cnt)ans++;//这一行都是白色的
		else if(r-l>=k)continue;
		else{
			int x=max(1,i-k+1),y=max(1,r-k+1);
			c[i][l]++;c[i][y-1]--;
			if(i>=k)
				c[i-k][l]--,c[x-1][y-1]++;
		}
	}
	
	for(int j=1;j<=n;j++){
		int l=n+1,r=0,cnt=0;
		for(int i=1;i<=n;i++)
			if(t[i][j])
				l=min(l,i),r=max(r,i),cnt++;
		if(!cnt)ans++;
		else if(r-l>=k)continue;
		else{
			int x=max(1,j-k+1),y=max(1,r-k+1);//x是左边，y是上面
			c[l][j]++;c[y-1][j]--;
			if(j>=k)
				c[l][j-k]--,c[y-1][x-1]++;
		}
	}
	for(int i=n;i>=1;i--)
		for(int j=n;j>=1;j--)
			pre[i][j]=pre[i+1][j]+pre[i][j+1]-pre[i+1][j+1]+c[i][j];
	
	int mx=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++){
			mx=max(mx,pre[i][j]);
		}
	cout<<ans+mx<<"\n";
	
	
	// for(int i=1;i<=n;i++)
		// for(int j=1;j<=n;j++)
			// cout<<pre[i][j]<<" \n"[j==n];
	
	
}

signed main()
{
	ios::sync_with_stdio(0),cin.tie(0);
	int tt=1;
	while(tt--)solve();
}


