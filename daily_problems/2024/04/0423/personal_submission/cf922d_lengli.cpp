// Problem: D. Robot Vacuum Cleaner
// Contest: Codeforces - Codeforces Round 461 (Div. 2)
// URL: https://codeforces.com/problemset/problem/922/D
// Memory Limit: 256 MB
// Time Limit: 1000 ms

/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define endl '\n'
#define all(x) x.begin(),x.end()
#define pb push_back

using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) "lengli"
#endif

const int N=100010;

void solve(){
	int n;
	cin>>n;
	vector<string> a(n);
	string str="";
	vector<array<int,3>> q;
	for(int i=0;i<n;i++){
		cin>>a[i];
		int s=0,h=0;
		for(auto x:a[i]){
			if(x=='s') s++;
			else h++;
		}
		q.pb({s,h,i});
	}
	sort(all(q),[&](auto l,auto r){
		return (long long)l[0]*r[1]>(long long)l[1]*r[0];
	});
	for(auto [cs,ch,id]:q) str+=a[id];
	long long res=0,cnt=0;
	reverse(all(str));
	for(auto x:str){
		if(x=='h') cnt++;
		else res+=cnt;
	}
	cout<<res;
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
