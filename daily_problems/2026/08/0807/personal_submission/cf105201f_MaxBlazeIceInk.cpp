#include<bits/stdc++.h>
using namespace std;

#define MAXN 2000005

int n,r[MAXN];
char s[MAXN],t[MAXN];

signed main(){
	scanf("%s",s + 1); n = strlen( s + 1 );
	int len = 0,ans = n;
	for( int i = 1 ; i <= n ; i ++ ) t[++len] = '#',t[++len] = s[i];
	t[++len] = '~',t[0] = '.';
	int mid = 0,rmax = 0;
	for( int i = 1 ; i <= len ; i ++ ){
		if( i < rmax ) r[i] = min( r[2 * mid - i] , rmax - i );
		while( t[i - r[i] - 1] == t[i + r[i] + 1] ){
			r[i] ++;
			if( t[i + r[i]] != '#' ) ans --;
		}
		if( i + r[i] > rmax ) rmax = i + r[i],mid = i;
	}
	printf("%d\n",ans);
	return 0;
}