#include<bits/stdc++.h>
using namespace std;

#define MAXN 1000005

int notp[MAXN],prime[MAXN],ptot,mu[MAXN],f[MAXN],c[MAXN];
vector<int> T[MAXN];

int n,q,a[MAXN];

inline void Euler(){
	notp[1] = mu[1] = 1;
	for( int i = 2 ; i < MAXN ; i ++ ){
		if( !notp[i] ) prime[++ptot] = i,mu[i] = -1;
		for( int j = 1 ; j <= ptot && i * prime[j] < MAXN ; j ++ ){
			notp[i * prime[j]] = 1;
			if( i % prime[j] == 0 ) break;
			mu[i * prime[j]] = -mu[i];
		}
	}
}

inline void modi( int x , int k ){ for( int ele : T[x] ) f[ele] += k; }

inline void solve(){
	scanf("%d%d",&n,&q);
	for( int i = 1 ; i <= n ; i ++ ) scanf("%d",&a[i]),modi( a[i] , 1 );
	for( int i = 1 ; i <= q ; i ++ ){
		int op; scanf("%d",&op);
		if( op == 1 ){
			int x,g; scanf("%d%d",&x,&g);
			x = a[x];
			if( x % g ){ puts("0"); continue; }
			x /= g;
			int ans = 0;
			for( int ele : T[x] ) ans += mu[ele] * f[g * ele];
			printf("%d\n",ans - ( x == 1 ));
		}
		else{
			int x,p; scanf("%d%d",&x,&p);
			modi( a[x] , -1 );
			a[x] = p;
			modi( a[x] , 1 );
		}
	}
	for( int i = 1 ; i <= n ; i ++ ) modi( a[i] , -1 );
}

signed main(){
	Euler();
	for( int i = 1 ; i < MAXN ; i ++ )
		for( int j = i ; j < MAXN ; j += i ) T[j].emplace_back( i );
	int t; scanf("%d",&t);
	while( t -- ) solve();
	return 0;
}