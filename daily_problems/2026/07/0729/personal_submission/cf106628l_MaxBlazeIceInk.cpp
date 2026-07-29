#include<bits/stdc++.h>
using namespace std;

#define int long long
#define MAXN 2005
#define mod 1000000007

int k,X[MAXN],Y[MAXN],iv[MAXN][MAXN],res[MAXN];

inline int fp( int x , int p ){
	int res = 1;
	while( p ){
		if( p & 1 ) res = res * x % mod;
		x = x * x % mod;
		p >>= 1;
	}
	return res;
}

inline void chkadd( int &x , int k ){ x += k; if( x >= mod ) x -= mod; }

signed main(){
	scanf("%lld",&k);
	for( int i = 1 ; i <= k + 2 ; i ++ ) scanf("%lld%lld",&X[i],&Y[i]);
	for( int i = 1 ; i <= k + 2 ; i ++ )
		for( int j = 1 ; j <= k + 2 ; j ++ )
			if( i != j ) iv[i][j] = fp( ( X[j] - X[i] + mod ) % mod , mod - 2 ) % mod;
	int ans0 = 0,id = 0;
	//钦定瑕疵在 1
	for( int i = 2 ; i <= k + 2 ; i ++ ){
		res[i] = 1;
		for( int j = 2 ; j <= k + 2 ; j ++ )
			if( i != j ) res[i] = res[i] * iv[i][j] % mod;
		chkadd( ans0 , res[i] * Y[i] % mod );
	}
	if( !ans0 ) id = 1;
	//钦定瑕疵在 i
	for( int i = 2 ; i <= k + 2 ; i ++ ){
		for( int j = 1 ; j <= k + 2 ; j ++ ){
			if( j != i && j != i - 1 ){
				res[j] = res[j] * ( X[i] - X[j] + mod ) % mod;	
				res[j] = res[j] * iv[j][i - 1] % mod;
			}
		}
		res[i - 1] = 1;
		for( int j = 1 ; j <= k + 2 ; j ++ )
			if( i != j && j != i - 1 ) res[i - 1] = res[i - 1] * iv[i - 1][j] % mod;
		ans0 = 0;
		for( int j = 1 ; j <= k + 2 ; j ++ )
			if( j != i )
				chkadd( ans0 , res[j] * Y[j] % mod );
		if( !ans0 ) id = i;
	}
	int Ans = 0;
	for( int i = 1 ; i <= k + 2 ; i ++ ){
		if( i == id ) continue;
		int res = 1;
		for( int j = 1 ; j <= k + 2 ; j ++ ){
			if( j == i || j == id ) continue;
			res = res * X[j] % mod * iv[i][j] % mod;
		}
		chkadd( Ans , res * Y[i] % mod );
	}
	printf("%lld\n",Ans);
	return 0;
}