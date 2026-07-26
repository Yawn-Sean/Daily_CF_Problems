#include<bits/stdc++.h>
using namespace std;

#define MAXN 15
#define double long double

int n,X[MAXN],Y[MAXN],r[MAXN];

signed main(){
	scanf("%d",&n);
	for( int i = 1 ; i <= n ; i ++ ) scanf("%d%d%d",&X[i],&Y[i],&r[i]);
	int ans = 0,tot = 0,S = 900;
	for( double x = -10 ; x <= 20 ; x += 0.01 ){
		for( double y = -10 ; y <= 20 ; y += 0.01 ){
			int c = 0;
			for( int i = 1 ; i <= n ; i ++ ){
				double dis = sqrtl( ( X[i] - x ) * ( X[i] - x ) + ( Y[i] - y ) * ( Y[i] - y ) );
				c += dis <= r[i];
				if( c == 1 ) break;
			}
			ans += c,tot ++;
		}
	}
	// cerr << ans << " " << tot << "\n";
	printf("%.12Lf\n",(double)1.0 * ans / tot * S);
	return 0;
}