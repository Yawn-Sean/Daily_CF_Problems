// Problem: D. Block Tower
// Contest: Codeforces - Codeforces Round 191 (Div. 2)
// URL: https://codeforces.com/problemset/problem/327/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// DateTime : 2024-12-30 14:37:27
// Author : sunyafei
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;

#define int long long

const int dx[4]={-1,0,0,1},dy[4]={0,-1,1,0};

void solve(){
	int n,m;cin>>n>>m;
	vector<vector<char>> a(n+1,vector<char>(m+1));
	vector<string> ans;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[i][j];
			if(a[i][j]=='.'){
				ans.push_back("B "+to_string(i)+" "+to_string(j)+"\n");
			}
		}
	}
	
	auto check=[&](int x,int y){
		return x>=1&&x<=n&&y>=1&&y<=m;
	};
	vector<pair<int,int>> b;
	auto dfs=[&](auto&&dfs,int i,int j)->void{
		for(int k=0;k<4;k++){
			int nx=i+dx[k],ny=j+dy[k];
			if(check(nx,ny)&&a[nx][ny]=='.'){
				a[nx][ny]='#';
				b.emplace_back(nx,ny);
				dfs(dfs,nx,ny);
			}
		}
	};
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i][j]=='.'){
				a[i][j]='#';
				dfs(dfs,i,j);
			}
		}
	}
	reverse(b.begin(),b.end());
	cout<<ans.size()+2*b.size()<<"\n";
	for(auto&s:ans){
		cout<<s;
	}
	for(auto&[x,y]:b){
		cout<<"D "<<x<<" "<<y<<"\n";
		cout<<"R "<<x<<" "<<y<<"\n";
	}
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t=1;
	// cin>>t;
	while(t--){
		solve();
		if(t)cout<<"\n";
	}
	return 0;
}
