#include<bits/stdc++.h>
using namespace std;

#define MAXN 105
int n,a[MAXN],ans[MAXN];

signed main(){
	scanf("%d",&n);
	int M = 0;
	for( int i = 0 ; i < n ; i ++ ) scanf("%d",&a[i]);
	int c = 0;
	for( int i = 0 ; i < n ; i ++ ) if( !a[i] ) ans[i] = 1 << c,c ++;
	for( int i = 0 ; i < n ; i ++ ) if( a[i] ) ans[i] = ( a[i] > 0 ) ? 1 << c : -( 1 << c ),c ++;
	for( int i = 0 ; i < n ; i ++ ) M += a[i] * ans[i];
	printf("%d\n",M > 0 ? M : -M);
	for( int i = 0 ; i < n ; i ++ ) printf("%d ",ans[i]);
	return 0;
}