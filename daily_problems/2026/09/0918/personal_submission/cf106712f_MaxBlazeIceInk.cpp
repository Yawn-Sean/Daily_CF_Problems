#include<bits/stdc++.h>
using namespace std;

#define MAXN 100005

int n,a[MAXN];
char s[MAXN];

signed main(){
	scanf("%s",s); n = strlen( s );
	reverse( s , s + n );
	int S = 0,upd = 0;
	for( int i = 0 ; i < n ; i ++ ){
		S += s[i] - '0';
		int xp = S + upd;
		upd = xp / 10;
	}
	//模拟高精度
	printf("%d\n",( S + upd ) % 10);
	return 0;
}