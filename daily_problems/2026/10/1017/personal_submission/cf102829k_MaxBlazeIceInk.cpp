#include<bits/stdc++.h>
using namespace std;

#define int long long
#define MAXN 605
#define mod 1000000007

int n,x[MAXN],y[MAXN],X[MAXN],Y[MAXN],id[MAXN],p2[MAXN];

inline bool cmp( pair<int,int> u , pair<int,int> v ){
	return atan2( u.second , u.first ) < atan2( v.second , v.first );
}

inline void chkadd( int &x , int k ){ x += k; if( x >= mod ) x -= mod; }

signed main(){
	scanf("%lld",&n);
	for( int i = 1 ; i <= n ; i ++ ) scanf("%lld%lld",&x[i],&y[i]);
	p2[0] = 1;
	for( int i = 1 ; i <= n ; i ++ ) p2[i] = p2[i - 1] * 2 % mod;
	int ans = 0;
	for( int X = 1 ; X <= n ; X ++ ){
		vector< pair<int,int> > A;
		for( int i = 1 ; i <= n ; i ++ ) if( i != X ) A.emplace_back( make_pair( x[i] - x[X] , y[i] - y[X] ) );
		sort( A.begin() , A.end() , cmp );
		for( int i = 0 ; i < n - 1 ; i ++ ) A.emplace_back( A[i] ); 
		chkadd( ans , 1ll );
		// cerr << ans << "\n";
		for( int l = 0 ; l < n - 1 ; l ++ ){
			int r = l;
			while( r < l + n - 1 && A[l].first * A[r].second - A[l].second * A[r].first >= 0 ) r ++;
			// cerr << "asd" << l << " " << r << "\n";
			for( int k = l ; k < r ; k ++ ){
				if( k == l ) ans = ( ans + 1 + mod ) % mod;
				else ans = ( ans + p2[k - l - 1] + mod ) % mod;
			}
		}
		// cerr << ans << "\n";
	}
	printf("%lld\n",ans);
	return 0;
}