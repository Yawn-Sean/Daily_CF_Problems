// Problem: C. Three Base Stations
// Contest: Codeforces - Codeforces Beta Round 48
// URL: https://codeforces.com/problemset/problem/51/C
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// DateTime : 2024-12-30 12:01:11
// Author : sunyafei
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve(){
	int n;cin>>n;
	vector<int> a(n);
	for(auto&x:a){
		cin>>x;
		x*=1000000;
	}
	sort(a.begin(),a.end());
	
	auto check=[&](int mid){
		int cnt=0;
		int cur=LLONG_MIN/2;
		for(int x:a){
			if(cur+mid<x){
				cnt++;
				cur=x+mid;
			}
		}
		return cnt<=3;
	};
	
	
	int l=0,r=1e15;
	while(l<=r){
		int mid=l+(r-l)/2;
		if(check(mid)) r=mid-1;
		else l=mid+1;
	}
	cout<<setprecision(6)<<fixed<<(1.0*l/1000000)<<"\n";
	int cur=LLONG_MIN/2;
	int cnt=3;
	for(int x:a){
		if(cur+l<x){
			cnt--;
			cur=x+l;
			cout<<setprecision(6)<<fixed<<(1.0*cur/1000000)<<" ";
		}
	}
	for(int i=0;i<cnt;i++){
		cout<<setprecision(6)<<fixed<<(1.0*a[0]/1000000)<<" ";
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
