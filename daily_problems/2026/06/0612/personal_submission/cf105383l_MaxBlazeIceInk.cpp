#include<bits/stdc++.h>
using namespace std;

#define MAXN 55
#define LOGN 31
#define mod 1000000007

int n,m,s,t,x,k;
int rk[LOGN][MAXN][MAXN],hsh[LOGN][MAXN][MAXN],g[LOGN][MAXN],ans[LOGN][MAXN],pw[MAXN];
pair<int,int> tmp[MAXN][MAXN];
vector< pair<int,int> > E[MAXN];

inline int fp( int x , int p ){
	int res = 1;
	while( p ){
		if( p & 1 ) res = 1ll * res * x % mod;
		x = 1ll * x * x % mod;
		p >>= 1;
	}
	return res;
}

inline void init(){
	map<int,int> M,R;
	for( int u = 1 ; u <= n ; u ++ )
		for( pair<int,int> p : E[u] ) M[p.second] = 1;
	int c = 0;
	for( pair<int,int> p : M ) R[p.first] = ++c;
	for( int u = 1 ; u <= n ; u ++ )
		for( pair<int,int> p : E[u] )
			rk[0][u][p.first] = R[p.second],hsh[0][u][p.first] = p.second;
}

signed main(){
	scanf("%d%d%d%d%d%d",&n,&m,&s,&t,&x,&k);
	for( int i = 1 ; i <= m ; i ++ ){
		int u,v,w; scanf("%d%d%d",&u,&v,&w);
		E[u].emplace_back( make_pair( v , w ) );
	}
	pw[0] = x;
	for( int i = 1 ; i < LOGN ; i ++ ) pw[i] = 1ll * pw[i - 1] * pw[i - 1] % mod;
	init();
	for( int j = 1 ; j < LOGN ; j ++ ){
		for( int u = 1 ; u <= n ; u ++ )	
			for( int v = 1 ; v <= n ; v ++ ) tmp[u][v] = make_pair( (int)1e9 , (int)1e9 );
		for( int u = 1 ; u <= n ; u ++ ){
			for( int v = 1 ; v <= n ; v ++ ){
				for( int w = 1 ; w <= n ; w ++ ){
					if( rk[j - 1][u][w] && rk[j - 1][w][v] ){
						pair<int,int> rks = make_pair( rk[j - 1][u][w] , rk[j - 1][w][v] );
						if( rks < tmp[u][v] ){
							tmp[u][v] = rks;
							hsh[j][u][v] = ( 1ll * hsh[j - 1][u][w] * pw[j - 1] % mod + hsh[j - 1][w][v] ) % mod;
						}
					}
				}
			}
		}
		//对排名做一个重整
		map< pair<int,int> , int > MM,RR;
		for( int u = 1 ; u <= n ; u ++ )
			for( int v = 1 ; v <= n ; v ++ )
				if( hsh[j][u][v] ) MM[tmp[u][v]] = 1;
		int c = 0;
		for( pair< pair<int,int> , int > p : MM ) RR[p.first] = ++c;
		for( int u = 1 ; u <= n ; u ++ )
			for( int v = 1 ; v <= n ; v ++ )
				if( hsh[j][u][v] ) rk[j][u][v] = RR[tmp[u][v]];
	}
	int c = 0,grd = 0;
	g[0][t] = 1;
	for( int j = LOGN - 1 ; j >= 0 ; j -- ){
		map< pair<int,int> , int > M,R;
		if( k >= 1 << j ){
			k -= 1 << j;
			for( int i = 1 ; i <= n ; i ++ ){
				for( int v = 1 ; v <= n ; v ++ ){
					if( g[c][v] && rk[j][i][v] ){
						M[make_pair( rk[j][i][v] , g[c][v] )] = 1;
					}
				}
			}
			int cnt = 0;
			for( pair< pair<int,int> , int > p : M ) R[p.first] = ++cnt;
			for( int i = 1 ; i <= n ; i ++ ){
				int RR = (int)1e9; //开小了
				for( int v = 1 ; v <= n ; v ++ ){
					if( g[c][v] && rk[j][i][v] ){
						int rks = R[make_pair( rk[j][i][v] , g[c][v] )];
						if( rks < RR ){
							RR = rks;
							g[c + 1][i] = rks;
							ans[c + 1][i] = ( 1ll * hsh[j][i][v] * fp( x , grd ) % mod + ans[c][v] ) % mod;
							// if( i == 1 && c + 1 == 2 ) cerr << i << " " << v << "\n";
						}
					}
				}
			}
			//对排名做一个重整
			c ++;
			// map<int,int> MM,RR;
			// for( int u = 1 ; u <= n ; u ++ )
				// if( g[c][u] ) MM[g[c][u]] = 1;
			// cnt = 0;
			// for( pair<int,int> p : MM ) RR[p.first] = ++cnt;
			// for( int u = 1 ; u <= n ; u ++ )
				// if( g[c][u] ) g[c][u] = RR[g[c][u]];
			grd += 1 << j;
		}
	}
	// cerr << ans[s][1] << "\n";
	if( !g[c][s] ) puts("-1");
	else printf("%d\n",ans[c][s]);
	return 0;
}