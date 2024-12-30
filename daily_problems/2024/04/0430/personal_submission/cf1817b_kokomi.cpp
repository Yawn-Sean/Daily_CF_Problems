#include<bits/stdc++.h>
using namespace std;
const int N = 2e3+5;
bool w;
int n,m;
vector<int> g[N],c,f;
bool b[N];
int d[N];
void dfs(int s,int e,int x){
	c.push_back(x),b[x]=true;
	if(x==e){
		f=c;
		return;
	}
	for(int i:g[x]){
		if(!b[i]&&(s!=x||i!=e)){
			dfs(s,e,i);
			if(!f.empty()) return;
		}
	}
	c.pop_back();//该节点无环
}

void solve(){
	cin>>n>>m;
	w = false;
	for(int i=1;i<=n;i++) g[i].clear(),b[i]=d[i]=0;
	for(int i=1;i<=m;i++){
		int u,v;
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
		d[u]++,d[v]++;
	}
	
	for(int i=1;i<=n;i++){
		if(d[i]>=4&&!w){
			for(int j:g[i]){
				//找环
				c.clear(),f.clear();
				memset(b,0,sizeof b);//清空标记数组
				dfs(i,j,i);
				if(!f.empty()){
					vector<pair<int,int>> r;
					for(int i=0;i<f.size();i++){
						r.push_back({f[i],f[(i+1)%f.size()]});
					}
					int c=0;
					for(int j:g[i]){
						if(c>1) break;
						if(find(f.begin(),f.end(),j)==f.end()){
							c++;
							r.push_back({i,j});
						}
					}//从其它节点选两个
					if(c<2) continue;
					cout<<"Yes"<<endl;
					cout<<r.size()<<endl;
					for(auto[u,v]:r) cout<<u<<" "<<v<<endl;
					w=true;
					break;
				}
			}
		}
	}
	if(!w) cout<<"No"<<endl;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		solve();
	}
}
