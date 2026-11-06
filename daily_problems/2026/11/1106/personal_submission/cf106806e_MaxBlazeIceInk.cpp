#include<bits/stdc++.h>
using namespace std;

#define MAXN 500005

int n,border[MAXN],cut[MAXN],cut2[MAXN];
char s[MAXN],t[MAXN];

signed main(){
	scanf("%s",s + 1);
	n = strlen( s + 1 );
	int c = 0;
	for( int i = 2 ; i <= n ; i ++ ) c += s[i] == s[1];
	if( c == n - 1 ){
		printf("%d\n",n);
		for( int i = 1 ; i <= n ; i ++ ) printf("%c\n",s[1]);
		return 0;
	}
	memcpy( t , s , sizeof( s ) );
	reverse( t + 1 , t + n + 1 );
	for( int i = 2 , j = 0 ; i <= n ; i ++ ){
		while( j && s[j + 1] != s[i] ) j = border[j];
		if( s[j + 1] == s[i] ) j ++; border[i] = j;
	}
	if( !border[n] || n % ( n - border[n] ) ){
		printf("1\n%s",s + 1);
		return 0;
	}
	for( int i = 1 ; i <= n ; i ++ )
		if( !border[i] || i % ( i - border[i] ) ) cut[i] = 1;
	for( int i = 1 ; i <= n ; i ++ ) border[i] = 0;
	for( int i = 2 , j = 0 ; i <= n ; i ++ ){
		while( j && t[j + 1] != t[i] ) j = border[j];
		if( t[j + 1] == t[i] ) j ++; border[i] = j;
	}
	for( int i = 1 ; i <= n ; i ++ )
		if( !border[i] || i % ( i - border[i] ) ) cut2[n - i + 1] = 1;
	int ans = 0;
	for( int i = 1 ; i < n ; i ++ ){
		if( cut[i] && cut2[i + 1] ){
			printf("2\n");
			for( int j = 1 ; j <= i ; j ++ ) printf("%c",s[j]);
			puts("");	
			for( int j = i + 1 ; j <= n ; j ++ ) printf("%c",s[j]);
			puts("");
			return 0;
		}
	}
	return 0;
}