// Problem: D. Misha and Permutations Summation
// Contest: Codeforces - Codeforces Round 285 (Div. 2)
// URL: https://codeforces.com/problemset/problem/501/D
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

using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) "lengli"
#endif

const int N=200010;

int n;
int cnt[N];

struct BIT{
	int n=N-1;
	int a[N];
	int lowbit(int x){return x&-x;}
	void add(int x,int c) {for(int i=x;i<=n;i+=lowbit(i)) a[i]+=c;}
	
	void init(){
		for(int i=0;i<=n;i++) a[i]=0; 
	};
	
	int sum(int x){
		long long res=0;
		for(int i=x;i;i-=lowbit(i)) res+=a[i];
		return res;
	}
	
	int find(int k){
		int l=1,r=n;
		while(l<r){
			int mid=(l+r)/2;
			if(sum(mid)>=k) r=mid;
			else l=mid+1;
		}
		return r;
	}
	
}tr;

void solve(){
	cin>>n;
	vector<int> s(n+1);
	
	tr.init();
	for(int i=1;i<=n;i++) cin>>s[i],s[i]++,tr.add(s[i],1);
	for(int i=1;i<=n;i++){
		cnt[i]+=tr.sum(s[i]-1);
		tr.add(s[i],-1);
	}
	tr.init();
	for(int i=1;i<=n;i++) cin>>s[i],s[i]++,tr.add(s[i],1);
	for(int i=1;i<=n;i++){
		cnt[i]+=tr.sum(s[i]-1);
		tr.add(s[i],-1);
	}
	for(int i=n;i>=1;i--){
		cnt[i-1]+=cnt[i]/(n-i+1);
		cnt[i]%=(n-i+1);
	}
	tr.init();
	for(int i=1;i<=n;i++) tr.add(i,1);
	
	for(int i=1;i<=n;i++){
		auto t=tr.find(cnt[i]+1);
		cout<<t-1<<" ";
		tr.add(t,-1);
	}
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
