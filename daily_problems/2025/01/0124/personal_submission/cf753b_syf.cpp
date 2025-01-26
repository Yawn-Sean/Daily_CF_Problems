// Problem: B. Interactive Bulls and Cows (Easy)
// Contest: Codeforces - Testing Round 13
// URL: https://codeforces.com/problemset/problem/753/B
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// DateTime : 2025-01-24 09:11:15
// Author : sunyafei
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve(){
	int i=0;
	vector<int> res;
	while(i<50){
		if(i<10){
			for(int j=0;j<4;j++){
				cout<<i;
			}
			cout<<endl;
			int a,b;cin>>a>>b;
			if(a==1) res.push_back(i);
		}else{
			do{
				for(int j=0;j<4;j++){
					cout<<res[j];
				}
				cout<<endl;
				int a,b;cin>>a>>b;
				if(a==4&&b==0){
					return;
				}
			}while(next_permutation(res.begin(),res.end()));
		}
		i++;
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
