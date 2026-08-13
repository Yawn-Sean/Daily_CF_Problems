#include<bits/stdc++.h>
using namespace std;

#define MAXN 200005

int n,r[MAXN << 1];

signed main(){
	scanf("%d",&n);
	int c0 = 0,c2 = 0;
	for( int i = 0 ; i < n ; i ++ ) scanf("%d",&r[i]),c0 += !r[i],c2 += r[i] == 2;
	for( int i = 0 ; i < n ; i ++ ) if( r[i] == 2 && ( r[( i + 1 ) % n] == 2 ) ){ puts("NO"); return 0; }
	for( int i = 0 ; i < n ; i ++ ) if( r[i] == 0 && ( r[( i + 1 ) % n] == 0 ) ){ puts("NO"); return 0; }
	if( !c0 || !c2 ){ puts("NO"); return 0; }
	for( int i = 0 ; i < n ; i ++ ) r[i + n] = r[i];
	int lst = -1;
	for( int i = 0 ; i < 2 * n ; i ++ ){
		if( r[i] == 0 || r[i] == 2 ){
			if( lst == r[i] ){ puts("NO"); return 0; }
			lst = r[i];
		}
	}
	puts("YES");
	return 0;
}