#include<bits/stdc++.h>
using namespace std;

#define int long long
#define MAXN 1005
#define INF (int)1e18

int n,k,a[MAXN];
vector<int> f[MAXN];

int Gcd( int x , int y ){ return y ? Gcd( y , x % y ) : x; }

struct node{
	int res,i,j;
	inline bool operator <( const node &b )const{
		return res < b.res;
	}
};

inline void solve(){
	scanf("%lld%lld",&n,&k);
	for( int i = 1 ; i <= n ; i ++ ) scanf("%lld",&a[i]);
	for( int i = 1 ; i <= n ; i ++ ) f[i].resize( k + 1 );
	f[1][1] = 0;
	for( int i = 2 ; i <= k ; i ++ ) f[1][i] = -INF;
	for( int i = 2 ; i <= n ; i ++ ){
		priority_queue<node> Q; Q.push( node{ 0 , 0 , k } );
		for( int j = 1 ; j < i ; j ++ )
			Q.push( node{ f[j][1] + Gcd( a[j] , a[i] ) , j , 1 } );
		for( int j = 1 ; j <= k ; j ++ ){
			if( Q.empty() ) f[i][j] = -INF;
			else{
				node p = Q.top(); Q.pop();
				f[i][j] = p.res;
				if( p.j < k ) Q.push( node{ f[p.i][p.j + 1] + Gcd( a[p.i] , a[i] ) , p.i , p.j + 1 } );
			}
		}
	}
	// for( int i = 1 ; i <= n ; i ++ )
		// for( int j = 1 ; j <= k ; j ++ ) cerr << i << " " << j << " " << f[i][j] << "\n";
	priority_queue<node> Q; Q.push( node{ 0 , 0 , k } );
	int ans = 0;
	for( int j = 1 ; j <= n ; j ++ ) Q.push( node{ f[j][1] , j , 1 } );
	for( int i = 1 ; i <= k ; i ++ ){
		node p = Q.top();
		ans = p.res;
		// cerr << p.i << " " << p.j << "\n";
		Q.pop();
		//k 边减边用 k 的神了
		if( p.j < k ) Q.push( node{ f[p.i][p.j + 1] , p.i , p.j + 1 } );
	}
	printf("%lld\n",ans);
	for( int i = 1 ; i <= n ; i ++ ) f[i].clear();
}

signed main(){
	int t; scanf("%lld",&t);
	while( t -- ) solve();
	return 0;
}