#include<bits/stdc++.h>
using namespace std;

#define MAXN 200005
#define int __int128

int n,a[MAXN],cnt[MAXN];
vector<int> pos[MAXN],pre[MAXN];

inline int read(){
	int x = 0; char ch = getchar();
	while( ch < '0' || ch > '9' ) ch = getchar();
	while( ch >= '0' && ch <= '9' ) x = x * 10 + ch - 48,ch = getchar();
	return x;
}

int f[1 << 10][10],d[10][10],dp[1 << 10];

inline int SS( int x ){ return x * ( x + 1 ) / 2; }

inline int calc( int i , int j ){
	int pnt = cnt[j] - 1,res = 0;
	for( int k = cnt[i] - 1 ; k >= 0 ; k -- ){
		while( pnt > 0 && pos[j][pnt - 1] > pos[i][k] ) pnt --;
		if( pnt >= 0 && pos[j][pnt] > pos[i][k] ) res += cnt[j] - pnt;
	}
	return res;
}

signed main(){
	n = read();
	for( int i = 1 ; i <= n ; i ++ ) a[i] = read(),a[i] --,pos[a[i]].emplace_back( i ),cnt[a[i]] ++;
	for( int i = 0 ; i < 10 ; i ++ )
		for( int j = 0 ; j < 10 ; j ++ ) if( i != j ) d[i][j] = calc( i , j );
	for( int i = 0 ; i < 10 ; i ++ ){
		for( int S = 0 ; S < 1 << 10 ; S ++ ){
			if( S >> i & 1 ) continue;
			int res = 0;
			for( int j = 0 ; j < 10 ; j ++ ) if( S >> j & 1 ) res += d[i][j];
			f[S][i] = res;
			// if( f[S][i] ) cerr << i << " " << S << " " << f[S][i] << "\n";
		}
	}
	dp[0] = 0;
	for( int S = 1 ; S < 1 << 10 ; S ++ ){
		dp[S] = (int)1e18;
		for( int i = 0 ; i < 10 ; i ++ ){
			if( S >> i & 1 ){
				dp[S] = min( dp[S] , dp[S ^ ( 1 << i )] + f[S ^ ( 1 << i )][i] );
			}
		}
	}
	printf("%lld\n",(long long)( dp[1023] ));
	return 0;
}