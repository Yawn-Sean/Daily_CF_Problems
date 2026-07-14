#include<bits/stdc++.h>
using namespace std;

#define MAXN 2000005
typedef long long ll;

int notp[MAXN],prime[MAXN],minp[MAXN],ptot;
ll pre[MAXN];

inline void euler(){
	notp[1] = 1;
	for( int i = 2 ; i < MAXN ; i ++ ){
		if( !notp[i] ) prime[++ptot] = i,minp[i] = i;
		for( int j = 1 ; j <= ptot && i * prime[j] < MAXN ; j ++ ){
			notp[i * prime[j]] = 1;
			minp[i * prime[j]] = prime[j];
			if( i % prime[j] == 0 ) break;
		}
	}
	//枚举 b
	for( int b = 2 ; b < MAXN ; b ++ ){
		int tmp = b,d = 1;
		while( tmp > 1 ){
			int p = minp[tmp],c = 0;
			while( tmp % p == 0 ) tmp /= p,c ++;
			//2c 个质因子 p
			d = d * ( 2 * c + 1 );
		}
		pre[b] = pre[b - 1] + d / 2;
	}
}

inline void solve(){
	int n; scanf("%d",&n);
	printf("%lld\n",pre[n]);
}

signed main(){
	euler();
	int t; scanf("%d",&t);
	while( t -- ) solve();
	return 0;
}