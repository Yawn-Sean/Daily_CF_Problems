#include<bits/stdc++.h>
using namespace std;

#define int long long
#define MAXN 100005

int n,b,a[MAXN],unbas[MAXN],siz,id[MAXN],len = 0;

struct basis{
	int dort[61],idmask[61];
	inline int insert( int x ){
		int mas = 0;
		for( int i = 60 ; i >= 0 ; i -- ){
			if( !( x >> i & 1 ) ) continue;
			if( dort[i] ){
				x ^= dort[i];
				mas ^= idmask[i];
			}
			else{
				dort[i] = x;
				idmask[i] = mas ^ ( 1ll << siz ),siz ++;
				return -1;
			}
		}
		return mas;
	}
}D;

signed main(){
	scanf("%lld%lld",&n,&b);
	vector<int> S;
	for( int i = 1 ; i <= n ; i ++ ){
		scanf("%lld",&a[i]);
		int v = D.insert( a[i] );
		if( v != -1 ) S.emplace_back( v );
	}
	int c0 = -1,c1 = -1,c2 = -1;
	for( int i = 0 ; i < siz ; i ++ ){
		int A = ( 1ll << i ) - 1,B = A,c = 0;
		for( int v : S )
			if( v >> i & 1 ) c ++,A &= v;
			else B &= ~v;
		int tot = __builtin_popcountll( A & B ) + 1;
		if( c == 0 ) c0 = max( c0 , tot );
		if( c == 1 ) c1 = max( c1 , tot );
		if( c >= 2 ) c2 = max( c2 , tot );
	}
	for( int ans = 0 ; ans < 8 ; ans ++ ){
		if( ( 1 << ans ) - ans - 1 >= c0 && ( 1 << ans ) - 1 >= c1 && ( 1 << ans ) >= c2 ){
			printf("%d\n",ans);
			return 0;
		}
	}
	return 0;
}