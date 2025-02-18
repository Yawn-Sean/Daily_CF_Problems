// Problem: C. Playing Piano
// Contest: Codeforces - Technocup 2019 - Elimination Round 3
// URL: https://codeforces.com/problemset/problem/1032/C
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// DateTime : 2025-01-23 20:35:03
// Author : sunyafei
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve(){
	int n;cin>>n;
	vector<int> a(n);
	for(int&x:a)cin>>x;
	
	vector<vector<int>> memo(n,vector<int>(5,-1));
	auto dfs=[&](auto&&dfs,int i,int j)->bool{
		if(i==n){
			return true;
		}
		if(memo[i][j]!=-1){
			return memo[i][j];
		}
		bool res=false;
		if(i==0){
			for(int k=0;k<5;k++){
				res|=dfs(dfs,i+1,k);
			}
		}else{
			if(a[i]>a[i-1]){
				for(int k=j+1;k<5;k++){
					res|=dfs(dfs,i+1,k);
				}
			}else if(a[i]==a[i-1]){
				for(int k=0;k<5;k++){
					if(k==j) continue;
					res|=dfs(dfs,i+1,k);
				}
			}else{
				for(int k=0;k<j;k++){
					res|=dfs(dfs,i+1,k);
				}
			}
		}
		return memo[i][j]=res;
	};
	bool ans=dfs(dfs,0,0);
	if(!ans) cout<<-1;
	else{
		vector<int> ans;
		auto print_ans=[&](auto&&print_ans,int i,int j)->void{
			if(i==n) return;
			bool final_res=dfs(dfs,i,j);
			if(i==0){
				for(int k=0;k<5;k++){
					if(dfs(dfs,i+1,k)==final_res){
						ans.push_back(k+1);
						print_ans(print_ans,i+1,k);
						break;
					}
				}
			}else{
				if(a[i]>a[i-1]){
					for(int k=j+1;k<5;k++){
						if(dfs(dfs,i+1,k)==final_res){
							ans.push_back(k+1);
							print_ans(print_ans,i+1,k);
							break;
						}
					}
				}else if(a[i]==a[i-1]){
					for(int k=0;k<5;k++){
						if(k==j) continue;
						if(dfs(dfs,i+1,k)==final_res){
							ans.push_back(k+1);
							print_ans(print_ans,i+1,k);
							break;
						}
					}
				}else{
					for(int k=0;k<j;k++){
						if(dfs(dfs,i+1,k)==final_res){
							ans.push_back(k+1);
							print_ans(print_ans,i+1,k);
							break;
						}
					}
				}
			}
		};
		print_ans(print_ans,0,0);
		for(int x:ans){
			cout<<x<<" ";
		}
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
