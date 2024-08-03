// Problem: C. Amr and Chemistry
// Contest: Codeforces - Codeforces Round 312 (Div. 2)
// URL: https://codeforces.com/problemset/problem/558/C
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int siz[N],vis[N],a[N],dep[N];
int dp[N];
int n,mx;

void dfs(int u){
	if(u>mx)return;
	dep[u<<1]=dep[u<<1|1]=dep[u]+1;
	dfs(u<<1);dfs(u<<1|1);
	siz[u]=siz[u<<1]+siz[u<<1|1]+vis[u];
}

void solve(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		vis[a[i]]++;
		mx=max(mx,a[i]);
	}	
	dfs(1);
	int root=0;
	for(int i=mx;i>=1;i--){
		if(siz[i]==n){
			root=i;break;
		}
	}
	
	for(int i=1;i<=n;i++)
		dp[root]+=dep[a[i]]-dep[root];
	int ans=dp[root];
	
	int t=root<<1;
	int lst=root;
	while((t<=mx)){
		dp[t]=dp[lst]-siz[t]+(n-siz[t]);		
		lst=t;
		ans=min(ans,dp[t]);
		t<<=1;
	}
	cout<<ans<<"\n";
}

signed main()
{
	ios::sync_with_stdio(0),cin.tie(0);
	int tt=1;
	while(tt--)solve();
}


