#include<bits/stdc++.h>
using namespace std;

#define MAXN 1000005
int m,notp[MAXN],prime[MAXN],ptot,minp[MAXN],ans[MAXN],maxp[MAXN];

inline void solve(){
	scanf("%d",&m);
	printf("%d\n",ans[m]);
}

signed main(){
	notp[1] = 1;
	for( int i = 2 ; i < MAXN ; i ++ ){
		if( !notp[i] ){
			prime[++ptot] = i,minp[i] = i;
			for( int j = 2 ; j * i < MAXN ; j ++ ){
				notp[i * j] = 1,minp[i * j] = i;
			}
		}
	}
	ans[1] = 1;
	for( int i = 2 ; i < MAXN ; i ++ ){
		int tmp = i; ans[i] = ans[i - 1];
		while( tmp > 1 ){
			int p = minp[tmp],c = 0;
			while( tmp % p == 0 ) tmp /= p,c ++;
			if( c > maxp[p] && ( c & ( c - 1 ) ) == 0 ) maxp[p] = c,ans[i] ++;
			// if( ( c & ( c - 1 ) ) == 0 ) ans[i] ++;
		}
	}
	int t; scanf("%d",&t);
	while( t -- ) solve();
	return 0;
}