// Problem: A. Graph and String
// Contest: Codeforces - AIM Tech Round (Div. 1)
// URL: https://codeforces.com/problemset/problem/623/A
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
using namespace std;
const int N=550,M=250*510;
int col[N],g[N][N];
vector<int>e[M];
int n,m;

bool dfs(int u,int c){
	if(e[u].size()==0){
		col[u]=4;
		return 0;
	}
	col[u]=c;
	for(int v:e[u]){
		if(!col[v]){
			if(dfs(v,c^1))//有奇环就一路返回
				return 1;
		}
		if(col[v]==c)
			return 1;
	}
	return 0;
}
void solve(){
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int u,v;cin>>u>>v;
		g[u][v]=g[v][u]=1;
	}
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++){
			if(!g[i][j])
				e[i].push_back(j),e[j].push_back(i);
		}
	
	for(int i=1;i<=n;i++){
		if(!col[i]){
			if(dfs(i,2)){
				cout<<"No\n";
				return;		
			}
		}
	}
	
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++){
			if(g[i][j]&&col[i]+col[j]==5){
				cout<<"No\n";return;
			}
		}
	cout<<"Yes\n";
	for(int i=1;i<=n;i++){
		if(col[i]==2)
			cout<<'a';
		else if(col[i]==3){
			cout<<"c";
		}
		else 
			cout<<"b";
	}
	
}

signed main()
{
	ios::sync_with_stdio(0),cin.tie(0);
	int tt=1;
	while(tt--)solve();
}


