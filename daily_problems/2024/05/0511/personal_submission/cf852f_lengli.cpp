// Problem: F. Product transformation
// Contest: Codeforces - Bubble Cup X - Finals [Online Mirror]
// URL: https://codeforces.com/problemset/problem/852/F
// Memory Limit: 256 MB
// Time Limit: 3000 ms

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

const int N=1000210;

int M;
int aa[N],bb[N];
int inv[N];
 
void init(){
	inv[1] = 1;
	for(int i = 2;i < N;i++)  inv[i] = (M -  M / i + M)%M * inv[M % i]%M;
	aa[0]=1,bb[0]=1;
	for(int i=1;i<N;i++) aa[i]=(i*aa[i-1])%M;
	for(int i=1;i<N;i++) bb[i]=(inv[i]*bb[i-1])%M;
}
 
int C(int x, int y) {
	return x < y || y < 0 ? 0 : aa[x] * bb[y] %M  * bb[x - y] %M;
}

int qmi(int a,int b,int M){
	int res=1;
	while(b){
		if(b&1) res=(res*a)%M;
		a=(a*a)%M;
		b/=2;
	}
	return res%M;
}

void solve(){
	int n,m,a,q;
	cin>>n>>m>>a>>q;
	M=1;
	int MM=a;
	while(MM%q!=1) MM=(a*MM)%q,M++;
	init();
	int sum=0;
	vector<int> res;
	for(int i=1;i<=n;i++){
		int t=C(m,i-1);
		sum+=t;sum%=M;
		res.pb(qmi(a,sum,q));
	}
	reverse(all(res));
	for(auto x:res) cout<<x<<" ";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
