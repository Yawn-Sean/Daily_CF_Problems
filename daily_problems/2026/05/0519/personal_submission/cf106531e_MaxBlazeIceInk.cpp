#include<bits/stdc++.h>
using namespace std;

#define int long long
#define MAXN 200005

int AX,AY,BX,BY;

int m;

inline int Abs( int x ){ return x < 0 ? -x : x; }

signed main(){
	scanf("%lld%lld%lld%lld",&AX,&AY,&BX,&BY);
	scanf("%lld",&m);
	int ans = Abs( AX - BX ) + Abs( AY - BY );
	for( int i = 1 ; i <= m ; i ++ ){
		int k,d; scanf("%lld%lld",&k,&d);
		if( d == 1 ){
			int opx1 = 0,opx2 = 0,opy1 = 0,opy2 = 0;
			
			//两次横着走 y = x + k
			opx1 = AY - k,opx2 = BY - k;
			ans = min( ans , Abs( opx1 - AX ) + Abs( opx2 - BX ) + Abs( opx1 - opx2 ) );
			
			//竖着横着走 y = x + k
			opy1 = AX + k,opx2 = BY - k;
			ans = min( ans , Abs( opy1 - AY ) + Abs( opx2 - BX ) + Abs( opy1 - k - opx2 ) );
			
			//横着竖着走 y = x + k
			opx1 = AY - k,opy2 = BX + k;
			ans = min( ans , Abs( opx1 - AX ) + Abs( opy2 - BY ) + Abs( opy2 - k - opx1 ) );
			
			//两次竖着走 y = x + k
			opy1 = AX + k,opy2 = BX + k;
			ans = min( ans , Abs( opy1 - AY ) + Abs( opy2 - BY ) + Abs( opy1 - opy2 ) );
		}
		else{
			int opx1 = 0,opx2 = 0,opy1 = 0,opy2 = 0;
			
			//两次横着走 y = -x + k
			opx1 = k - AY,opx2 = k - BY;
			ans = min( ans , Abs( opx1 - AX ) + Abs( opx2 - BX ) + Abs( opx1 - opx2 ) );
			
			//竖着横着走 y = -x + k
			opy1 = -AX + k,opx2 = k - BY;
			ans = min( ans , Abs( opy1 - AY ) + Abs( opx2 - BX ) + Abs( k - opy1 - opx2 ) );
			
			//横着竖着走 y = -x + k
			opx1 = k - AY,opy2 = -BX + k;
			ans = min( ans , Abs( opx1 - AX ) + Abs( opy2 - BY ) + Abs( k - opy2 - opx1 ) );
			
			//两次竖着走 y = -x + k
			opy1 = -AX + k,opy2 = -BX + k;
			ans = min( ans , Abs( opy1 - AY ) + Abs( opy2 - BY ) + Abs( opy1 - opy2 ) );
		}
	}
	printf("%lld\n",ans);
	return 0;
}