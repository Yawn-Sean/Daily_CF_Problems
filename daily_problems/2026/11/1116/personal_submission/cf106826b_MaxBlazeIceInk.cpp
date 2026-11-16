#include<bits/stdc++.h>
using namespace std;

#define int long long
#define MAXN 200005
#define mod 998244353

int n,a[MAXN],p2[MAXN],deg[MAXN];
vector<int> E[MAXN];

//定根，定左右儿子，权值唯一确定

inline void solve(){
	scanf("%lld",&n);
	for( int i = 1 ; i < n ; i ++ ){
		int u,v; scanf("%lld%lld",&u,&v);
		deg[u] ++,deg[v] ++;
	}
	int c = 0,c2 = 0;
	for( int i = 1 ; i <= n ; i ++ ) c += deg[i] == 1,c2 += deg[i] == 2;
	int ans = ( p2[n - c] * c2 % mod + p2[n - c + 1] * c % mod ) % mod;
	// cerr << c << " " << c2 
	printf("%lld\n",ans);
	for( int i = 1 ; i <= n ; i ++ ) deg[i] = 0;
}

signed main(){
	p2[0] = 1;
	for( int i = 1 ; i < MAXN ; i ++ ) p2[i] = p2[i - 1] * 2 % mod;
	int t; scanf("%lld",&t);
	while( t -- ) solve();
	return 0;
}