#include<bits/stdc++.h>
using namespace std;

#define MAXN 17
#define double long double

int n;
double p[MAXN][MAXN],f[1 << MAXN];

signed main(){
	scanf("%d",&n);
	for( int i = 0 ; i < n ; i ++ )
		for( int j = 0 ; j < n ; j ++ ) scanf("%Lf",&p[i][j]);
	f[( 1 << n ) - 1] = 1;
	for( int S = ( 1 << n ) - 1 ; S > 0 ; S -- ){
		int c = 0;
		for( int i = 0 ; i < n ; i ++ ) c += S >> i & 1;
		c = c * ( c - 1 ) / 2;
		for( int i = 0 ; i < n ; i ++ ){
			if( S >> i & 1 ){
				for( int j = i + 1 ; j < n ; j ++ ){
					if( S >> j & 1 ){
						//i 被选走
						f[S ^ ( 1 << i )] += f[S] * p[j][i] / c;
						//j 被选走
						f[S ^ ( 1 << j )] += f[S] * p[i][j] / c;
					}
				}
			}
		}
	}
	for( int i = 0 ; i < n ; i ++ ) printf("%.12Lf\n",f[1 << i]);
	return 0;
}