#include<bits/stdc++.h>
using namespace std;

#define MAXN 100005
int n,k,a[MAXN];

signed main(){
	scanf("%d%d",&n,&k);
	int c = 0;
	for( int i = 1 ; i <= n ; i ++ ){
		int x; scanf("%d",&x);
		if( x % k ) c ++;
	}
	if( c == 0 ) puts("Rami");
	else if( c == 2 ) puts("Oussama");
	else puts( n & 1 ? "Rami" : "Oussama" );
	return 0;
}