#include<bits/stdc++.h>
using namespace std;

#define MAXN 4005
#define mod 1000000007
#define iv2 500000004

int n,a[MAXN];

inline void chkadd( int &x , int k ){ x += k; if( x >= mod ) x -= mod; }

signed main(){
	scanf("%d",&n);
	int ans = 0;
	for( int i = 1 ; i <= n ; i ++ ){
		int x; scanf("%d",&x);
		if( i == 1 ) chkadd( ans , x );
		else if( i == 2 ) chkadd( ans , mod - x );
	}
	//二项式定理也可以推出后面正负的概率都是 1/2
	printf("%d\n",ans);
	return 0;
}