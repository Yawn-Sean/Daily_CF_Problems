#include<bits/stdc++.h>
using namespace std;

#define MAXN 40
int r,c,m,k,a[MAXN][MAXN];

inline void solve(){
	scanf("%d%d%d%d",&r,&c,&m,&k);
	if( k > min( r , c ) || k > m ){ puts("NO"); return; }
	int minn = k,maxx = k * max( r , c );
	if( m < minn || m > maxx ){ puts("NO"); return; }
	for( int i = 1 ; i <= r ; i ++ )
		for( int j = 1 ; j <= c ; j ++ ) a[i][j] = '.';
	for( int i = 1 ; i <= k ; i ++ ) a[i][k - i + 1] = '#';
	int cnt = k;
	//一个斜对角线是基础，剩下的随便填
	for( int i = 1 ; i <= r ; i ++ ){
		for( int j = 1 ; j <= c ; j ++ ){
			if( cnt >= m ) continue;
			if( a[i][j] != '#' ){
				if( r >= c && j <= k ) a[i][j] = '#',cnt ++;
				if( r < c && i <= k ) a[i][j] = '#',cnt ++;
			}
		}
	}
	puts("YES");
	for( int i = 1 ; i <= r ; i ++ , puts("") )
		for( int j = 1 ; j <= c ; j ++ ) printf("%c",(char)a[i][j]);
}

signed main(){
	int t; scanf("%d",&t);
	while( t -- ) solve();
	return 0;
}