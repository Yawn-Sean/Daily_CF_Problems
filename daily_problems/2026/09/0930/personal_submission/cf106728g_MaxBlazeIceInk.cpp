#include<bits/stdc++.h>
using namespace std;

#define MAXN 200005
#define int long long

int n,h[MAXN],s[MAXN],rk[MAXN],hs[MAXN],hcnt,tr[MAXN],Ans[MAXN];

inline void add( int x , int k ){ for( ; x <= hcnt ; x += x & -x ) tr[x] += k; }
inline int sum( int x ){ int ret = 0; for( ; x ; x -= x & -x ) ret += tr[x]; return ret; }

signed main(){
	scanf("%lld",&n);
	for( int i = 1 ; i <= n ; i ++ ) scanf("%lld",&h[i]),hs[++hcnt] = h[i];
	sort( hs + 1 , hs + hcnt + 1 );
	hcnt = unique( hs + 1 , hs + hcnt + 1 ) - ( hs + 1 );
	for( int i = 1 ; i <= n ; i ++ ) h[i] = lower_bound( hs + 1 , hs + hcnt + 1 , h[i] ) - hs;
	for( int i = 1 ; i <= n ; i ++ ) scanf("%lld",&s[i]);
	sort( s + 1 , s + n + 1 );
	priority_queue<int> Q;
	int pnt = 1;
	for( int i = n ; i >= 1 ; i -- ){
		while( pnt <= n && s[pnt] + i <= n ) Q.push( s[pnt] ),pnt ++;
		if( !Q.size() ){ puts("-1"); return 0; }
		rk[i] = Q.top(); Q.pop();
	}
	for( int i = 1 ; i <= n ; i ++ ) add( i , 1 );
	for( int i = 1 ; i <= n ; i ++ ){
		// cerr << i << " " << rk[i] << "\n";
		int l = 1,r = n,ans = -1;
		while( l <= r ){
			int mid = ( l + r ) >> 1;
			if( sum( mid ) >= rk[i] + 1 ) ans = mid,r = mid - 1;
			else l = mid + 1;
		}
		Ans[i] = hs[ans];
		add( ans , -1 );
	}
	for( int i = 1 ; i <= n ; i ++ ) printf("%lld ",Ans[i]);
	puts("");
	return 0;
}