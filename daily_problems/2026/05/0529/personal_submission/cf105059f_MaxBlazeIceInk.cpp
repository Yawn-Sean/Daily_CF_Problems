#include<bits/stdc++.h>
using namespace std;

#define int long long
#define double long double
#define MAXN 200005

int n,a[MAXN],f[MAXN],g[MAXN],s[MAXN];

inline void solve(){
	scanf("%lld",&n);
	for( int i = 1 ; i <= n ; i ++ ) scanf("%lld",&a[i]),s[i] = s[i - 1] + a[i];
	for( int i = 1 ; i <= n ; i ++ )
		f[i] = f[i - 1] + i * a[i];
	for( int i = n ; i >= 1 ; i -- )
		g[i] = g[i + 1] + ( n - i + 1 ) * a[i];
	double S = 0;
	for( int i = 1 ; i <= n ; i ++ ){
		int S2 = 0;
		if( i <= n / 2 ){
			S2 += f[i - 1] + g[n - i + 2] + i * ( s[n - i + 1] - s[i - 1] );
		}
		else{
			int t = n - i;
			S2 += f[t] + g[n - t + 1] + ( t + 1 ) * ( s[n - t] - s[t] );
		}
		S += 1.0 * S2 / i;
	}
	printf("%.10Lf\n",1.0 * S / ( n * ( n + 1 ) / 2 ));
	for( int i = 1 ; i <= n ; i ++ ) a[i] = s[i] = f[i] = g[i] = 0;
}

signed main(){
	int t; scanf("%lld",&t);
	while( t -- ) solve();
	return 0;
}
