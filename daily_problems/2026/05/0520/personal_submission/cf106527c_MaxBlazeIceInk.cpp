#include<bits/stdc++.h>
using namespace std;

// #define int long long
#define MAXN 1000005

int n,p,x,k[MAXN],cnt[MAXN];

inline void solve(){
	scanf("%d%d%d",&n,&p,&x);
	int S = 0,ans = n;
	for( int i = 1 ; i <= p ; i ++ ) scanf("%d",&k[i]),cnt[k[i]] ++,S += k[i];
	for( int i = n ; i >= 0 ; i -- ) cnt[i] += cnt[i + 1];
	if( S <= x * n ){
		puts("0");
		// assert( n < )
		for( int i = 0 ; i <= n ; i ++ ) cnt[i] = 0;
		return;
	}
	for( int i = 1 ; i <= n ; i ++ ){
		ans ++,S -= cnt[i];
		if( S <= ( n - i ) * x ){
			ans = i;
			printf("%d\n",ans);
			for( int i = 0 ; i <= n ; i ++ ) cnt[i] = 0;
			return;
		}
	}
	printf("%d\n",n);
}

signed main(){
	int t; scanf("%d",&t);
	while( t -- ) solve();
	return 0;
}