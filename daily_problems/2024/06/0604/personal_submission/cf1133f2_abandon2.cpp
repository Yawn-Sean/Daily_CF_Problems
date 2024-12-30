#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
vector<int>e[N];
int f[N];

int find(int x){
	if(x==f[x])return x;
	return f[x]=find(f[x]);
}

void solve(){
	int n,m,d;cin>>n>>m>>d;
	vector<array<int,2>>g;
	for(int i=1;i<=m;i++){
		int a,b;cin>>a>>b;
		e[a].push_back(b);
		e[b].push_back(a);
		g.push_back({a,b});
	}		
	for(int i=1;i<=n;i++)f[i]=i;
	int cnt=0;
	for(auto &[u,v]:g){
		if(u>v)swap(u,v);
	
		int x=find(u),y=find(v);
		if(x!=y&&u!=1){
			
			f[x]=y;
		}
		if(u==1)cnt++;
	}

	if(cnt<d){
		cout<<"NO\n";return;
	}
	cnt=0;
	for(int i=1;i<=n;i++){
		if(find(i)==i&&i!=1)cnt++;
	}
	if(cnt>d){
		cout<<"NO\n";return;//连通块数量过多
	}

	cnt=0;
	vector<int>vis(n+2,0),deg(n+2,0);
	//在1和连通块之间连一条边
	vector<array<int,2>>ans;
	for(auto [u,v]:g){
		//cout<<u<<" "<<v<<"\n";
		int x=find(u),y=find(v);
		//cout<<x<<" "<<y<<"  lll\n";
		if(f[y]&&x==1&&!vis[y]){
			deg[x]++;
			f[y]=0;
			ans.push_back({u,v});
			vis[v]=1;
		}
	}

	for(int i=1;i<=n;i++)
	 	f[i]=vis[i]?1:i;
	// for(int i=1;i<=n;i++){
	// 	cout<<f[i]<<" ";
	// }
	// cout<<"\n";
	// for(auto[u,v]:ans){
	// 	cout<<u<<" "<<v<<"\n";
	// }
	//cout<<"\n";
	sort(g.begin(),g.end());
	cnt=ans.size();
	//cout<<cnt<<"xxxxx\n";
	for(auto [u,v]:g){
		if(cnt==n-1){
			break;
		}
		if(u==1&&deg[u]==d)continue;
		//cout<<u<<" "<<v<<" "<<deg[1]<<"\n";
		int x=find(u),y=find(v);
		//cout<<x<<" "<<y<<"ddd\n";
		if(x!=y){
			//cout<<x<<" "<<y<<"fff\n";
			if(x==1)deg[x]++;
			cnt++;
			ans.push_back({u,v});
			f[y]=x;
		}
	}
	//cout<<deg[1]<<"dd\n";
	cout<<"YES\n";
	for(auto[u,v]:ans){
		cout<<u<<" "<<v<<"\n";
	}
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	solve();
	return 0;
}
