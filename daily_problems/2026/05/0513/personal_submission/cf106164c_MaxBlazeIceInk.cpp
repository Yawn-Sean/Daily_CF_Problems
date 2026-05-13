#include<bits/stdc++.h>
using namespace std;

#define int long long
#define MAXN 200005

int X,rev[MAXN];

inline void solve(){
	scanf("%lld",&X);
	for( int N = 1 ; ; N ++ ){
		rev[N] = 0; 
		int S = N * ( N + 1 ) / 2;
		int L = -S + 2,R = S;
		if( ( X + S ) % 2 ) continue;
		int T = ( S - X ) / 2;
		if( X >= L && X <= R ){
			for( int i = N ; i >= 2 ; i -- ){
				if( T >= i && T - i != 1 ) T -= i,rev[i] = 1;
			}
			if( T ){ for( int i = 1 ; i <= N ; i ++ ) rev[i] = 0; continue; }
			printf("%lld\n",N);
			printf("1");
			for( int i = 2 ; i <= N ; i ++ ){
				if( rev[i] ) printf("-");
				else printf("+");
				printf("%lld",i);
			}
			for( int i = 1 ; i <= N ; i ++ ) rev[i] = 0;
			puts(""); return;
		}
	}
}

signed main(){
	int t; scanf("%lld",&t);
	while( t -- ) solve();
	return 0;
}