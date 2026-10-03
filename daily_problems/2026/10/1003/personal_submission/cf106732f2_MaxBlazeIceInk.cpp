#include<bits/stdc++.h>
using namespace std;

#define int long long
#define MAXN 200005
#define INF (int)1e18

int n,a[MAXN],s[MAXN],f[MAXN],g[MAXN];

vector< pair<int,int> > E[MAXN],G[MAXN];

inline bool cmp( pair<int,int> a , pair<int,int> b ){
	int u = a.first,v = b.first;
	if( s[u] >= 0 && s[v] >= 0 ){
		return f[u] == f[v] ? s[u] > s[v] : f[u] < f[v];
	}
	if( s[u] < 0 && s[v] >= 0 ) return 0;
	if( s[v] < 0 && s[u] >= 0 ) return 1;
	return f[u] + s[u] > f[v] + s[v];
}

void getf( int x , int fa ){
	s[x] = a[x];
	vector<int> A;
	for( pair<int,int> p : E[x] ){
		int v = p.first,w = p.second;
		if( v == fa ) continue;
		getf( v , x );
		G[x].emplace_back( p );
		f[v] = max( w + f[v] , 2 * w - s[v] ),s[v] -= 2 * w,s[x] += s[v];
	}
	sort( G[x].begin() , G[x].end() , cmp );
	f[x] = max( 0ll , -a[x] ); int sum = a[x];
	for( pair<int,int> p : G[x] ){
		int v = p.first;
		//w >= -sum + f[v]
		f[x] = max( f[x] , -sum + f[v] );
		sum += s[v];
	}
}

void getg( int x ){
	//一个点的权值是自身 f 减去前面 s 的和
	vector<int> pref,suff,val,pres;
	int sum = 0,siz = G[x].size();
	pref.resize( siz ),suff.resize( siz ),val.resize( siz ),pres.resize( siz );
	for( int i = 0 ; i < siz ; i ++ ){
		int v = G[x][i].first,w = G[x][i].second;
		getg( v ),g[v] += w,val[i] = -sum + f[v];
		sum += s[v],pres[i] = sum;
	}
	if( !G[x].size() ){ g[x] = max( 0ll , -a[x] ); return; }
	pref[0] = val[0];
	for( int i = 1 ; i < siz ; i ++ ) pref[i] = max( pref[i - 1] , val[i] );
	suff[siz - 1] = val[siz - 1];
	for( int i = siz - 2 ; i >= 0 ; i -- ) suff[i] = max( suff[i + 1] , val[i] );
	g[x] = INF;
	for( int i = 0 ; i < siz ; i ++ ){
		int v = G[x][i].first,w = G[x][i].second;
		int s1 = i == 0 ? -INF : pref[i - 1];
		int s2 = i == siz - 1 ? -INF : suff[i + 1] + s[v];
		//W + sum >= g[v]
		g[x] = min( g[x] , max( { s1 , s2 , g[v] - ( pres.back() - s[v] ) } ) );
	}
	g[x] = max( g[x] - a[x] , 0ll );
}

signed main(){
	scanf("%lld",&n);
	for( int i = 1 ; i <= n ; i ++ ) scanf("%lld",&a[i]);
	for( int i = 1 ; i < n ; i ++ ){
		int u,v,w; scanf("%lld%lld%lld",&u,&v,&w);
		E[u].emplace_back( make_pair( v , w ) );
		E[v].emplace_back( make_pair( u , w ) );
	}
	getf( 1 , 0 );
	// for( int i = 1 ; i <= n ; i ++ ) cerr << i << " " << s[i] << " " << f[i] << "\n";
	getg( 1 );
	printf("%lld\n",g[1]);
	return 0;
}