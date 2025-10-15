#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n, k, u, v;
vector<int> e[N];
int d[N], pre[N];
int st, ed;
bool flag;
void dfs1(int u, int fa, int h){
	pre[u]=fa;
	if(h==2*k+1){
		ed=u;
		return;
	}
	for(auto v:e[u]){
		if(v==fa) continue;
		dfs1(v, u, h+1);	
	}
	return;
}
void dfs2(int u, int fa, int h){
	if(h==k){
		if(d[u]!=1) flag=1;
		return;
	}
	if(u!=ed&& d[u]<4){
		flag=1;
		return;
	}
	for(auto v:e[u]){
		if(v==fa) continue;
		dfs2(v, u, h+1);	
	}
	return;
}
int main(){
	cin>>n>>k;
	for(int i=1;i<n;i++){
		cin>>u>>v;
		e[u].push_back(v);
		e[v].push_back(u);
		d[u]++; d[v]++;
	}
	for(int i=1;i<=n;i++){
		if(d[i]==1){
			st=i;
			break;
		}
	}
	dfs1(st, -1, 1);
	if(ed==0){//防止k过大的时候tle
		cout<<"No";
		return 0;
	}
	for(int i=1;i<=k;i++){//
		ed=pre[ed];
	}
	if(d[ed]<3){//
		cout<<"No";
		return 0;
	}
	dfs2(ed, -1, 0);
	if(flag) cout<<"No";
	else cout<<"Yes";
	return 0;
}
