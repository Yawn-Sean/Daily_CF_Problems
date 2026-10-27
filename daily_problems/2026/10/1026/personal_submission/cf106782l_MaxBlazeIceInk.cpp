#include<bits/stdc++.h>
using namespace std;

#define MAXN 105
int ans[MAXN][MAXN];
int has[2][MAXN][MAXN],dx[4][3] = {{0,0,0},{0,-1,0},{1,0,-1},{1,0,0}};

inline int Ask( int x , int y ){
	printf("? %d %d\n",x,y);
	fflush( stdout );
	char s[4]; scanf("%s",s + 1);
	if( s[1] == 'U' ) return 0;
	else if( s[1] == 'R' ) return 1;
	else if( s[1] == 'D' ) return 2;
	return 3;
}

int n,m;

signed main(){
	scanf("%d%d",&n,&m);
	for( int j = 2 ; j <= m ; j += 2 ){
		for( int i = 2 ; i <= n ; i += 2 ){
			int st = Ask( i , j );
			has[0][i][j] = -1;
			has[0][i - 1][j] = -1;
			has[1][i][j - 1] = -1;
			has[1][i][j] = -1;
			if( st == 0 ) has[0][i][j] = 1;
			if( st == 2 ) has[0][i - 1][j] = 1;
			if( st == 1 ) has[1][i][j - 1] = 1;
			if( st == 3 ) has[1][i][j] = 1;
		}
	}
	while( 1 ){
		bool f = 1;
		for( int i = 1 ; i < n ; i ++ )
			for( int j = 1 ; j <= m ; j ++ )
				if( !has[0][i][j] ) f = 0;
		for( int i = 1 ; i <= n ; i ++ )
			for( int j = 1 ; j < m ; j ++ )
				if( !has[1][i][j] ) f = 0;
		if( f ) break;
		for( int i = 1 ; i <= n ; i ++ ){
			for( int j = 1 ; j <= m ; j ++ ){
				int st1 = 0,tot = 0,cn1 = 0;
				for( int k = 0 ; k < 4 ; k ++ ){
					int t = dx[k][0],nx = i + dx[k][1],ny = j + dx[k][2];
					if( t == 0 && ( nx < 1 || nx >= n || ny < 1 || ny > m ) ) continue;
					if( t == 1 && ( nx < 1 || nx > n || ny < 1 || ny >= m ) ) continue;
					if( has[t][nx][ny] == 1 ) st1 ++;
					if( has[t][nx][ny] == -1 ) cn1 ++;
					tot ++;
				}
				if( st1 ){
					for( int k = 0 ; k < 4 ; k ++ ){
						int t = dx[k][0],nx = i + dx[k][1],ny = j + dx[k][2];
						if( t == 0 && ( nx < 1 || nx >= n || ny < 1 || ny > m ) ) continue;
						if( t == 1 && ( nx < 1 || nx > n || ny < 1 || ny >= m ) ) continue;
						if( has[t][nx][ny] == 0 ) has[t][nx][ny] = -1;
					}
				}
				if( cn1 == tot - 1 ){
					for( int k = 0 ; k < 4 ; k ++ ){
						int t = dx[k][0],nx = i + dx[k][1],ny = j + dx[k][2];
						if( t == 0 && ( nx < 1 || nx >= n || ny < 1 || ny > m ) ) continue;
						if( t == 1 && ( nx < 1 || nx > n || ny < 1 || ny >= m ) ) continue;
						if( has[t][nx][ny] == 0 ) has[t][nx][ny] = 1;
					}
				}
			}
		}
	}
	puts("!");
	for( int i = 1 ; i <= n ; i ++ , puts("") )
		for( int j = 1 ; j <= m ; j ++ ){
			for( int k = 0 ; k < 4 ; k ++ ){
				int t = dx[k][0],nx = i + dx[k][1],ny = j + dx[k][2];
				if( t == 0 && ( nx < 1 || nx >= n || ny < 1 || ny > m ) ) continue;
				if( t == 1 && ( nx < 1 || nx > n || ny < 1 || ny >= m ) ) continue;
				if( has[t][nx][ny] == 1 ){
					if( k == 0 ) putchar('U');
					if( k == 1 ) putchar('D');
					if( k == 2 ) putchar('R');
					if( k == 3 ) putchar('L');
				}
			}
		}
	fflush( stdout );
	return 0;
}