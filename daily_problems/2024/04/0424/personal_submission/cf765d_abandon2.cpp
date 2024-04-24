// Problem: D. Artsem and Saunders
// Contest: Codeforces - Codeforces Round 397 by Kaspersky Lab and Barcelona Bootcamp (Div. 1 + Div. 2 combined)
// URL: https://codeforces.com/problemset/problem/765/D
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int f[N],h[N],g[N],t[N];

void solve(){
	int n;cin>>n;
	for(int i=1;i<=n;i++){
		cin>>f[i];
	}	

	int m=0;
	map<int,int>mp;
	for(int i=1;i<=n;i++){
		if(f[i]!=f[f[i]]){
			cout<<"-1\n";return;
		}
		if(!mp.count(f[i])){
			mp[f[i]]=1;
			m++;
			t[f[i]]=m;//题目信息
			h[m]=f[i];//去重后的f
		}
		g[i]=t[f[i]];
	}
	cout<<m<<"\n";
	for(int i=1;i<=n;i++){
		cout<<g[i]<<" ";
	}
	cout<<"\n";
	for(int i=1;i<=m;i++){
		cout<<h[i]<<" ";
	}
}


signed main()
{
	ios::sync_with_stdio(0),cin.tie(0);
	int tt=1;
	while(tt--)solve();
}


