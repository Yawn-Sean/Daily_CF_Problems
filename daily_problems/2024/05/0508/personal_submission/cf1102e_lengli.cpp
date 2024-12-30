// Problem: E. Monotonic Renumeration
// Contest: Codeforces - Codeforces Round 531 (Div. 3)
// URL: https://codeforces.com/problemset/problem/1102/E
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

const int N=100010,M=998244353;

vector<array<int,2>> merge_segment(vector<array<int,2>> q){
    vector<array<int,2>> p;
    sort(q.begin(),q.end());
    int l=-1,r=-1;
    for(array<int,2> t:q){
        if(l==-1) l=t[0],r=t[1];
        else if(t[0]>r) {
            p.push_back({l,r});
            l=t[0],r=t[1];
        }else r=max(r,t[1]);
    }
    if(l!=-1) p.push_back({l,r});
    return p;
}

int qmi(int a,int b){
	int res=1;
	while(b){
		if(b&1) res*=a;
		a*=a;
		b/=2;
		res%=M,a%=M;
	}
	return res%M;
}

void solve(){
	int n;
	cin>>n;
	vector<int> a(n+1);
	map<int,array<int,2>> q;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(q.count(a[i])) q[a[i]][1]=i;
		else q[a[i]][0]=q[a[i]][1]=i;
	}
	vector<array<int,2>> s;
	for(auto [x,t]:q) s.pb({t[0],t[1]});
	s=merge_segment(s);
	int t=s.size()-1;
	cout<<qmi(2,t);
	
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
