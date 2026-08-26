#include<bits/stdc++.h>
using namespace std;

#define MAXN 100005

int n,m,col[MAXN],lab[MAXN],minn;
vector<int> E[MAXN],A;
bool f;

void dfs( int x ){
	A.emplace_back( x ),minn = min( minn , lab[x] );
	for( int v : E[x] ){
		if( col[v] ){
			if( col[v] != 3 - col[x] ) f = 0;
			continue;
		}
		col[v] = 3 - col[x];
		dfs( v );
	}
}

map<int,int> M;

signed main(){
	//二分图自证之战
	scanf("%d%d",&n,&m);
	for( int i = 1 ; i <= n ; i ++ ) scanf("%d",&lab[i]);
	for( int i = 1 ; i <= m ; i ++ ){
		int u,v; scanf("%d%d",&u,&v);
		E[u].emplace_back( v ),E[v].emplace_back( u );
	}
	//标签两两不同
	int Ans = 0;
	long long T = 0;
	for( int i = 1 ; i <= n ; i ++ ){
		if( !col[i] ){
			A.clear(); f = 1,minn = (int)1e9;
			col[i] = 1;
			dfs( i );
			if( f ){
				int siz[3] = {0,0,0};
				for( int ele : A ){
					siz[col[ele]] ++;
				}
				T += 1ll * siz[2] * ( siz[2] - 1 ) / 2;
				T += 1ll * siz[1] * ( siz[1] - 1 ) / 2;
				// Ans = max( Ans , max( siz[2] , siz[1] ) );
			}
			else{
				T += 1ll * (int)A.size() *(  (int)A.size() - 1 ) / 2;
			}
			// cerr << (int)A.size() << "\n";
		}
	}
	printf("%lld\n",T);
	return 0;
}