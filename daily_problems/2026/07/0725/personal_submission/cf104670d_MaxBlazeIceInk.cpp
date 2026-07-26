#include<bits/stdc++.h>
using namespace std;

#define MAXN 1005

int n,m,dis[MAXN][MAXN],dx[4][2] = {{-1,0},{0,-1},{1,0},{0,1}};
int ava[MAXN][MAXN],vis[MAXN][MAXN];
char s[MAXN][MAXN],ord[100005];

signed main(){
	scanf("%d%d",&m,&n);
	for( int i = 1 ; i <= n ; i ++ ) scanf("%s",s[i] + 1);
	scanf("%s",ord + 1); int L = strlen( ord + 1 );
	queue< pair<int,int> > Q;
	int sx = 0,sy = 0;
	for( int i = 1 ; i <= n ; i ++ ){
		for( int j = 1 ; j <= m ; j ++ ){
			dis[i][j] = (int)1e7;
			if( s[i][j] == 'S' ) dis[i][j] = 0,sx = i,sy = j;
		}
	}
	Q.push( make_pair( sx , sy ) );
	while( !Q.empty() ){
		int x = Q.front().first,y = Q.front().second; Q.pop();
		if( vis[x][y] ) continue;
		vis[x][y] = 1;
		for( int k = 0 ; k < 4 ; k ++ ){
			int nx = x + dx[k][0],ny = y + dx[k][1];
			if( nx < 1 || nx > n || ny < 1 || ny > m || s[nx][ny] == '#' ) continue;
			if( dis[nx][ny] == (int)1e7 )
				dis[nx][ny] = dis[x][y] + 1,Q.push( make_pair( nx , ny ) );
		}
	}
	for( int i = 1 ; i <= n ; i ++ )
		for( int j = 1 ; j <= m ; j ++ ) vis[i][j] = 0;
	Q.push( make_pair( sx , sy ) ); ava[sx][sy] = 1;
	while( !Q.empty() ){
		int x = Q.front().first,y = Q.front().second; Q.pop();
		if( !ava[x][y] || vis[x][y] ) continue;
		vis[x][y] = 1;
		for( int k = 0 ; k < 4 ; k ++ ){
			int nx = x + dx[k][0],ny = y + dx[k][1];
			if( nx < 1 || nx > n || ny < 1 || ny > m || s[nx][ny] == '#' || dis[nx][ny] != dis[x][y] + 1 ) continue;
			int id = dis[x][y] + 1;
			if( ord[id] == 'N' && k == 0 ) continue;
			if( ord[id] == 'W' && k == 1 ) continue;
			if( ord[id] == 'S' && k == 2 ) continue;
			if( ord[id] == 'E' && k == 3 ) continue;
			ava[nx][ny] = 1,Q.push( make_pair( nx , ny ) );
			if( dis[nx][ny] == L ) s[nx][ny] = '!';
		}
	}
	for( int i = 1 ; i <= n ; i ++ , puts("") )
		printf("%s",s[i] + 1);
	return 0;
}