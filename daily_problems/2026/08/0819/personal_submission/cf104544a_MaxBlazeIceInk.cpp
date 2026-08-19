#include<bits/stdc++.h>
using namespace std;

#define int long long
#define MAXN 2000005

int n,x,a[MAXN],d[MAXN],cnt[MAXN],dcnt,f[MAXN];
map<int,int> M;

int Gcd( int x , int y ){ return y ? Gcd( y , x % y ) : x; }

signed main(){
	scanf("%lld%lld",&n,&x);
	if( x == 1 ){ puts("1"); return 0; }
	for( int i = 1 ; i <= n ; i ++ ) scanf("%lld",&a[i]),a[i] = Gcd( a[i] , x );
	for( int i = 1 ; i * i <= x ; i ++ ){
		if( x % i == 0 ){
			d[++dcnt] = i;
			if( x / i != i ) d[++dcnt] = x / i;
		}
	}
	sort( d + 1 , d + dcnt + 1 );
	for( int i = 1 ; i <= dcnt ; i ++ ) M[d[i]] = i;
	for( int i = 1 ; i <= n ; i ++ ) cnt[M[a[i]]] ++;
	for( int i = 1 ; i <= dcnt ; i ++ ) f[i] = (int)1e9;
	f[1] = 0;
	for( int i = 1 ; i <= dcnt ; i ++ ){
		int v = d[i]; if( v == 1 ) continue;
		int c = 1,tmp = v; while( tmp * v <= x ) tmp *= v,c ++;
		c = min( c , cnt[i] );
		while( c -- ){
			for( int j = dcnt ; j >= 1 ; j -- ){
				int D = d[j] * v; if( D % x == 0 ) D = x;
				f[M[D]] = min( f[M[D]] , f[j] + 1 );
			}
		}
	}
	int ans = f[dcnt]; if( ans > 60 ) ans = -1;
	printf("%lld\n",ans);
	return 0;
}