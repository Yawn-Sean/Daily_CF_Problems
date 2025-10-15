// Problem: C. Cycle In Maze
// Contest: Codeforces - VK Cup 2017 - Qualification 1
// URL: https://codeforces.com/problemset/problem/769/C
// Memory Limit: 256 MB
// Time Limit: 15000 ms
// DateTime : 2025-01-01 14:39:37
// Author : sunyafei
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;

#define int long long

int dx[4]={1,0,0,-1},dy[4]={0,-1,1,0};

void solve(){
	int n,m,k;cin>>n>>m>>k;
	vector<string> a(n);
	int x=0,y=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
		for(int j=0;j<m;j++){
			if(a[i][j]=='X'){
				x=i;
				y=j;	
			}
		}
	}
	if(k%2==1)cout<<"IMPOSSIBLE";
	else{
		vector<vector<int>> dis(n,vector<int>(m,-1));
		dis[x][y]=0;
		queue<pair<int,int>> q;
		q.emplace(x,y);
		while(!q.empty()){
			auto [i,j]=q.front();
			q.pop();
			for(int d=0;d<4;d++){
				int nx=dx[d]+i,ny=dy[d]+j;
				if(nx>=0&&nx<n&&ny>=0&&ny<m&&a[nx][ny]!='*'&&dis[nx][ny]==-1){
					dis[nx][ny]=dis[i][j]+1;
					q.emplace(nx,ny);
				}
			}
		}
		string ans;
		string alp="DLRU";
		auto dfs=[&](auto&&dfs,int i,int j,int cnt)->void{
			if(cnt==0) return;
			for(int d=0;d<4;d++){
				int nx=dx[d]+i,ny=dy[d]+j;
				if(nx>=0&&nx<n&&ny>=0&&ny<m&&a[nx][ny]!='*'&&dis[nx][ny] <=cnt-1){
					ans+=alp[d];
					dfs(dfs,nx,ny,cnt-1);
					break;
				}
			}
		};
		dfs(dfs,x,y,k);
		int m=ans.length();
		if(m==0) cout<<"IMPOSSIBLE";
		else {
			cout<<ans;
		}
	}
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t=1;
	//cin>>t;
	while(t--){
		solve();
		if(t)cout<<"\n";
	}
	return 0;
}
