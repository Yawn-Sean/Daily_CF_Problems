// Problem: E. President and Roads
// Contest: Codeforces - Codeforces Round #Pi (Div. 2)
// URL: https://codeforces.com/problemset/problem/567/E
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int>PII;
const int N=1e5+10,inf=1e18;
vector<PII>e[N];
int n,m,s,t;
int d[N],h[N],st[N];
int dfn[N],low[N],tot,cnt;
PII bride[N];
vector<PII>c;
vector<int>g[N];
struct node{
	int x,y,d;
};
node p[N];
map<PII,int>mp;

void add(int u,int v){
	c.push_back({u,v});
	g[u].push_back(c.size()-1);
}


void dij(int s){
	for(int i=1;i<=n;i++)	
		d[i]=inf;
	memset(st,0,sizeof st);
	priority_queue<PII,vector<PII>,greater<PII>>q;
	q.push({0,s});
	d[s]=0;
	while(q.size()){
		auto [dd,u]=q.top();q.pop();
		if(st[u])continue;
		st[u]=1;
		for(auto [v,x]:e[u]){
			if(d[v]>dd+x){
				d[v]=dd+x;
				q.push({d[v],v});
			}
		}
	}
}

void tarjan(int u,int in_deg){
	dfn[u]=low[u]=++tot;
	for(int i=0;i<g[u].size();i++){
		int j=g[u][i],v=c[j].second;
		//cout<<u<<" "<<v<<"\n";
		if(!dfn[v]){
			tarjan(v,j);
			low[u]=min(low[u],low[v]);
			//cout<<u<<" "<<v<<"\n";
			if(low[v]>dfn[u]){
				//cout<<u<<" "<<v<<"\n";
				mp[{u,v}]=1;//桥
			}
		}
		else if(j!=(in_deg^1)){
			low[u]=min(low[u],dfn[v]);
		}
	}
}

void solve(){
	cin>>n>>m>>s>>t;
	//vector<node>p[m+1];
	for(int i=1;i<=m;i++){
		int a,b,c;cin>>a>>b>>c;
		p[i]=(node){a,b,c};
		e[b].push_back({a,c});
		//e[b].push_back({a,c});
	}
	dij(t);
	memcpy(h,d,sizeof d);
	//cout<<d[t]<<"\n";
	for(int i=1;i<=n;i++){
		e[i].clear();
	}
	
	for(int i=1;i<=m;i++){
		auto [a,b,c]=p[i];
		e[a].push_back({b,c});
	}
	dij(s);
	int mn=d[t];
	//cout<<h[s]<<"\n";
	//cout<<mn<<"\n";
	//cout<<d[2]<<"\n";
	vector<int>st(m+1);
	for(int i=1;i<=m;i++){
		auto [u,v,w]=p[i];
		//cout<<d[u]<<" "<<h[v]<<"\n";
		//cout<<w<<"\n";
		if(d[u]+h[v]+w==mn){
			//cout<<u<<" "<<v<<"\n";
			st[i]=1;
			add(u,v);add(v,u);
			//g[u].push_back(v);
			//g[v].push_back(u);
		}
	}
	for(int i=1;i<=n;i++){
		if(!dfn[i])
			tarjan(i,0);
	}
	// for(auto [x,y]:mp){
		// cout<<x.first<<" "<<x.second<<"\n";
	// }
	
	for(int i=1;i<=m;i++){
		auto [u,v,w]=p[i];
		if(d[u]+d[v]+w>=inf){
			cout<<"NO\n";continue;
		}
		if((mp[{u,v}]||mp[{v,u}])&&st[i]){
			cout<<"YES\n";
		}
		else{
			int t=d[u]+h[v]+w-mn;
			//cout<<t<<"\n";
			if(w-t-1<=0){
				cout<<"NO\n";
			}
			else
				cout<<"CAN"<<" "<<t+1<<"\n";
		}
	}
	
}

signed main()
{
	ios::sync_with_stdio(0),cin.tie(0);
	int tt=1;
	while(tt--)solve();
}


