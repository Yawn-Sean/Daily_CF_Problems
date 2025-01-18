// Problem: C. Basic Diplomacy
// Contest: Codeforces - Технокубок 2021 - Финал
// URL: https://codeforces.com/problemset/problem/1482/C
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// DateTime : 2025-01-17 20:05:37
// Author : sunyafei
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve(){
	int n,m;cin>>n>>m;
	vector<int> cnt(n+1);
	vector<vector<int>> a(m);
	for(int i=0;i<m;i++){
		int k;cin>>k;
		a[i]=vector<int> (k);
		for(int j=0;j<k;j++){
			cin>>a[i][j];
		}
	}
	vector<int> idx(m);
	iota(idx.begin(),idx.end(),0);
	sort(idx.begin(),idx.end(),[&](auto& i,auto& j){
		return a[i].size()<a[j].size();
	});
	vector<int> ans(m);
	for(int ii=0;ii<m;ii++){
		int i=idx[ii];
		if(a[i].size()==1){
			cnt[a[i][0]]++;
			ans[i]=a[i][0];
		}else{
			int mn=INT_MAX,id=-1;
			for(int j=0;j<a[i].size();j++){
				if(cnt[a[i][j]]<mn){
					mn=cnt[a[i][j]];
					id=a[i][j];
				}
			}
			if(id!=-1){
				cnt[id]++;
				ans[i]=id;
			}
		}
	}
	int mx=*max_element(cnt.begin()+1,cnt.end());
	if(mx>(m+1)/2){
		cout<<"NO";
	}else{
		cout<<"YES\n";
		for(int x:ans)cout<<x<<" ";
	}
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t=1;
	cin>>t;
	while(t--){
		solve();
		if(t)cout<<"\n";
	}
	return 0;
}
