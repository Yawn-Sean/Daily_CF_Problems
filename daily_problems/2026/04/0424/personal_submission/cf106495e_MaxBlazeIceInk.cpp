#include<bits/stdc++.h>
using namespace std;

//p 向 p / minp 连边，直接 dfs 就是所需要的序

#define MAXN 1000005
int n,q,notp[MAXN],prime[MAXN],ptot,minp[MAXN],ans[MAXN];
vector<int> E[MAXN];

int idx;
void dfs( int x ){
	ans[++idx] = x;
	for( int ele : E[x] ) dfs( ele );
}

signed main(){
	scanf("%d%d",&n,&q);
	notp[1] = 1;
	for( int i = 2 ; i < MAXN ; i ++ ){
		if( !notp[i] ){
			prime[++ptot] = i,minp[i] = i;
			for( int j = i * 2 ; j < MAXN ; j += i ){
				notp[j] = 1,minp[j] = i;
			}
		}
	}
	for( int i = 2 ; i <= n ; i ++ )
		E[i / minp[i]].emplace_back( i );
	dfs( 1 );
	for( int i = 1 ; i <= q ; i ++ ){
		int k; scanf("%d",&k);
		printf("%d\n",ans[k]);
	}
	return 0;
}