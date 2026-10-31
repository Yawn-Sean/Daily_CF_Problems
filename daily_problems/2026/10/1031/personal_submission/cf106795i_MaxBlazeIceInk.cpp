#include<bits/stdc++.h>
using namespace std;

#define MAXN 2505

int n,a[MAXN],notp[MAXN],prime[MAXN],ptot,minp[MAXN],vis[MAXN],cnt = 0,Big[MAXN],v2[MAXN];

//2 3 5 7 11 13 17 19 23 29 31 37 41 43 47

int res = 3000;
void dfs( int x , int used ){
	if( x > 15 ){
		for( int i = 1 ; i <= n ; i ++ ){
			v2[minp[a[i]]] = 0;
		}
		for( int i = 1 ; i <= n ; i ++ ){
			if( !vis[i] ){
				if( minp[a[i]] <= 47 ) return;
				used += !v2[minp[a[i]]];
				v2[minp[a[i]]] = 1;
			}
		}
		res = min( res , used );
		return;
	}
	//不选
	dfs( x + 1 , used );
	//选
	int p = prime[x];
	for( int i = 1 ; i <= n ; i ++ ){
		if( a[i] % p == 0 ){
			vis[i] ++;
		}
	}
	dfs( x + 1 , used + 1 );
	for( int i = 1 ; i <= n ; i ++ ){
		if( a[i] % p == 0 ){
			vis[i] --;
		}
	}
}

signed main(){
	scanf("%d",&n);
	notp[1] = 1;
	for( int i = 2 ; i < MAXN ; i ++ ){
		if( !notp[i] ){
			prime[++ptot] = i,minp[i] = i;
			for( int j = 2 * i ; j < MAXN ; j += i ){
				notp[j] = 1,minp[j] = i;
			}
		}
	}
	int ans = 0;
	for( int i = 1 ; i <= n ; i ++ ) scanf("%d",&a[i]);
	sort( a + 1 , a + n + 1 );
	n = unique( a + 1 , a + n + 1 ) - ( a + 1 );
	dfs( 1 , 0 );
	printf("%d\n",res);
	return 0;
}