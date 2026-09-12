#include<bits/stdc++.h>
using namespace std;

#define MAXN 1000005

int n,len,r[MAXN];
char s[MAXN],t[MAXN];

//经典结论，anti-palin 可以直接做

inline bool judge( char A , char B ){
	if( A == B && A == '#' ) return 1;
	if( A + B == 'a' + 'b' ) return 1;
	return 0;
}

signed main(){
	scanf("%d%s",&n,s + 1);
	t[0] = '~';
	for( int i = 1 ; i <= n ; i ++ ) t[++len] = '#',t[++len] = s[i];
	t[++len] = '#',t[++len] = '.';
	int mid = 0,rmax = 0;
	for( int i = 1 ; i <= len ; i ++ ){
		if( i < rmax ) r[i] = min( rmax - i , r[mid * 2 - i] );
		// cerr << i << " " << r[i] << "\n";
		while( judge( t[i - r[i] - 1] , t[i + r[i] + 1] ) ) r[i] ++;
		if( i % 2 == 0 ) r[i] = 0; //排除奇回文对偶回文的干扰
		// cerr << i << " " << r[i] << "\n";
		//#a#b#b#a#b#a#b#b#a
		if( i + r[i] > rmax ) rmax = i + r[i],mid = i;
	}
	int ans = 0;
	for( int i = 1 ; i <= len ; i ++ ){
		if( i % 2 ) ans = max( ans , r[i] );
		// else ans = max( ans , r[i] + 1 );
	}
	printf("%d\n",ans);
	return 0;
}