// Problem: D. Inconvenient Pairs
// Contest: Codeforces - Educational Codeforces Round 113 (Rated for Div. 2)
// URL: https://codeforces.com/problemset/problem/1569/D
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
	int n,m,k;
	cin>>n>>m>>k;
	vector<int> X(n),Y(m);
	for(auto &x:X) cin>>x;
	for(auto &x:Y) cin>>x;
	vector<array<int,2>> q(k);
	for(auto &[x,y]:q) cin>>x>>y;
	
	auto get=[&](vector<array<int,2>> &a,vector<int> &idx){
		sort(all(a));
		int n=a.size(),m=idx.size();
		int l=0,r=-1;
		map<int,int> q;
		int res=0;
		for(int i=1,sum=0;i<m;i++){
			int L=idx[i-1],R=idx[i];
			while(r+1<n and a[r+1][0]>=L and a[r+1][0]<=R){
				if(a[r+1][0]!=L and a[r+1][0]!=R) q[a[r+1][1]]++,sum++;
				r++;
			}
			while(l<n and a[l][0]<=L){
				if(a[l][0]!=L and a[l][0]!=0) {
					q[a[l][1]]--;
					sum--;
					if(!q[a[l][1]]) q.erase(a[l][1]);
				}
				l++;
			}
			res+=sum*(sum-1)/2;
			for(auto [c,v]:q){
				if(v>=2) res-=(v-1)*v/2;
			}
		}
		return res;
	};
	
	int res=get(q,X);
	for(auto &[x,y]:q) swap(x,y);
	res+=get(q,Y);
	cout<<res<<endl;
}

signed main(){
    fastio;
    
    int T;
    cin>>T;
    while(T--) solve();
    
    return 0;
}
