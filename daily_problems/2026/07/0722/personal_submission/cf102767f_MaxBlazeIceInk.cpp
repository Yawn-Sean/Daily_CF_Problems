#include<bits/stdc++.h>
using namespace std;

#define MAXN 100005

int Gcd( int x , int y ){ return y ? Gcd( y , x % y ) : x; }

int n,x,p[MAXN],a[MAXN],inv[MAXN];

//我好笨啊，我已笨哭
//我好笨啊，我已笨哭
//我好笨啊，我已笨哭
//我好笨啊，我已笨哭
//我好笨啊，我已笨哭
//我好笨啊，我已笨哭
//我好笨啊，我已笨哭
//我好笨啊，我已笨哭
//我好笨啊，我已笨哭
//我好笨啊，我已笨哭
//我好笨啊，我已笨哭
//我好笨啊，我已笨哭
//我好笨啊，我已笨哭
//我好笨啊，我已笨哭
//我好笨啊，我已笨哭
//我好笨啊，我已笨哭
//我好笨啊，我已笨哭
//我好笨啊，我已笨哭
//我好笨啊，我已笨哭
//我好笨啊，我已笨哭
//我好笨啊，我已笨哭
//我好笨啊，我已笨哭
//我好笨啊，我已笨哭
//我好笨啊，我已笨哭
//我好笨啊，我已笨哭
//我好笨啊，我已笨哭
//我好笨啊，我已笨哭
//我好笨啊，我已笨哭
//我好笨啊，我已笨哭
//我好笨啊，我已笨哭
//我好笨啊，我已笨哭
//我好笨啊，我已笨哭
//我好笨啊，我已笨哭
//我好笨啊，我已笨哭
//我好笨啊，我已笨哭
//我好笨啊，我已笨哭

int lst[MAXN],ans[MAXN];
inline int fp( int x , int p , int mod ){
	int res = 1;
	while( p ){
		if( p & 1 ) res = res * x % mod;
		x = x * x % mod;
		p >>= 1;
	}
	return res;
}

inline void solve(){
	scanf("%d%d",&n,&x); p[0] = 1;
	for( int i = 1 ; i < x ; i ++ ) inv[i] = fp( i , x - 2 , x );
	for( int i = 1 ; i <= n ; i ++ )
		scanf("%d",&a[i]),p[i] = p[i - 1] * a[i] % x;
	for( int i = 1 ; i < x ; i ++ ) lst[i] = -1,ans[i] = -1;
	lst[1] = 0;
	for( int r = 1 ; r <= n ; r ++ ){
		for( int X = x - 1 ; X >= 1 ; X -- ){
			if( lst[p[r] * inv[X] % x] != -1 ){
				int len = r - lst[p[r] * inv[X] % x];
				// cerr << r << " " << X << " " << len << "\n";
				if( ans[X] == -1 ) ans[X] = len;
				else ans[X] = min( ans[X] , len );
			}
		}
		lst[p[r]] = r;
	}
	int Ans = x - 1; while( ans[Ans] == -1 ) Ans --;
	printf("%d %d\n",Ans,ans[Ans]);
	for( int i = 0 ; i <= max( n , x ) ; i ++ ) p[i] = lst[i] = ans[i] = 0;
}

signed main(){
	int t; scanf("%d",&t);
	while( t -- ) solve();
	return 0;
}