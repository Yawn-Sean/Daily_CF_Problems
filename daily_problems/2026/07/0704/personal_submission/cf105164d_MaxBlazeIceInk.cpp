#include<bits/stdc++.h>
using namespace std;

#define int long long
#define mod 1000000007

int N;

signed main(){
	scanf("%lld",&N);
	int ans = 0;
	for( int x = 1 ; x <= N - 2 ; x ++ ){
		if( N - x <= x ) continue;
		//i + j = N - x,i < x < N - x,j < x
		//二者和为 t 的时候
		//i + j = t,i < x,t - i < x
		//贡献是 ( x - 1 ) - ( t - x + 1 ) + 1 = 2x - t - 1 对 t 从 L 到 R 求和
		//t > 2x 的时候不行，t<=x 的时候不行
		//同时 t<=n-x
		int R = min( N - x , 2 * x - 2 );
		int L = max( x + 1 , 2ll );
		int res = 0;
		if( L <= R ){
			res += ( 2 * x - 1 ) * ( R - L + 1 );
			res -= R * ( R + 1 ) / 2 - ( L - 1 ) * L / 2;
		}
		L = x / 2;
		res += min( x - 1 , ( N - x ) / 2 ) - L;
		res /= 2;
		ans += res;
		//然后计算还有 x 的情况
		// cerr << x << " " << ans << "\n";
		if( x * 2 < N ) ans += min( x , N - 2 * x );
		// cerr << x << " " << ans << "\n";
		//去掉重复的
		//2i + x <= N,i < x,2i > x
		// if( 3 * x <= N ) ans ++;
		// cerr << x << " " << ans << "\n";
	}
	printf("%lld\n",ans % mod);
	return 0;
}

/*
3 1 3
3 2 2
3 2 3
3 3 3

4 2 3
4 3 3

4 4 1
4 4 2
4 4 3
4 4 4

5
*/