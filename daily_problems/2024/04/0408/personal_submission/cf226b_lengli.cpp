// Problem: B. Naughty Stone Piles
// Contest: Codeforces - Codeforces Round 140 (Div. 1)
// URL: https://codeforces.com/problemset/problem/226/B
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
	int n;
	cin>>n;
	vector<int> a(n);
	vector<int> res(N,0);
	for(auto &x:a) cin>>x;
	sort(all(a),greater<>());
	
	for(int i=n-1,sum=0;i>0;i--){
		sum+=a[i];
		res[1]+=sum;
	}
	
	vector<int> b(n+1,0);
	for(int i=1;i<=n;i++) b[i]=a[i-1]+b[i-1];
	
	int q;
	cin>>q;
	while(q--){
		int k;
		cin>>k;
		if(res[k]) cout<<res[k]<<" ";
		else{
			int ans=0;
			for(int i=1,j=0,len=1;i<=n;len*=k,j++,i++){
				int l=i,r=min(n,i+len-1);
				ans+=(b[r]-b[l-1])*j;
				i=r;
			}
			cout<<ans<<" ";
			res[k]=ans;
		}
	}
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
