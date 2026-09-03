#include<bits/stdc++.h>
using namespace std;

#define MAXN 100005
char s[MAXN];

int n,a[MAXN];

inline void add(){
	a[0] ++;
	for( int i = 0 ; ; i ++ ){
		if( a[i] < 10 ) break;
		a[i + 1] += a[i] / 10,a[i] %= 10;
		if( a[i + 1] ) n = max( n , i + 2 );
	}
}

signed main(){
	scanf("%s",s); n = strlen( s );
	reverse( s , s + n );
	for( int i = 0 ; i < n ; i ++ ) a[i] = s[i] - '0';
	for( int i = 0 ; i < n ; i ++ ) a[i] *= 9;
	for( int i = 0 ; ; i ++ ){
		if( a[i] ) n = max( n , i + 1 );
		a[i + 1] += a[i] / 10,a[i] %= 10;
		if( i > n + 1 && !a[i] ) break;
	}
	// for( int i = 0 ; i < n ; i ++ ) cerr << a[i];
	int ans = 0;
	while( 1 ){
		add();
		a[n - 1] --;
		while( n && !a[n - 1] ) n --; ans ++;
	// for( int i = 0 ; i < n ; i ++ ) cerr << a[i];
	// cerr << "\n";
		if( !n ) break;
	}
	printf("%d\n",ans);
	return 0;
}