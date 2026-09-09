#include<bits/stdc++.h>
using namespace std;

#define MAXN 200005
#define int long long
#define mod 998244353

int n,m,k,lay[MAXN],vis[MAXN],rk[MAXN],ans[MAXN];
vector< pair<int,int> > E[MAXN];
vector<int> T[MAXN];

inline bool cmp( int x , int y ){ return rk[x] < rk[y]; }
inline bool cmp2( pair<int,int> A , pair<int,int> B ){ return A.second == B.second ? A.first < B.first : A.second < B.second; }

struct node{ int ele,v,w; };
inline bool cmp3( node A , node B ){ return rk[A.ele] == rk[B.ele] ? A.w < B.w : rk[A.ele] < rk[B.ele]; }

void dfs( int x ){
	lay[x] = 0;
	for( pair<int,int> p : E[x] ){
		int v = p.first,w = p.second;
		if( !w && lay[v] == n + 1 ) dfs( v );
	}
}

inline void solve(){
	scanf("%lld%lld%lld",&n,&m,&k);
	for( int i = 1 ; i <= m ; i ++ ){
		int u,v,w; scanf("%lld%lld%lld",&u,&v,&w);
		E[u].emplace_back( make_pair( v , w ) );
		E[v].emplace_back( make_pair( u , w ) );
	}
	for( int i = 1 ; i <= n ; i ++ ) sort( E[i].begin() , E[i].end() , cmp2 );
	for( int i = 1 ; i <= n ; i ++ ) lay[i] = n + 1;
	dfs( 1 );
	queue<int> Q;
	for( int i = 1 ; i <= n ; i ++ ) if( lay[i] == 0 ) Q.push( i );
	while( !Q.empty() ){
		int u = Q.front(); Q.pop();
		if( vis[u] ) continue;
		vis[u] = 1;
		for( pair<int,int> p : E[u] ){
			int v = p.first;
			lay[v] = min( lay[v] , lay[u] + 1 );
			Q.push( v );
		}
	}
	for( int i = 1 ; i <= n ; i ++ ) vis[i] = 0;
	for( int i = 1 ; i <= n ; i ++ ){
		if( lay[i] == n + 1 ) ans[i] = -1,vis[i] = 1;
		else T[lay[i]].emplace_back( i );
	}
	for( int i = 1 ; i <= n ; i ++ ) if( lay[i] == 0 ) rk[i] = 1,vis[i] = 1;
	for( int i = 0 ; i < n ; i ++ ){
		vector<node> tmp;
		sort( T[i].begin() , T[i].end() , cmp );
		for( int ele : T[i] ){
			for( pair<int,int> p : E[ele] ){
				int v = p.first,w = p.second;
				if( lay[v] != lay[ele] + 1 ) continue;
				tmp.emplace_back( node{ ele , v , w } );
			}
		}
		int now = 1;
		pair<int,int> lst = make_pair( -1 , -1 );
		sort( tmp.begin() , tmp.end() , cmp3 );
		for( node p : tmp ){
			int ele = p.ele,v = p.v,w = p.w;
			// cerr << ele << " " << v << " " << w << "\n";
			if( vis[v] ) continue;
			ans[v] = ( ans[ele] * k % mod + w ) % mod;
			vis[v] = 1;
			if( lst.first == -1 ) rk[v] = now;
			else{
				if( rk[ele] == lst.first && w == lst.second ) rk[v] = now;
				else rk[v] = ++now;
			}
			lst = make_pair( rk[p.ele] , p.w );
		}
	}
	for( int i = 1 ; i <= n ; i ++ ) printf("%lld ",ans[i]);
	puts("");
	for( int i = 0 ; i <= n + 1 ; i ++ ){
		lay[i] = vis[i] = rk[i] = ans[i] = 0;
		T[i].clear();
		E[i].clear();
	}
}

signed main(){
	int t; scanf("%lld",&t);
	while( t -- ) solve();
	return 0;
}