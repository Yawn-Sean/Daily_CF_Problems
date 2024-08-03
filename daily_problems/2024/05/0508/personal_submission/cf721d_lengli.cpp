// Problem: D. Maxim and Array
// Contest: Codeforces - Codeforces Round 374 (Div. 2)
// URL: https://codeforces.com/problemset/problem/721/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms

/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define endl '\n'
#define all(x) x.begin(),x.end()
#define pb push_back
#define int long long

using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) "lengli"
#endif

const int N=100010;

void solve(){
	int n,k,x;
	cin>>n>>k>>x;
	set<array<int,2>> s;
	vector<int> a(n+1);
	
	int flag=1;
	
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<0) flag^=1;
		s.insert({abs(a[i]),i});
	}
	
	auto it=s.begin();
	if((*it)[0]>=k*x and flag){
		auto idx=(*it)[1];
		if(a[idx]>0) a[idx]-=k*x;
		else a[idx]+=k*x;
		for(int i=1;i<=n;i++) cout<<a[i]<<" ";
		cout<<endl;
	}else{
		if(flag){
			it=s.begin();
			auto idx=(*it)[1];
			int nd=abs(a[idx])/x+1;
			k-=nd;
			if(a[idx]>=0) a[idx]-=nd*x;
			else a[idx]+=nd*x;
			s.erase(it);
			s.insert({abs(a[idx]),idx});
		}
		while(s.size() and k>0){
			auto idx=(*s.begin())[1];
			if(a[idx]>=0) a[idx]+=x;
			else a[idx]-=x;
			s.erase(s.begin());
			s.insert({abs(a[idx]),idx});
			k-=1;
		}
		for(int i=1;i<=n;i++) cout<<a[i]<<" ";
		cout<<endl;
	}
	
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
