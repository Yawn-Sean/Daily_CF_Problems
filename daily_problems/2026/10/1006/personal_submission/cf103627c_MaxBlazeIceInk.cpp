#include<bits/stdc++.h>
using namespace std;

#define MAXN 20

int n,a[1 << MAXN];

signed main(){
	scanf("%d",&n);
	for( int i = 0 ; i < 1 << n ; i ++ ) scanf("%d",&a[i]);
	for( int i = 0 ; i < n ; i ++ ){
		for( int j = 0 ; j < n ; j ++ ){
			for( int S = 0 ; S < 1 << n ; S ++ ){
				if( S >> i & 1 || S >> j & 1 || i == j ) continue;
				int A = S,B = A + ( 1 << i ),C = A + ( 1 << j ),D = B | C;
				if( a[B] + a[C] < a[A] + a[D] ){
					printf("%d %d\n",B,C);
					return 0;
				}
			}
		}
	}
	puts("-1");
	return 0;
}