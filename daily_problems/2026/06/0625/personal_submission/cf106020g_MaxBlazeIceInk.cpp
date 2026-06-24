#include<bits/stdc++.h>
using namespace std;

#define int long long
#define MAXN 155
#define INF (int)1e18

int notp[1 << 20],prime[1 << 20],ptot;
int n,a[MAXN],f[MAXN][MAXN][MAXN][2][2],pos[1 << 20];

inline void pre(){
	notp[0] = notp[1] = 1;
	for( int i = 2 ; i < 1 << 20 ; i ++ ){
		if( !notp[i] ) prime[++ptot] = i;
		for( int j = 1 ; j <= ptot && i * prime[j] < 1 << 20 ; j ++ ){
			notp[i * prime[j]] = 1;
			if( i % prime[j] == 0 ) break;
		}
	}
}

inline void chkmax( int &x , int k ){ x = max( x , k ); }

inline void solve(){
	scanf("%lld",&n);
	for( int i = 1 ; i <= n ; i ++ ) scanf("%lld",&a[i]);
	for( int i = n ; i >= 1 ; i -- ) pos[a[i]] = i;
	for( int i = 0 ; i <= n ; i ++ ){
		for( int j = 0 ; j <= n ; j ++ ){
			for( int k = 0 ; k <= n ; k ++ ){
				f[i][j][k][0][0] = f[i][j][k][0][1] = 
				f[i][j][k][1][0] = f[i][j][k][1][1] = -INF;
			}
		}
	}
	f[0][0][0][0][0] = 0;
	int Ans = 0;
	for( int i = 1 ; i <= n ; i ++ ){
		for( int j = 0 ; j < i ; j ++ ){
			for( int k = 0 ; k < i ; k ++ ){
				if( j && k && j == k ) continue;
				if( j && a[j] % 2 == 0 ) continue;
				if( k && a[k] % 2 ) continue;
				for( int i1 = 0 ; i1 < 2 ; i1 ++ ){
					if( i1 && ( !pos[a[j] ^ 2] || pos[a[j] ^ 2] >= i ) ) continue;
					for( int i2 = 0 ; i2 < 2 ; i2 ++ ){
						if( i2 && ( !pos[a[k] ^ 2] || pos[a[k] ^ 2] >= i ) ) continue;
						vector< pair<int,int> > S,T;
						if( j ) S.emplace_back( make_pair( a[j] , j ) );
						if( k ) S.emplace_back( make_pair( a[k] , k ) );
						if( i1 && j && pos[a[j] ^ 2] ) S.emplace_back( make_pair( a[j] ^ 2 , pos[a[j] ^ 2] ) );
						if( i2 && k && pos[a[k] ^ 2] ) S.emplace_back( make_pair( a[k] ^ 2 , pos[a[k] ^ 2] ) );
						for( pair<int,int> p1 : S ){
							for( pair<int,int> p2 : S ){
								if( p1.second != p2.second && notp[p1.first ^ p2.first] ) continue;
							}
						}
						// for( pair<int,int> p : S ) cerr << p.first << " " << p.second << "\n";
						// cerr << "\n";
						int SS = 0;
						for( pair<int,int> ele : S )
							SS += ele.first;
						chkmax( f[i][j][k][i1][i2] , f[i - 1][j][k][i1][i2] + SS );
						chkmax( Ans , f[i][j][k][i1][i2] );
						SS = 0;
						// //只扔掉与 a[i] 不合法的
						for( pair<int,int> ele : S ) if( !notp[a[i] ^ ele.first] ) T.emplace_back( ele );
						T.emplace_back( make_pair( a[i] , i ) );
						// if( i == 3 ){
							// cerr << "asd\n";
							// cerr << j << " " << k << " " << i1 << " " << i2 << " " << f[i - 1][j][k][i1][i2] << "\n";
							// for( pair<int,int> ele : S ){
							// cerr << ele.first << " ";
							// }
							// cerr << "\n";
						// }
						int nj = 0,nk = 0,ni1 = 0,ni2 = 0;
						// cerr << T.size() << "\n";
						// assert( T.size() <= 4 );
						for( pair<int,int> ele : T ){
							SS += ele.first;
							if( ele.first % 2 ){
								if( !nj ) nj = ele.second;
								else ni1 = 1;
							}
							else{
								if( !nk ) nk = ele.second;
								else ni2 = 1;
							}
						}
						chkmax( f[i][nj][nk][ni1][ni2] , f[i - 1][j][k][i1][i2] + SS );
						chkmax( Ans , f[i][nj][nk][ni1][ni2] );
					}
				}
			}
		}
		// cerr << i << " " << Ans << "\n";
	}
	// cerr << f[3][1][0][1][0] << "\n";
	printf("%lld\n",Ans);
	for( int i = 0 ; i <= n ; i ++ ){
		for( int j = 0 ; j <= n ; j ++ ){
			for( int k = 0 ; k <= n ; k ++ ){
				f[i][j][k][0][0] = f[i][j][k][0][1] = 
				f[i][j][k][1][0] = f[i][j][k][1][1] = 0;
			}
		}
		pos[a[i]] = 0;
	}
}

signed main(){
	pre();
	int t; scanf("%lld",&t);
	while( t -- ) solve();
	return 0;
}