#include<bits/stdc++.h>
using namespace std;

#define MAXN 2000005

int n,len,r[MAXN],atL[MAXN],pre[MAXN],atR[MAXN];
char s[MAXN],t[MAXN];

signed main(){
	scanf("%s",s + 1); n = strlen( s + 1 );
	t[0] = '~';
	for( int i = 1 ; i <= n ; i ++ )
		t[++len] = '#',t[++len] = s[i];
	t[++len] = '#',t[++len] = '.';
	int mid = 0,rmax = 0;
	for( int i = 1 ; i <= len ; i ++ ){
		if( i < rmax ) r[i] = min( r[2 * mid - i] , rmax - i );
		while( t[i - r[i] - 1] == t[i + r[i] + 1] ) r[i] ++;
		if( i + r[i] > rmax ) rmax = i + r[i],mid = i;
	}
	int now = 1; atL[1] = 1;
	for( int i = 1 ; i <= len ; i += 2 ){
		if( now > i/ 2 ) continue;
		int L = i / 2 - r[i] / 2 + 1;
		int R = i / 2 + r[i] / 2;
		// cerr << i / 2 << " " << L << " " << R << "\n";
		if( L <= now ){
			int len = i / 2 - now + 1;
			R = i / 2 + len;
			now = R + 1;
			atL[now] = 1;
		}
	}
	for( int i = 1 ; i <= n ; i ++ ) pre[i] = pre[i - 1] + atL[i];
	now = n; atR[n] = 1;
	for( int i = len - 1 ; i >= 1 ; i -= 2 ){
		if( now < i / 2 ) continue;
		int L = i / 2 - r[i] / 2 + 1;
		int R = i / 2 + r[i] / 2;
		if( R >= now ){
			int len = now - i / 2;
			L = i / 2 - len + 1;
			now = L - 1;
			atR[now] = 1;
		}
	}
	long long ans = 0;
	for( int r = n ; r >= 1 ; r -- )
		if( atR[r] ) ans += pre[r];
	printf("%lld\n",ans);
	return 0;
}