#include<bits/stdc++.h>
using namespace std;

#define int long long
#define MAXN 500005

int n,a[MAXN],buc[3][3];

signed main(){
	scanf("%lld",&n);
	for( int i = 1 ; i <= n ; i ++ ) scanf("%lld",&a[i]);
	buc[0][0] = 1;
	int S = 0,SS = 0,ans = 0;
	for( int r = 1 ; r <= n ; r ++ ){
		SS += a[r] % 3 * a[r] % 3; SS %= 3;
		S += a[r]; S %= 3;
		for( int i = 0 ; i < 3 ; i ++ ){
			for( int j = 0 ; j < 3 ; j ++ ){
				if( ( ( SS - i + 3 ) % 3 - ( ( S - j ) * ( S - j ) % 3 + 3 ) % 3 + 3 ) % 3 == 0 ){
					ans += buc[j][i];
				}
			}
		}
		buc[S][SS] ++;
	}
	printf("%lld\n",ans);
	return 0;
}