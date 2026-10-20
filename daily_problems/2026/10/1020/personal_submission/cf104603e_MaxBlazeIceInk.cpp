#include<bits/stdc++.h>
using namespace std;

#define int long long

int A,S,L,R;

signed main(){
	scanf("%lld%lld%lld%lld",&A,&S,&L,&R);
	int ans = 0;
	for( int d = 1 ; d <= R - L ; d ++ ){
		for( int f = A ; f >= L ; f -= d ){
			//n * f + n*(n-1)/2*d = S
			//n^2d + ( 2f - d ) * n - 2S = 0
			__int128 delta = __int128(1) * (2 * f - d) * (2 * f - d) + __int128(8) * S * d;
			__int128 c = sqrtl(delta) - 1; c = max( c , __int128(0) ); while( c * c < delta ) c ++;
			// cerr << c << "\n";
			if( c * c == delta ){
				int Aa = ( d - 2 * f ) + c;
				int B = 2 * d;
				if( Aa % B == 0 ){
					int n = Aa / B;
					__int128 r = f + __int128( n - 1 ) * d;
					//检查是否能覆盖到 A
					if( n > 1 && ( A - f ) / d <= n - 1 && r <= R ){
						// cerr << d << " " << f << " " << r << "\n";
						ans ++;
					}
				}
			}
		}
	}
	if( A == S ) ans ++;
	printf("%lld\n",ans);
	return 0;
}