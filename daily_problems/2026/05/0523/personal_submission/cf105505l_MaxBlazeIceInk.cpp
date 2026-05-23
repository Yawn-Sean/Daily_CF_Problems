#include<bits/stdc++.h>
using namespace std;

#define MAXN 505
int n,q,r[MAXN],c[MAXN],vis[MAXN],vi2[MAXN],ans[MAXN][MAXN];

signed main(){
	scanf("%d%d",&n,&q);
	for( int i = 1 ; i <= n ; i ++ ) r[i] = i,c[i] = i;
	for( int i = 1 ; i <= q ; i ++ ){
		char t[2]; int I,J;
		scanf("%s%d%d",t + 1,&I,&J);
		if( t[1] == 'R' ) swap( r[I] , r[J] );
		else swap( c[I] , c[J] );
	}
	int now = 1,siz = 0;
	while( !vis[now] ) siz ++,vis[now] = 1,now = r[now];
	// vector<int> rs;
	memset( vis , 0 , sizeof( vis ) );
	for( int i = 1 ; i <= n ; i ++ ){
		if( vis[i] ) continue;
		now = i; int ts = 0;
		while( !vis[now] ) ts ++,vis[now] = 1,now = r[now];
		if( ts != siz ){ puts("*"); return 0; }
	}
	memset( vis , 0 , sizeof( vis ) );
	for( int i = 1 ; i <= n ; i ++ ){
		if( vis[i] ) continue;
		now = i; int ts = 0;
		while( !vis[now] ) ts ++,vis[now] = 1,now = c[now];
		if( ts != siz ){ puts("*"); return 0; }
	}
	memset( vis , 0 , sizeof( vis ) );
	vector< pair<int,int> > st;
	for( int i = 1 ; i <= n / siz ; i ++ ){
		int R = 1,res = ( i - 1 ) * siz;
		while( vis[R] ) R ++;
		memset( vi2 , 0 , sizeof( vi2 ) );
		for( int j = 1 ; j <= n / siz ; j ++ ){
			int C = 1;
			while( vi2[C] ) C ++;
			while( !vi2[C] ) vi2[C] = 1,ans[R][C] = ( ++res == n + 1 ? res = 1 : res ),st.emplace_back( make_pair( R , C ) ),C = c[C];
		}
		while( !vis[R] ) vis[R] = 1,R = r[R];
	}
	for( pair<int,int> ele : st ){
		int nowi = ele.first,nowj = ele.second,v = ans[nowi][nowj];
		for( int i = 1 ; i <= siz * siz ; i ++ ){
			ans[nowi][nowj] = v;
			nowi = r[nowi],nowj = c[nowj];
		}
	}
	for( int i = 1 ; i <= n ; i ++ , puts("") )
		for( int j = 1 ; j <= n ; j ++ )
			printf("%d ",ans[i][j]);
	return 0;
}