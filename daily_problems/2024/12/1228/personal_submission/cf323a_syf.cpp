// Problem: A. Black-and-White Cube
// Contest: Codeforces - Testing Round 7
// URL: https://codeforces.com/problemset/problem/323/A
// Memory Limit: 256 MB
// Time Limit: 500 ms
// DateTime : 2024-12-28 22:09:08
// Author : sunyafei
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve(){
	int n;cin>>n;
	if(n%2==1)cout<<-1;
	else{
		char a[2]={'w','b'};
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				for(int k=0;k<n;k++){
					cout<<a[(i/2+j+k/2)%2];
				}
				cout<<"\n";
			}
			cout<<"\n";
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
