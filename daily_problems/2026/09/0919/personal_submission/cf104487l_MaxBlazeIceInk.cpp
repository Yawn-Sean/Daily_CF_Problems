#include<bits/stdc++.h>
using namespace std;

#define int long long
#define double long double
#define MAXN 205

int n,X[MAXN],Y[MAXN];

inline int dis( int i , int j ){
	return ( X[i] - X[j] ) * ( X[i] - X[j] ) + ( Y[i] - Y[j] ) * ( Y[i] - Y[j] );
}

__int128 Gcd( __int128 x , __int128 y ){ return y ? Gcd( y , x % y ) : x; }

//比较分数可以约分

inline void solve(){
	scanf("%lld",&n);
	for( int i = 1 ; i <= n ; i ++ ) scanf("%lld%lld",&X[i],&Y[i]);
	int Ans = 2;
	for( int i = 1 ; i <= n ; i ++ ){
		for( int j = i + 1 ; j <= n ; j ++ ){
			if( i == j ) continue;
			map< pair<__int128,__int128> , int > M;
			for( int k = 1 ; k <= n ; k ++ ){
				if( k == i || k == j ) continue;
				__int128 A = dis( i , k ),B = dis( j , k ),C = dis( i , j );
				//A ^ 2 + B ^ 2 - C ^ 2 = 2ABcosx
				if( __int128( A + B - C ) * ( A + B - C ) == __int128(4) * A * B ) continue;
				__int128 xx = ( A + B - C ) * ( A + B - C ),yy = A * B,g = Gcd( xx , yy );
				xx /= g,yy /= g;
				__int128 dx1 = X[i] - X[k],dx2 = X[j] - X[k];
				__int128 dy1 = Y[i] - Y[k],dy2 = Y[j] - Y[k];
				bool f = ( dx1 * dy2 - dx2 * dy1 < 0 ) ^ ( A + B - C < 0 );
				pair<__int128,__int128> p = make_pair( f ? xx : -xx , yy );
				Ans = max( Ans , ++ M[p] + 2 );
				// cerr << i << " " << j << " " << k << " " << "(" << A + B - C << "," << A * B  << "\n";
			}
		}
	}
	printf("%lld\n",Ans);
}

signed main(){
	int t; scanf("%lld",&t);
	while( t -- ) solve();
	return 0;
}