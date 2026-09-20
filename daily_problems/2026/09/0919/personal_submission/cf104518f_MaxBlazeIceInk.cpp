#include<bits/stdc++.h>
using namespace std;

#define int long long
#define MAXN 500005

int n,m,a[MAXN],b[MAXN],c[MAXN],p[MAXN],f[MAXN];

inline bool cmp( int x , int y ){ return c[x] < c[y]; }

int find( int x ){ return f[x] == x ? x : f[x] = find( f[x] ); }

vector< pair<int,int> > E[MAXN];
vector<int> ans;
int S = 0;

void dfs( int x , int fa ){
	for( pair<int,int> p : E[x] ){
		int v = p.first,w = p.second;
		if( v == fa ) continue;
		ans.emplace_back( v ),dfs( v , x ),S += 2 * w;
		ans.emplace_back( x );
	}
}

signed main(){
	scanf("%lld%lld",&n,&m);
	for( int i = 1 ; i <= m ; i ++ ){
		scanf("%lld%lld%lld",&a[i],&b[i],&c[i]);
		p[i] = i;
	}
	sort( p + 1 , p + m + 1 , cmp );
	for( int i = 1 ; i <= n ; i ++ ) f[i] = i;
	for( int i = 1 ; i <= m ; i ++ ){
		int U = a[p[i]],V = b[p[i]];
		if( find( U ) != find( V ) ){
			E[U].emplace_back( make_pair( V , c[p[i]] ) );
			E[V].emplace_back( make_pair( U , c[p[i]] ) );
			// cerr << U << " " << V << " " << c[p[i]] << "/**/\n/**/";
			f[find( U )] = find( V );
		}
	}
	//显然可以走最小生成树
	ans.emplace_back( 1 );
	dfs( 1 , 0 );
	printf("%lld\n%lld\n",S,(int)ans.size());
	for( int ele : ans ) printf("%lld ",ele); puts("");
	return 0;
}