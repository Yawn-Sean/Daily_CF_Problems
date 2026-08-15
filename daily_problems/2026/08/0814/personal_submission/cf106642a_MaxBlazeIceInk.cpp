#include<bits/stdc++.h>
using namespace std;

#define MAXN 55
#define INF (int)1e9

int n,len[MAXN],nxt[MAXN][26],fail[MAXN];
int cp[MAXN][MAXN][MAXN],cs[MAXN][MAXN][MAXN],pre[MAXN][MAXN][MAXN],suf[MAXN][MAXN][MAXN];
char s[MAXN][MAXN],P[MAXN];
int f[1 << 12][MAXN],id[MAXN];

inline void chkmax( int &x , int k ){ x = max( x , k ); }

signed main(){
	scanf("%d",&n);
	for( int i = 1 ; i <= n ; i ++ ) scanf("%s",s[i] + 1),len[i] = strlen( s[i] + 1 );
	scanf("%s",P + 1); int Len = strlen( P + 1 );
	queue<int> Q; Q.push( 1 );
	for( int i = 0 ; i < Len ; i ++ ) nxt[i][P[i + 1] - 'a'] = i + 1;
	while( !Q.empty() ){
		int u = Q.front(); Q.pop();
		for( int j = 0 ; j < 26 ; j ++ )
			if( nxt[u][j] ) fail[nxt[u][j]] = nxt[fail[u]][j],Q.push( nxt[u][j] );
			else nxt[u][j] = nxt[fail[u]][j];
	}
	// for( int i = 0 ; i <= Len ; i ++ ){
		// for( int j = 0 ; j < 2 ; j ++ ){
			// cerr << i << " " << j << " " << nxt[i][j] << "\n";
		// }
	// }
	for( int i = 1 ; i <= n ; i ++ ){
		for( int L = 0 ; L <= Len ; L ++ ){
			for( int j = 1 ; j <= len[i] ; j ++ ){
				int now = L,C = 0;
				for( int k = 1 ; k <= j ; k ++ ){
					now = nxt[now][s[i][k] - 'a']; C += now == Len;
					pre[i][j][L] = now,cp[i][j][L] = C;
				}
			}
		}
	}
	for( int i = 1 ; i <= n ; i ++ ){
		for( int L = 0 ; L <= Len ; L ++ ){
			for( int j = 1 ; j <= len[i] ; j ++ ){
				int now = L,C = 0;
				for( int k = j ; k <= len[i] ; k ++ ){
					now = nxt[now][s[i][k] - 'a']; C += now == Len;
					suf[i][j][L] = now,cs[i][j][L] = C;
				}
			}
		}
	}
	int Ans = 0;
	for( int i = 1 ; i <= n ; i ++ ){
		for( int j = 1 ; j <= len[i] ; j ++ ){
			for( int S = 0 ; S < 1 << ( n - 1 ) ; S ++ )
				for( int k = 0 ; k <= Len ; k ++ ) f[S][k] = -INF;
			int cnt = 0;
			for( int j = 1 ; j <= n ; j ++ ) if( j != i ) id[cnt] = j,cnt ++;
			f[0][suf[i][j][0]] = cs[i][j][0];
			for( int S = 0 ; S < 1 << ( n - 1 ) ; S ++ ){
				for( int t = 0 ; t <= Len ; t ++ ){
					for( int k = 0 ; k < n - 1 ; k ++ ){
						if( S >> k & 1 ) continue;
						int Nxt = pre[id[k]][len[id[k]]][t];
						chkmax( f[S ^ ( 1 << k )][Nxt] , f[S][t] + cp[id[k]][len[id[k]]][t] );
					}
				}
			}
			for( int k = 0 ; k <= Len ; k ++ )
				chkmax( Ans , f[( 1 << ( n - 1 ) ) - 1][k] + cp[i][j - 1][k] );
		}
	}
	printf("%d\n",Ans);
	return 0;
}