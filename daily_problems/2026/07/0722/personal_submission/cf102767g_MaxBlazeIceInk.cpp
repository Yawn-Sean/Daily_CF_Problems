#include<bits/stdc++.h>
using namespace std;

#define MAXN 100005

int Gcd( int x , int y ){ return y ? Gcd( y , x % y ) : x; }

int n,a[MAXN],p[MAXN];

//我好笨啊，我已笨哭

inline void solve(){
	scanf("%d",&n);
	for( int i = 1 ; i <= n ; i ++ ){
		scanf("%d",&a[i]);
		if( Gcd( a[i] , n ) == 1 ) p[i] = 1;
	}
	// if( n == 1 ){ puts("0"); return; }
	int l = 1,r = n,ans = 0;
	while( l <= n ){
		while( l <= n && !p[l] ) l ++;
		if( l > n ) break;
		r = l;
		while( r <= n && p[r] == 1 ) r ++;
		r --; //我刚才脑抽把这个删了
		map<int,int> M; int res = 1;
		// cerr << l << " " << r << "\n";
		for( int x = l ; x <= r ; x ++ ){
			res = 1ll * res * a[x] % n;
			if( M.count( res ) ){
				if( !ans ) ans = x - M[res];
				else ans = min( ans , x - M[res] );
			}
			if( res == 1 ){
				if( !ans ) ans = x - l + 1;
				else ans = min( ans , x - l + 1 );
			}
			M[res] = x;
		}
		l = r + 1;
	}
	printf("%d\n",ans);
	for( int i = 1 ; i <= n ; i ++ ) p[i] = 0;
}

signed main(){
	int t; scanf("%d",&t);
	while( t -- ) solve();
	return 0;
}