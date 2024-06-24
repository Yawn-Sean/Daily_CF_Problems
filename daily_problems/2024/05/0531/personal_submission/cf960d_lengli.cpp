// Problem: D. Full Binary Tree Queries
// Contest: Codeforces - Divide by Zero 2018 and Codeforces Round 474 (Div. 1 + Div. 2, combined)
// URL: https://codeforces.com/problemset/problem/960/D
// Memory Limit: 256 MB
// Time Limit: 4000 ms

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
	int n;
	cin>>n;
	vector<int> dx(70,0),cnt(70,0);
	
	for(int i=1;i<=61;i++){
		cnt[i]=(1ll<<i)-(1ll<<(i-1));
	}
	
	auto get_dep=[&](int x)->int{
		for(int i=1;i<=61;i++){
			if(((1ll<<i)-1)>=x) return i;
		}
		return -1;
	};
	
	auto rotate=[&](int x,int t){
		dx[x]+=t;
		dx[x]+=cnt[x];
		dx[x]%=cnt[x];
	};
	
	for(int i=1;i<=n;i++){
		int op;
		cin>>op;
		if(op==1){
			int x,t;
			cin>>x>>t;
			int dep=get_dep(x);
			bool flag=(t<0);
			t=abs(t)%cnt[dep];
			if(flag) t=cnt[dep]-t;
			rotate(dep,t);
		}else if(op==2){
			int x,t;
			cin>>x>>t;
			int dep=get_dep(x);
			bool flag=(t<0);
			t=abs(t)%cnt[dep];
			if(flag) t=cnt[dep]-t;
			for(int j=dep,k=t;j<=61;j++,k*=2){
				rotate(j,k);
			}
		}else{
			int x;
			cin>>x;
			vector<int> res;
			
			int k=get_dep(x);
			int ll=1ll<<(k-1);
			x=ll+((x-ll+cnt[k])%cnt[k]+dx[k])%cnt[k];
			
			while(x){
				int dep=get_dep(x);
				int l=1ll<<(dep-1);
				int idx=((x-l+cnt[dep])%cnt[dep]-dx[dep]+cnt[dep])%cnt[dep];
				res.pb(l+idx);
				//cout<<x<<"!"<<l<<" "<<idx<<" "<<dep<<" "<<dx[dep]<<endl;
				x/=2;
			}
			//debug(res);
			for(auto x:res) cout<<x<<" ";
			cout<<endl;
		}
		
		// for(int i=1;i<=5;i++) cout<<dx[i]<<" ";
		// cout<<endl;
	}
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
