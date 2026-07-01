#include<bits/stdc++.h>
using namespace std;

#define int long long
#define mod 998244353
#define MAXN 600005

int n,x[MAXN],y[MAXN],siz[MAXN],e[MAXN],f[MAXN];
int inv[MAXN];

int find( int x ){ return f[x] == x ? x : f[x] = find( f[x] ); }

inline void solve(){
	scanf("%lld",&n);
	for( int i = 1 ; i <= 2 * n ; i ++ ) f[i] = i,siz[i] = 1;
	int ans = 1,cnt = 0;
	map<int,int> M;
	for( int i = 1 ; i <= n ; i ++ ){
		int u,v; scanf("%lld%lld",&u,&v);
		if( M.count( u ) ) u = M[u];
		else M[u] = ++cnt,u = M[u];
		if( M.count( v ) ) v = M[v];
		else M[v] = ++cnt,v = M[v];
		if( find( u ) != find( v ) ){
			u = find( u ),v = find( v );
			if( e[u] < siz[u] ) ans = ans * inv[siz[u]] % mod;
			else ans = ans * inv[2] % mod;
			if( e[v] < siz[v] ) ans = ans * inv[siz[v]] % mod;
			else ans = ans * inv[2] % mod;
			e[v] += e[u] + 1,siz[v] += siz[u],f[u] = v;
			if( e[v] < siz[v] ) ans = ans * siz[v] % mod;
			else if( e[v] == siz[v] ) ans = ans * 2 % mod;
			else ans *= 0;
		}
		else{
			u = find( u );
			if( e[u] < siz[u] ) ans = ans * inv[siz[u]] % mod;
			e[u] ++;
			if( e[u] < siz[u] ) ans = ans * siz[u] % mod;
			else if( e[u] == siz[u] ) ans = ans * 2 % mod;
			else ans *= 0;
		}
		printf("%lld ",ans);
	}
	puts("");
	for( int i = 1 ; i <= cnt ; i ++ ) siz[i] = e[i] = f[i] = 0;
}

signed main(){
	inv[1] = 1;
	for( int i = 2 ; i < MAXN ; i ++ ) inv[i] = ( mod - mod / i ) * inv[mod % i] % mod;
	int t; scanf("%lld",&t);
	while( t -- ) solve();
	return 0;
}