#include<bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define MAXN 1005

int h,w,k,val[20][MAXN][MAXN],xa,ya,xb,yb;

vector<int> dp[MAXN][MAXN];

inline int fp( int x , int p ){
	int res = 1;
	while( p ){
		if( p & 1 ) res = 1ll * res * x % mod;
		x = 1ll * x * x % mod;
		p >>= 1;
	}
	return res;
}

inline bool cmp( vector<int> A , vector<int> B ){
	long double d1 = 0,d2 = 0;
	for( int i = 0 ; i < 20 ; i ++ ) d1 += 1.0 * A[i] / ( i + 1 ),d2 += 1.0 * B[i] / ( i + 1 );
	return d1 <= d2;
}

signed main(){
	scanf("%d%d%d",&h,&w,&k);
	scanf("%d%d%d%d",&xa,&ya,&xb,&yb);
	for( int i = 1 ; i <= k ; i ++ ){
		int X1,Y1,X2,Y2;
		scanf("%d%d%d%d",&X1,&Y1,&X2,&Y2);
		int S = ( Y2 - Y1 + 1 ) * ( X2 - X1 + 1 );
		for( int j = X1 ; j <= X2 ; j ++ )
			for( int k = Y1 ; k <= Y2 ; k ++ )
				val[S - 1][j][k] ++;
	}
	for( int i = 0 ; i < 20 ; i ++ ) dp[xa][ya].emplace_back( val[i][xa][ya] );
	for( int i = xa ; i <= xb ; i ++ ){
		for( int j = ya ; j <= yb ; j ++ ){
			if( i == xa && j == ya ) continue;
			vector<int> S1 = dp[i][j - 1],S2 = dp[i - 1][j];
			S1.resize( 20 ),S2.resize( 20 );
			if( i > xa ) for( int k = 0 ; k < 20 ; k ++ ) S2[k] += val[k][i][j];
			if( j > ya ) for( int k = 0 ; k < 20 ; k ++ ) S1[k] += val[k][i][j];
			if( i == xa ) dp[i][j] = S1;
			else if( j == ya ) dp[i][j] = S2;
			else{
				if( cmp( S1 , S2 ) ) dp[i][j] = S1;
				else dp[i][j] = S2;
			}
		}
	}
	int ans = 0;
	for( int i = 0 ; i < 20 ; i ++ ){
		// cerr << dp[xb][yb][i] << "\n";
		ans = ( ans + 1ll * fp( ( i + 1 ) , mod - 2 ) * dp[xb][yb][i] % mod ) % mod;
	}
	printf("%d\n",ans);
	return 0;
}