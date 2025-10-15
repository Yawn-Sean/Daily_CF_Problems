// Problem: C. Save the Nature
// Contest: Codeforces - Technocup 2020 - Elimination Round 1
// URL: https://codeforces.com/problemset/problem/1223/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// DateTime : 2024-12-27 13:22:50
// Author : sunyafei
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve(){
	int n;cin>>n;
	vector<int> arr(n);
	for(int&x:arr){
		cin>>x;
		x/=100;
	}
	sort(arr.begin(),arr.end(),greater<>());
	int x,a,y,b;cin>>x>>a>>y>>b;
	if(x<y){
		swap(x,y);
		swap(a,b);
	}
	int k;cin>>k;
	auto check=[&](int mid)->bool{
		int cnt_a=mid/a,cnt_b=mid/b,cnt_ab=mid/lcm(a,b);
		int res=0;
		for(int i=0;i<cnt_ab;i++){
			res+=(x+y)*arr[i];
		}
		for(int i=cnt_ab;i<cnt_a;i++){
			res+=x*arr[i];
		}
		for(int i=cnt_a;i<cnt_a+cnt_b-cnt_ab;i++){
			res+=y*arr[i];
		}
		return res>=k;
	};
	
	int l=1,r=n;
	while(l<=r){
		int mid=l+(r-l)/2;
		if(check(mid)) r=mid-1;
		else l=mid+1;
	}
	if(l>n)cout<<-1;
	else cout<<l;
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
