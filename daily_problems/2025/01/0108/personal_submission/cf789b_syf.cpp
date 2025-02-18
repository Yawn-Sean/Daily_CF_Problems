// Problem: B. Masha and geometric depression
// Contest: Codeforces - Codeforces Round 407 (Div. 2)
// URL: https://codeforces.com/problemset/problem/789/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// DateTime : 2025-01-08 12:00:16
// Author : sunyafei
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve(){
	int b1,q,l,m;cin>>b1>>q>>l>>m;
	set<int> st;
	for(int i=0;i<m;i++){
		int x;cin>>x;
		st.insert(x);
	}
	if(b1==0){
		if(st.count(0)){
			cout<<0;
		}else{
			cout<<"inf";
		}
		return;
	}
	if(q==0){
		if(st.count(0)){
			if(st.count(b1)){
				cout<<0;
			}else if(abs(b1)<=l){
				cout<<1;
			}else{
				cout<<0;
			}
		}else{
			if(abs(b1)<=l)cout<<"inf";
			else cout<<0;
		}
		return;
	}
	if(q==1){
		if(st.count(b1)){
			cout<<0;
		}else if(abs(b1)<=l){
			cout<<"inf";
		}else{
			cout<<0;
		}
	}else if(q==-1){
		if(st.count(b1)&&st.count(-b1)){
			cout<<0;
		}else if(abs(b1)<=l){
			cout<<"inf";
		}else{
			cout<<0;
		}
	}else{
		int ans=0;
		for(int i=b1;abs(i)<=l;i*=q){
			if(!st.count(i)) ans++;
		}
		cout<<ans;
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
