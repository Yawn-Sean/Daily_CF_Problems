#include<bits/stdc++.h>
using namespace std;

#define int long long
//最大值开大点
#define INF (int)1e15
#define MAXN 4005
#define MAXQ 500005
#define double long double

const int V = 4000;

int n,m,q,deg[MAXN],dp[MAXN][MAXN << 1],K[MAXN << 1],B[MAXN << 1],st[MAXN << 1],top,Ans[MAXQ],vis[MAXN];
vector< array<int,3> > E[MAXN],qs[MAXN];

inline void chkmin( int &x , int k ){ x = min( x , k ); }

inline pair<double,double> inter( int k1 , int b1 , int k2 , int b2 ){
	//k1x + b1 = k2x + b2
	double x = 1.0 * ( b2 - b1 ) / ( k1 - k2 );
	double y = k1 * x + b1;
	return make_pair( x , y );
}

inline bool upon( int k1 , int b1 , pair<double,double> p ){
	double x = p.first,y = p.second;
	return k1 * x + b1 < y;
}

signed main(){
	scanf("%lld%lld%lld",&n,&m,&q);
	for( int i = 1 ; i <= m ; i ++ ){
		int u,v,t,r; scanf("%lld%lld%lld%lld",&u,&v,&t,&r);
		E[u].emplace_back( array<int,3>{ v , t , r } );
		deg[v] ++;
	}
	queue<int> Q;
	for( int i = 1 ; i <= n ; i ++ ) if( !deg[i] ) Q.push( i );
	vis[1] = 1;
	for( int i = 1 ; i <= n ; i ++ )
		for( int k = -V ; k <= V ; k ++ ) dp[i][k + V] = INF;
	dp[1][0 + V] = 0;
	while( !Q.empty() ){
		int u = Q.front(); Q.pop();
		for( auto &[v,t,r] : E[u] ){
			vis[v] |= vis[u];
			for( int k = -V ; k <= V ; k ++ )
				if( k + r >= -V && k + r <= V ) chkmin( dp[v][k + r + V] , dp[u][k + V] + t );
			if( !--deg[v] ) Q.push( v );
		}
	}
	for( int i = 1 ; i <= q ; i ++ ){
		int l,r,x; scanf("%lld%lld%lld",&l,&r,&x);
		qs[x].emplace_back( array<int,3>{ l , r , i } );
	}
	for( int i = 1 ; i <= n ; i ++ ){
		// cerr << i << " " << vis[i] << "\n";
		if( !vis[i] ){ for( auto &[l,r,id] : qs[i] ){ Ans[id] = -INF - 2; } continue; }
		int c = 0;
		//喜欢加两遍 c
		for( int k = V ; k >= -V ; k -- ) K[++c] = k,B[c] = dp[i][k + V];
		//阉割版半平面交
		for( int j = 1 ; j <= c ; j ++ ){
			while( top > 1 && upon( K[st[top - 1]] , B[st[top - 1]] , inter( K[st[top]] , B[st[top]] , K[j] , B[j] ) ) ) top --;
			st[++top] = j;
		}
		// cerr << i << "\n";
		// for( int k = -2 ; k <= 2 ; k ++ ) cerr << i << " " << dp[i][k + V] << "\n";
		// for( int j = 1 ; j <= top ; j ++ ) if( i == 3 && K[st[j]] == 2 ) cerr << K[st[j]] << " " << B[st[j]] << "corr";
		for( auto &[l,r,id] : qs[i] ){
			int L = 1,R = top - 1,ans = top - 1;
			int res = INF;
			while( L <= R ){
				int mid = ( L + R ) >> 1;
				if( inter( K[st[mid]] , B[st[mid]] , K[st[mid + 1]] , B[st[mid + 1]] ).first > l ) ans = mid,R = mid - 1;
				else L = mid + 1;
			}
			for( int j = max( 1ll , ans - 2 ) ; j <= min( top , ans + 2 ) ; j ++ )
				res = min( res , K[st[j]] * l + B[st[j]] );
			L = 1,R = top - 1,ans = top - 1;
			while( L <= R ){
				int mid = ( L + R ) >> 1;
				if( inter( K[st[mid]] , B[st[mid]] , K[st[mid + 1]] , B[st[mid + 1]] ).first > r ) ans = mid,R = mid - 1;
				else L = mid + 1;
			}
			for( int j = max( 1ll , ans - 2 ) ; j <= min( top , ans + 2 ) ; j ++ )
				res = min( res , K[st[j]] * r + B[st[j]] );
			Ans[id] = res;
		}
		top = 0;
	}
	for( int i = 1 ; i <= q ; i ++ ){
		if( Ans[i] == -INF - 2 ) puts("sorry");
		else printf("%lld\n",Ans[i]);
	}
	return 0;
}