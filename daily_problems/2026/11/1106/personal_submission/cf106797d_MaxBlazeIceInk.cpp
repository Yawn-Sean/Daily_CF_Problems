#include<bits/stdc++.h>
using namespace std;

#define int long long
#define MAXN 400005

int n,m,f[MAXN],c[MAXN],col[MAXN],siz[MAXN];

struct node{
	int u,v,w;
	inline bool operator <( const node &b ) const{
		return w < b.w;
	}
}E[MAXN];

vector<int> T[MAXN],A;

bool flg;

void dfs( int x ){
	A.emplace_back( x );
	for( int ele : T[x] ){
		if( col[ele] == 0 ){
			col[ele] = 3 - col[x];
			dfs( ele );
		}
		else if( col[ele] && col[ele] == col[x] ) flg = 0;
	}
}

int find( int x ){ return f[x] == x ? x : f[x] = find( f[x] ); }

signed main(){
	scanf("%lld%lld",&n,&m);
	for( int i = 1 ; i <= m ; i ++ ){
		int u,v,t; scanf("%lld%lld%lld",&u,&v,&t);
		E[i] = node{ u , v , t };
	}
	sort( E + 1 , E + m + 1 );
	reverse( E + 1 , E + m + 1 );
	for( int i = 1 ; i <= n ; i ++ ) f[i] = i,siz[i] = 1;
	int l = 1;
	while( l <= m ){
		int r = l,w = E[l].w;
		while( r + 1 <= m && E[r + 1].w == w ) r ++;
		set<int> S;
		for( int i = l ; i <= r ; i ++ ){
			int u = find( E[i].u ),v = find( E[i].v );
			T[u].emplace_back( v ),T[v].emplace_back( u );
			S.insert( u ),S.insert( v );
		}
		for( int ele : S ) col[ele] = 0;
		for( int ele : S ){
			if( !col[ele] ){
				// cerr << ele << "?";
				//每个连通块处理
				flg = 1,A.clear();
				col[ele] = 1,dfs( ele );
				if( !flg ){ puts("impossible"); return 0; }
				int res[2] = {0,0};
				for( int ele : A ){
					if( col[ele] == 1 ) res[0] += c[ele],res[1] += c[ele] + siz[ele]; //可以折一下就不填 1 转弯了
					else res[1] += c[ele],res[0] += c[ele] + siz[ele];
				}
				int st = A[0]; c[st] = min( res[0] , res[1] );
				// cerr << "?" << res[0] << " " << res[1] << "\n";
				for( int ele : A ){
					if( find( ele ) != find( st ) ){
						siz[st] += siz[ele];
						f[ele] = st;
					}
				}
				// cerr << st << " " << c[st] << "\n";
			}
		}
		for( int ele : S ) T[ele].clear();
		l = r + 1;
	}
	int ans = 0;
	for( int i = 1 ; i <= n ; i ++ ) if( find( i ) == i ) ans += c[i];
	printf("possible\n%lld\n",ans);
	return 0;
}