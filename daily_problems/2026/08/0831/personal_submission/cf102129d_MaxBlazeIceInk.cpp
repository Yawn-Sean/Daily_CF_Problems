#include<bits/stdc++.h>
#include<cassert>
using namespace std;

#define mod 1000000007
#define MAXN 130

int k,a[MAXN],b[MAXN],A[MAXN][MAXN];

struct term{
	int a[MAXN];
	term(){ memset( a , 0 , sizeof( a ) ); }
	inline int& operator []( int x ){ return a[x]; }
};

unordered_map<int,term> M;

inline void chkadd( int &x , int k ){ x += k; if( x >= mod ) x -= mod; }

inline term Next( term X ){
	term res;
	for( int i = 1 ; i < k ; i ++ ) chkadd( res[i + 1] , X[i] ); 
	for( int i = 1 ; i <= k ; i ++ ) chkadd( res[i] , 1ll * X[k] * a[k - i + 1] % mod );
	return res;
}

inline term Get( int x ){
	if( M.count( x ) ) return M[x];
	if( x % 2 ){
		int st = x / 2 + 1;
		term refe = Get( st ),res,now = refe;
		for( int i = 1 ; i <= k ; i ++ ){
			for( int j = 1 ; j <= k ; j ++ )
				chkadd( res[j] , 1ll * now[j] * refe[i] % mod );
			now = Next( now );
		}
		return M[x] = res;
	}
	else{
		return M[x] = Next( Get( x - 1 ) );
	}
}

inline int reduce( int x ){ return x < 0 ? x + mod : x; }

inline int inv( int x ){
	int res = 1,p = mod - 2;
	while( p ){
		if( p & 1 ) res = 1ll * res * x % mod;
		x = 1ll * x * x % mod;
		p >>= 1;
	}
	return res;
}

signed main(){
	scanf("%d",&k);
	for( int i = 1 ; i <= k ; i ++ ) scanf("%d",&a[i]);
	for( int i = 1 ; i <= k ; i ++ ) scanf("%d",&b[i]);
	for( int i = 1 ; i <= k ; i ++ ){ term tmp; tmp[i] = 1; M[i] = tmp; }
	for( int x = k + 1 ; x <= 100 * k ; x ++ ){
		term A;
		for( int i = 1 ; i <= k ; i ++ ){
			term tmp = M[x - i];
			for( int j = 1 ; j <= k ; j ++ )
				chkadd( A[j] , 1ll * tmp[j] * a[i] % mod );
		}
		M[x] = A;
	}
	term res = Get( b[k] + 1 );
	for( int i = 1 ; i <= k ; i ++ ) A[i][k + 1] = res[i];
	for( int i = 1 ; i <= k ; i ++ ){
		term P = Get( b[k] + 1 - b[i] );
		for( int j = 1 ; j <= k ; j ++ ) A[j][i] = P[j];
	}
	//c[1] * b[1][1] + c[2] * b[2][1] + ... = ans[1]
	for( int j = 1 ; j <= k ; j ++ ){
		int id = j;
		for( int i = j ; i <= k ; i ++ )
			if( A[i][j] ){ id = i; break; }
		for( int t = 1 ; t <= k + 1 ; t ++ ) swap( A[j][t] , A[id][t] );
		int iv = inv( A[id][j] );
		for( int i = 1 ; i <= k ; i ++ ){
			if( i == id ) continue;
			int coef = 1ll * A[i][j] * iv % mod;
			for( int t = j ; t <= k + 1 ; t ++ )
				A[i][t] = reduce( A[i][t] - 1ll * coef * A[id][t] % mod );
		}
		// cerr << "\n";
		// for( int i = 1 ; i <= k ; i ++ ){
			// for( int j = 1 ; j <= k + 1 ; j ++ ) cerr << A[i][j] << " "; cerr << "\n";
		// }
	}
	for( int i = 1 ; i <= k ; i ++ )
		printf("%lld ",1ll * A[i][k + 1] * inv( A[i][i] ) % mod);
	return 0;
}