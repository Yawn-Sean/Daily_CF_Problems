// Problem: D. New Year Santa Network
// Contest: Codeforces - Good Bye 2014
// URL: https://codeforces.com/problemset/problem/500/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
#define x first 
#define y second
typedef long long ll;
vector<int>e[N];
double w[N],siz[N];

void dfs(int u,int fa){
	siz[u]=1;
	for(int v:e[u]){
		if(v==fa)continue;
		dfs(v,u);
		siz[u]+=siz[v];
	}
}

void solve(){
	double n;scanf("%lf",&n);
	vector<pair<int,int>>p(n+1);	
	for(int i=1;i<=n;i++)
		w[i]=siz[i]=0,e[i].clear();
	for(int i=1;i<n;i++){
		int a,b;scanf("%d%d%lf",&a,&b,&w[i]);
		p[i]={a,b};
		e[a].push_back(b);
		e[b].push_back(a);
	}
	double c=n*(n-1)/2*(n-2)/3;
	dfs(1,0);
	//for(int i=1;i<=n;i++)
		//cout<<siz[i]<<" ";
	//cout<<"\n";
	double sum=0;
	for(int i=1;i<n;i++){
		auto [x,y]=p[i];
		double c1=min(siz[x],siz[y]);
		double c2=n-c1;
		sum+=(c1*(c2-1)*c2/2+c2*(c1-1)*c1/2)*w[i]*2;
	}
	//cout<<c<<"\n";
	//cout<<sum<<"\n";
	int q;scanf("%d",&q);
	while(q--){
		int x,y;scanf("%d%d",&x,&y);
		double z=w[x];
		w[x]=y;
		auto [a,b]=p[x];
		double c1=min(siz[a],siz[b]);
		double c2=n-c1;
		//cout<<c1<<" "<<c2<<"\n";
		double t=(c1*(c2-1)*c2/2+c2*(c1-1)*c1/2)*(z-w[x])*2;
		sum-=t;
		printf("%.10lf\n",sum*1.0/c);
		//cout<<sum/c<<"\n";
	}
}

signed main()
{
	//ios::sync_with_stdio(0),cin.tie(0);
	int tt=1;
	while(tt--)solve();
}


