#include<bits/stdc++.h>
using namespace std;

#define MAXN 200005

int fib[MAXN],pre[MAXN],isf[MAXN];

inline void solve(){
	int n; scanf("%d",&n);
	printf("%d\n",pre[n]);
}

signed main(){
	pre[3] = 2;
	for( int i = 4 ; i < MAXN ; i ++ ){
		if( i % 3 == 1 || i % 3 == 0 ) pre[i] = pre[i - 1] + 1;
		else pre[i] = pre[i - 1];
	}
	int t; scanf("%d",&t);
	while( t -- ) solve();
	return 0;
}