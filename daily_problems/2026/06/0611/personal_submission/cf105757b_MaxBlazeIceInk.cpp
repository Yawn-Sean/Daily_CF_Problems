#include<bits/stdc++.h>
using namespace std;

#define MAXN 6000005

int n,notp[MAXN],prime[MAXN],ptot,pr[MAXN];
int ans[MAXN];

inline void pre(){
	notp[1] = 1;
	for( int i = 2 ; i < MAXN ; i ++ ){
		if( !notp[i] ) prime[++ptot] = i;
		for( int j = 1 ; j <= ptot && i * prime[j] < MAXN ; j ++ ){
			notp[i * prime[j]] = 1;
			if( i % prime[j] == 0 ) break;
		}
	}
	for( int i = 2 ; i < MAXN / 2 ; i ++ ){
		bool f = 1;
		for( int j = 1 ; j < min( i , MAXN / 2 ) ; j ++ ){
			if( !notp[i + j] ){ pr[i] = j; f = 0; break; }
		}
		if( f ) assert( 0 );
	}
}

inline void solve(){
	scanf("%d",&n);
	if( n & 1 ){
		int pnt = n / 2 + 1; ans[pnt] = 1;
		int now = n;
		while( now > 1 ){
			int p = pr[now];
			int l = p,r = now;
			while( l <= r ) ans[pnt - 1] = l,ans[n - pnt + 2] = r,l ++,r --,pnt --;
			now = p - 1;
		}
	}
	else{
		int pnt = n / 2,now = n;
		while( now > 1 ){
			int p = pr[now];
			int l = p,r = now;
			while( l <= r ) ans[pnt] = l,ans[n - pnt + 1] = r,l ++,r --,pnt --;
			now = p - 1;
		}
	}
	for( int i = 1 ; i <= n ; i ++ ){
		printf("%d ",ans[i]);
	}
	puts("");
}

signed main(){
	pre();
	int t; scanf("%d",&t);
	while( t -- ) solve();
	return 0;
}