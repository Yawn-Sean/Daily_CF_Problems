#include<bits/stdc++.h>
using namespace std;

#define int long long
#define MAXN 200005

int n,q,delta[MAXN],Ans[MAXN];

inline int Gcd( int x , int y ){ return y ? Gcd( y , x % y ) : x; }

vector< pair<int,int> > T[MAXN];

signed main(){
	scanf("%lld%lld",&n,&q);
	for( int i = 1 ; i <= q ; i ++ ){
		int st,ste,cost; scanf("%lld%lld%lld",&st,&ste,&cost);
		int g = Gcd( ste , n ); st --; st %= g;
		T[g].emplace_back( make_pair( st , cost ) );
	}
	for( int g = 1 ; g <= n ; g ++ ){
		if( n % g ) continue;
		memset( delta , 0 , sizeof( delta ) );
		for( pair<int,int> p : T[g] )
			delta[p.first] += p.second;
		for( int i = 0 ; i < n ; i ++ ) Ans[i] += delta[i % g];
	}
	int ans = -(int)1e18;
	for( int i = 0 ; i < n ; i ++ ) ans = max( ans , Ans[i] );
	int id = 0;
	for( int i = 0 ; i < n ; i ++ ) if( Ans[i] == ans ){ id = i; break; }
	printf("%lld\n",id + 1);
	return 0;
}