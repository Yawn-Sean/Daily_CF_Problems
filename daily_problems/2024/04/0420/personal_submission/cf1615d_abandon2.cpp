// Problem: D. X(or)-mas Tree
// Contest: Codeforces - Codeforces Global Round 18
// URL: https://codeforces.com/problemset/problem/1615/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
#define x first
#define y second
int f[N],fa[N],d[N];
int n,m;
vector<int>e[N];
struct node{
	int x,y;
};

void dfs(int u){
	for(int v:e[u]){
		if(v==fa[u])continue;
		fa[v]=u;
		dfs(v);
	}
}

int find(int x){
	if(f[x]==x)return x;
	int tmp=f[x];
	f[x]=find(f[x]);
	d[x]^=d[tmp];
	return f[x];
}

void solve(){
	vector<node>v;
	int n,m;cin>>n>>m;
	map<pair<int,int>,int>mp;
	for(int i=1;i<=n;i++)f[i]=i,fa[i]=0,d[i]=0,e[i].clear();
	for(int i=1;i<n;i++){
		int a,b,w;cin>>a>>b>>w;
		e[a].push_back(b),e[b].push_back(a);
		if(w!=-1)mp[{a,b}]=mp[{b,a}]=w;
	}
	dfs(1);
	int flag=1;
	for(auto [u,w]:mp){
		int x=u.x,y=u.y;
		w=__builtin_popcount(w)&1;
		//cout<<x<<" "<<y<<" "<<w<<"\n\n";
		int a=find(x),b=find(y);
		//cout<<a<<" "<<b<<"\n";
		if(a==b){
			if((d[x]^d[y])!=w)
				flag=0;
		}
		else{
			d[a]=d[x]^d[y]^w;
			f[a]=b;
		}
		
	}
	
	for(int i=1;i<=m;i++){
		int x,y,w;cin>>x>>y>>w;
		//w=__builtin_popcount(w)&1;
		int a=find(x),b=find(y);
		if(a==b){
			if((d[x]^d[y])!=w)
				flag=0;
		}
		else{
			d[a]=d[x]^d[y]^w;
			f[a]=b;
		}
		
	}
	if(!flag){
		cout<<"NO\n";return;
	}
	cout<<"YES\n";
	for(int i=2;i<=n;i++){
		//cout<<i<<" "<<fa[i]<<"\n";
		if(mp.count({i,fa[i]})){
			cout<<i<<" "<<fa[i]<<" "<<mp[{i,fa[i]}]<<"\n";
		}
		else{
			int a=find(i),b=find(fa[i]);
			cout<<i<<" "<<fa[i]<<" "<<(d[i]^d[fa[i]])<<"\n";
		}
	}	
}

signed main()
{
	ios::sync_with_stdio(0),cin.tie(0);
	int tt;cin>>tt;
	while(tt--)solve();
}


