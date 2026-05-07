#include<bits/stdc++.h>
using namespace std;

mt19937_64 rnd( 20070414 );
#define MAXN 1005

int n,m,dr[MAXN],dc[MAXN];

char to[200];

inline void solve(){
	scanf("%d%d",&n,&m);
	int X[3],Y[3];
	scanf("%d%d%d%d%d%d",&X[0],&Y[0],&X[1],&Y[1],&X[2],&Y[2]);
	int c = 0;
	while( 1 ){
		for( int i = 1 ; i <= n ; i ++ ) dr[i] = 0;
		for( int i = 1 ; i <= m ; i ++ ) dc[i] = 0;
		for( int i = 1 ; i <= n ; i ++ ) dr[i] = rnd() % 2 + 1,dr[i] += dr[i - 1];
		for( int i = 1 ; i <= m ; i ++ ) dc[i] = rnd() % 2 + 1,dc[i] += dc[i - 1];
		bool flag = 1;
		for( int i = 0 ; i < 3 ; i ++ ){
			for( int j = i + 1 ; j < 3 ; j ++ ){
				// int l = min( X[i] , X[j] ),r = max( X[i] , X[j] );
				// int l2 = min( Y[i] , Y[j] ),r2 = max( Y[i] , Y[j] );
				if( ( dr[X[i]] - dr[X[j]] + dc[Y[i]] - dc[Y[j]] ) % 3 == 0 ){ flag = 0; break; }
			}
		}
		if( flag ) break;
		c ++;
		if( c == 100 ){ puts("NO"); return; }
	}
		// for( int i = 1 ; i <= n ; i ++ ) cerr << dr[i] << " ";
		// cerr << "\n";
		// for( int i = 1 ; i <= m ; i ++ ) cerr << dc[i] << " ";
	puts("YES");
	int st = dr[1];
	for( int i = 1 ; i <= n ; i ++ ){
		int now = st;
		for( int j = 1 ; j <= m ; j ++ ){
			printf("%c",to[now]);
			now += ( dc[j + 1] - dc[j] ) % 3;
			now %= 3;
		}
		st += ( dr[i + 1] - dr[i] ) % 3;
		st %= 3;
		puts("");
	}
}

signed main(){
	to[0] = 'R',to[1] = 'G',to[2] = 'B';
	int t; scanf("%d",&t);
	while( t -- ) solve();
	return 0;
}