#include<bits/stdc++.h>
using namespace std;

#define MAXN 2005

int n,m,s[MAXN],a[MAXN],border[MAXN];

signed main(){
	scanf("%d%d",&n,&m);
	for( int i = 1 ; i <= m ; i ++ ) scanf("%d",&s[i]);
	for( int i = 1 ; i <= n ; i ++ ){
		for( int j = 1 ; j <= m ; j ++ ) scanf("%d",&a[j]),a[j + m] = a[j];
		for( int i = 2 , j = 0 ; i <= m ; i ++ ){
			while( j && s[j + 1] != s[i] ) j = border[j];
			if( s[j + 1] == s[i] ) j ++; border[i] = j;
		}
		int c = 0;
		for( int i = 1 , j = 0 ; i <= 2 * m ; i ++ ){
			while( j && s[j + 1] != a[i] ) j = border[j];
			if( s[j + 1] == a[i] ) j ++;
			if( j == m ) c ++,j = border[j];
		}
		if( c ){ printf("%d\n",i); return 0; }
		for( int i = 1 ; i <= 2 * m ; i ++ ) border[i] = 0;
	}
	puts("-1");
	return 0;
}