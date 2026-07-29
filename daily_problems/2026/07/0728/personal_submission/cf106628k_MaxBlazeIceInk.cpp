#include<bits/stdc++.h>
using namespace std;

#define int long long
#define MAXN 200005
#define INF (int)1e18

int n,X[MAXN],Y[MAXN];
pair<int,int> p[MAXN],q[MAXN];

inline void solve(){
	scanf("%lld",&n);
	for( int i = 1 ; i <= n ; i ++ ) scanf("%lld%lld",&X[i],&Y[i]);
	if( n <= 3 ){ puts("0"); return; }
	for( int i = 1 ; i <= n ; i ++ ) p[i] = make_pair( X[i] + Y[i] , i );
	for( int i = 1 ; i <= n ; i ++ ) q[i] = make_pair( X[i] - Y[i] , i );
	sort( p + 1 , p + n + 1 ),sort( q + 1 , q + n + 1 );
	vector<int> A;
	A.emplace_back( p[1].second );
	A.emplace_back( p[2].second );
	A.emplace_back( p[n].second );
	A.emplace_back( p[n - 1].second );
	A.emplace_back( q[1].second );
	A.emplace_back( q[2].second );
	A.emplace_back( q[n].second );
	A.emplace_back( q[n - 1].second );
	int ans = INF;
	for( int ele : A ){
		for( int ele2 : A ){
			int xmin = INF,xmax = -INF,ymin = INF,ymax = -INF;
			for( int i = 1 ; i <= n ; i ++ ){
				if( i == ele || i == ele2 ) continue;
				xmin = min( xmin , X[i] + Y[i] );
				xmax = max( xmax , X[i] + Y[i] );
				ymin = min( ymin , X[i] - Y[i] );
				ymax = max( ymax , X[i] - Y[i] );
			}
			// cerr << ele << " " << ele2 << " " << max( xmax - xmin , ymax - ymin ) << "\n";
			ans = min( ans , max( xmax - xmin , ymax - ymin ) );
		}
	}
	printf("%lld\n",ans);
}

signed main(){
	int t; scanf("%lld",&t);
	while( t -- ) solve();
	return 0;
}