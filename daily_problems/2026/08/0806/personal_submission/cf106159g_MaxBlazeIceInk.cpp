#include<bits/stdc++.h>
using namespace std;

#define int long long
#define MAXN 100005

int n,a[MAXN],P[MAXN],p[MAXN],f[MAXN],siz[MAXN],fro[MAXN],vis[MAXN];

int find( int x ){ return f[x] == x ? x : f[x] = find( f[x] ); }

inline int cmp( int x , int y ){ return a[x] < a[y]; }

signed main(){
	scanf("%lld",&n);
	for( int i = 1 ; i <= n ; i ++ ) scanf("%lld",&a[i]),P[i] = i,f[i] = i,siz[i] = 1;
	for( int i = 1 ; i <= n ; i ++ ) scanf("%lld",&p[i]),fro[p[i]] = i;
	sort( P + 1 , P + n + 1 , cmp );
	int ans = 0,Ans = 0;
	for( int i = n ; i >= 1 ; i -- ){
		int I = P[i];
		int u = p[I],v = fro[I];
		if( !vis[u] && !vis[v] ) ans ++,Ans = max( Ans , ans * a[I] );
		else if( !vis[u] || !vis[v] ){
			if( !vis[u] ) swap( u , v );
			u = find( u );
			ans -= ( siz[u] + 1 ) / 2;
			f[I] = u,siz[u] ++;
			ans += ( siz[u] + 1 ) / 2;
			Ans = max( Ans , ans * a[I] );
		}
		else{
			u = find( u ),v = find( v );
			if( u != v ){
				ans -= ( siz[u] + 1 ) / 2 + ( siz[v] + 1 ) / 2;
				ans += siz[u] / 2 + siz[v] / 2 + 1;
				Ans = max( Ans , ans * a[I] );
				ans -= siz[u] / 2 + siz[v] / 2 + 1;
				siz[I] = siz[u] + siz[v] + 1;
				f[u] = f[v] = I;
				ans += ( siz[I] + 1 ) / 2;
			}
			else{
				ans -= ( siz[u] + 1 ) / 2;
				siz[I] = siz[u] + 1,f[u] = f[v] = I;
				ans += siz[I] / 2;
				Ans = max( Ans , ans * a[I] );
			}
		}
		// cerr << ans << "\n";
		vis[I] = 1;
	}
	printf("%lld\n",Ans);
	return 0;
}