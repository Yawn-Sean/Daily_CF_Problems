#include<bits/stdc++.h>
using namespace std;

#define int long long
#define MAXN 1000005

int n,notp[MAXN],prime[MAXN],ptot,phi[MAXN];

inline void euler(){
	notp[1] = 1; phi[1] = 1;
	for( int i = 2 ; i < MAXN ; i ++ ){
		if( !notp[i] ) prime[++ptot] = i,phi[i] = i - 1;
		for( int j = 1 ; j <= ptot && i * prime[j] < MAXN ; j ++ ){
			notp[i * prime[j]] = 1;
			if( i % prime[j] == 0 ){
				phi[i * prime[j]] = phi[i] * prime[j];
				break;
			}
			phi[i * prime[j]] = phi[i] * phi[prime[j]];
		}
	} 
}

inline void solve(){
	// cerr << phi[12] << " " << phi[8] << " " << phi[4] << " " << phi[2] << "\n";
	scanf("%lld",&n);
	int ans = 0;
	for( int i = 1 ; i <= n ; i ++ ){
		for( int j = i ; j <= n ; j += 2 * i ){
			ans += phi[j / i] * 2;
		}
	}
	ans -= n;
	printf("%lld\n",ans);
}

signed main(){
	euler();
	int t; scanf("%lld",&t);
	while( t -- ) solve();
	return 0;
}