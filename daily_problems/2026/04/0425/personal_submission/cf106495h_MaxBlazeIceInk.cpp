#include<bits/stdc++.h>
using namespace std;

#define MAXN 2000005
#define int long long
typedef long long ll;
char s[2][MAXN],t[MAXN];

int n,r[2][MAXN],L,R[MAXN],dif[MAXN];

inline void clear(){
	//清干净
	for( int i = 0 ; i <= n * 2 + 2 ; i ++ ) r[0][i] = r[1][i] = 0,dif[i] = R[i] = 0;
	//L 没清我是人吗
	L = 0;
}

inline void Manacher( char *s , int *r ){
	int len = 0;
	t[0] = '~';
	for( int i = 1 ; i <= n ; i ++ ) t[++len] = '#',t[++len] = s[i];
	t[++len] = '#',t[++len] = '.';
	int mid = 0,rmax = 0;
	for( int i = 1 ; i <= len ; i ++ ){
		if( i < rmax ) r[i] = min( r[2 * mid - i] , rmax - i );
		while( t[i - r[i] - 1] == t[i + r[i] + 1] ) r[i] ++;
		if( i + r[i] > rmax ) rmax = i + r[i],mid = i;
	}
}

inline void solve(){
	scanf("%s%s",s[0] + 1,s[1] + 1); n = strlen( s[0] + 1 );
	Manacher( s[0] , r[0] ),Manacher( s[1] , r[1] );
	for( int i = 1 ; i <= n ; i ++ ){
		if( s[0][i] == s[1][n - i + 1] && s[1][i] == s[0][n - i + 1] ) L = i;
		else break;
	}
	// cerr << L << "\n";
	for( int i = 2 ; i <= n * 2 ; i += 2 ) R[i / 2] = min( r[0][i] / 2 , r[1][i] / 2 );
	ll ans = 0;
	for( int i = 1 ; i <= n ; i ++ ) dif[i] = 0;
	for( int i = 1 ; i <= n ; i ++ ) dif[i] ++,dif[i + R[i] + 1] --;
	for( int i = 1 ; i <= n ; i ++ ) dif[i] += dif[i - 1];
	for( int i = 1 ; i <= min( n - 1 , L ) ; i ++ ) ans += dif[n - i];
	// cerr << ans << "\n";
	for( int i = 1 ; i <= n ; i ++ ) dif[i] = 0;
	for( int i = 1 ; i <= n ; i ++ ) dif[i - R[i]] ++,dif[i + 1] --;
	for( int i = 1 ; i <= n ; i ++ ) dif[i] += dif[i - 1];
	for( int i = 1 ; i <= min( n - 1 , L ) ; i ++ ) ans += dif[i + 1];
	// cerr << ans << "\n";
	for( int i = 3 ; i <= n * 2 ; i += 2 ) R[i / 2] = min( r[0][i] / 2 , r[1][i] / 2 );
	for( int i = 1 ; i <= n ; i ++ ) dif[i] = 0;
	for( int i = 1 ; i < n ; i ++ ) dif[i + 1] ++,dif[i + R[i] + 1] --;
	for( int i = 1 ; i <= n ; i ++ ) dif[i] += dif[i - 1];
	for( int i = 1 ; i <= min( n - 1 , L ) ; i ++ ) ans += dif[n - i];
	for( int i = 1 ; i <= n ; i ++ ) dif[i] = 0;
	for( int i = 1 ; i < n ; i ++ ) dif[i - R[i] + 1] ++,dif[i + 1] --;
	for( int i = 1 ; i <= n ; i ++ ) dif[i] += dif[i - 1];
	for( int i = 1 ; i <= min( n - 1 , L ) ; i ++ ) ans += dif[i + 1];
	ans += L;
	printf("%lld\n",ans);
	for( int i = 1 ; i <= n + 1 ; i ++ ) dif[i] = 0;
	clear();
}

signed main(){
	int t; scanf("%lld",&t);
	while( t -- ) solve();
	return 0;
}