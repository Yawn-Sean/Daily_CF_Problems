#include<bits/stdc++.h>
using namespace std;

#define MAXN 1005

int n,x[MAXN],y[MAXN],p[MAXN];

//简单构造

inline bool cmp( int i , int j ){ return x[i] == x[j] ? y[i] < y[j] : x[i] < x[j]; }

signed main(){
	scanf("%d",&n);
	for( int i = 1 ; i <= n ; i ++ ) scanf("%d%d",&x[i],&y[i]),p[i] = i;
	sort( p + 1 , p + n + 1 , cmp );
	printf("%d\n",2 * n - 1);
	for( int i = 1 ; i <= n ; i ++ ) printf("%d ",p[i]);
	for( int i = n - 1 ; i >= 1 ; i -- ) printf("%d ",p[i]);
	return 0;
}