#include<bits/stdc++.h>
using namespace std;

int n,m;

set< array<int,3> > vis[70][70];

const int V = 35;

// inline int Hash( int lst1 , int lst2 , int lst3 ){ return ( lst1 + 1 ) * 36 + ( lst2 + 1 ) * 6 + lst3 + 1; }

char s[10];

inline int In(){
	scanf("%s",s + 1);
	if( s[1] == 'E' ) return -1;
	if( s[1] == 'O' ) return 1;
	return 0;
}

inline int ask( int x ){
	if( x == 1 ) printf("MOVE UP\n");
	else if( x == 2 ) printf("MOVE RIGHT\n");
	else if( x == 3 ) printf("MOVE DOWN\n");
	else if( x == 4 ) printf("MOVE LEFT\n");
	fflush( stdout );
	return In();
}

int dxy[5][2] = {{0,0},{-1,0},{0,1},{1,0},{0,-1}};
int rev[5] = {0,3,4,1,2};

bool flag = 0;

void walk( int dx , int dy , array<int,3> A ){
	if( vis[dx + V][dy + V].find( A ) != vis[dx + V][dy + V].end() ){ printf("BACK\n"); fflush( stdout ); In(); return; }
	vis[dx + V][dy + V].insert( A );
	for( int i = 1 ; i <= 4 ; i ++ ){
		if( i == rev[get<0>(A)] ) continue;
		int p = ask( i );
		array<int,3> new3 = array<int,3>{ i , get<0>(A) , get<1>(A) };
		if( p == 1 ) walk( dx + dxy[i][0] , dy + dxy[i][1] , new3 );
		else if( p == -1 ){ exit( 0 ); return; }
		if( flag ) return;
	}
	if( flag ) return;
	printf("BACK\n"); fflush( stdout );
	if( In() == -1 ) exit( 0 );
}

signed main(){
	scanf("%d%d",&n,&m);
	array<int,3> new3 = array<int,3>{ 0 , 0 , 0 };
	walk( 0 , 0 , new3 );
	return 0;
}