// Problem: A. Thor
// Contest: Codeforces - Codeforces Round 366 (Div. 1)
// URL: https://codeforces.com/problemset/problem/704/A
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// DateTime : 2025-01-04 16:02:19
// Author : sunyafei
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve(){
	int n,q;cin>>n>>q;
	vector<array<int,2>> cnt(n+1);
	vector<int> st;
	int sum=0,i=0;
	while(q--){
		int op,x;cin>>op>>x;
		if(op==1){
			cnt[x][0]++;
			sum++;
			st.push_back(x);
		}else if(op==2){
			sum-=cnt[x][0];
			cnt[x][0]=0;
			cnt[x][1]=st.size();
		}else{
			while(i<x){
				if(i>=cnt[st[i]][1]){
					sum--;
					cnt[st[i]][0]--;
				}
				i++;
			}
		}
		cout<<sum<<"\n";
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
