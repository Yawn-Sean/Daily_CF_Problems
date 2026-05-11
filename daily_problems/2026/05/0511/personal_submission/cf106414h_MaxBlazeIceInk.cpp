#include<bits/stdc++.h>
using namespace std;

#define MAXN 600005

int n,m,k,vis[MAXN],col[MAXN],c[MAXN],ans[MAXN];
int choi[MAXN][3];
vector<int> E[MAXN],E2[MAXN],A;

void dfs( int x ){
	vis[x] = 1; A.emplace_back( x );
	for( int v : E[x] ){
		if( !vis[v] ){
			col[v] = col[x] ^ 1;
			dfs( v );
		}
	}
}

inline void solveA(){
	scanf("%d%d",&n,&m);
	for( int i = 1 ; i <= n ; i ++ ) scanf("%d",&c[i]);
	for( int i = 1 ; i <= m ; i ++ ){
		int u,v; scanf("%d%d",&u,&v);
		E[u].emplace_back( v ),E[v].emplace_back( u );
	}
	vector<int> Ans;
	for( int i = 1 ; i <= n ; i ++ ){
		if( !vis[i] ){
			A.clear(),dfs( i );
			int cnt[2] = {0,0};
			for( int ele : A ) cnt[col[ele]] ++;
			int Col = cnt[0] < cnt[1] ? 0 : 1;
			for( int ele : A )
				if( col[ele] == Col ) Ans.emplace_back( ele );
		}
	}
	// for( int i = 1 ; i <= n ; i ++ ) cerr << i << " " << col[i] << "\n";
	// for( int ele : Ans ) cerr << ele << "\n";
	printf("%d\n",(int)Ans.size());
	for( int ele : Ans ) printf("%d ",c[ele]); puts("");
	for( int i = 1 ; i <= n ; i ++ ) E[i].clear(),vis[i] = col[i] = c[i] = 0; A.clear();
}

int dfn[MAXN],low[MAXN],idx,inst[MAXN],st[MAXN],top;
int Cnt,bel[MAXN];

void tarjan( int x ){
	dfn[x] = low[x] = ++idx,inst[x] = 1,st[++top] = x;
	for( int v : E2[x] ){
		if( !dfn[v] ){
			tarjan( v );
			low[x] = min( low[x] , low[v] );
		}
		else if( inst[v] ) low[x] = min( low[x] , dfn[v] );
	}
	if( dfn[x] == low[x] ){
		Cnt ++;
		while( st[top] != x ){
			bel[st[top]] = Cnt,inst[st[top]] = 0;
			top --;
		}
		inst[x] = 0,bel[x] = Cnt,top --;
	}
}

inline void solveB(){
	scanf("%d%d%d",&n,&m,&k);
	for( int i = 1 ; i <= k ; i ++ ) scanf("%d",&c[i]);
	for( int i = 1 ; i <= m ; i ++ ){
		int u,v; scanf("%d%d",&u,&v);
		E[u].emplace_back( v ),E[v].emplace_back( u );
	}
	int pnt = 0;
	for( int i = 1 ; i <= n ; i ++ ){
		if( !vis[i] ){
			A.clear(),dfs( i );
			int cnt[2] = {0,0};
			for( int ele : A ) cnt[col[ele]] ++;
			int Col = cnt[0] < cnt[1] ? 0 : 1;
			for( int ele : A )
				if( col[ele] == Col )
					pnt ++,ans[ele] = c[pnt];
		}
	}
	// for( int i = 1 ; i <= n ; i ++ ) cerr << ans[i] << " ";
	for( int i = 1 ; i <= n ; i ++ ){
		if( ans[i] ) continue;
		int ava[4] = {-1,1,1,1};
		for( int ele : E[i] )
			if( ans[ele] ) ava[ans[ele]] = 0;
		int p = 0;
		for( int j = 1 ; j <= 3 ; j ++ )
			if( ava[j] ){ choi[i][p] = j,p ++; }
		if( p == 1 ) E2[i + n].emplace_back( i );
	}
	for( int i = 1 ; i <= n ; i ++ ){
		for( int ele : E[i] ){
			if( ans[i] || ans[ele] || i > ele ) continue;
			for( int j = 0 ; j < 2 ; j ++ ){
				for( int k = 0 ; k < 2 ; k ++ ){
					if( !choi[i][j] || !choi[ele][k] ) continue;
					if( choi[i][j] == choi[ele][k] ){
						E2[i + j * n].emplace_back( ele + ( 1 - k ) * n );
						E2[ele + k * n].emplace_back( i + ( 1 - j ) * n );
					}
				}
			}
		}
	}
	for( int i = 1 ; i <= 2 * n ; i ++ ) if( !dfn[i] ) tarjan( i );
	for( int i = 1 ; i <= n ; i ++ ){
		if( ans[i] ) continue;
		if( bel[i] < bel[i + n] ) ans[i] = choi[i][0];
		else ans[i] = choi[i][1];
	}
	for( int i = 1 ; i <= n ; i ++ ) printf("%d ",ans[i]);
	puts("");
	for( int i = 1 ; i <= 2 * n ; i ++ ){
		E[i].clear();
		dfn[i] = low[i] = inst[i] = vis[i] = ans[i] = c[i] = col[i] = bel[i] = st[i] = 0;
		E2[i].clear();
		choi[i][0] = choi[i][1] = choi[i][2] = 0;
	}
	A.clear(); Cnt = idx = top = 0;
}

signed main(){
	char s[2]; scanf("%s",s + 1);
	if( s[1] == 'f' ){
		int t; scanf("%d",&t);
		while( t -- ) solveA();
	}
	else{
		int t; scanf("%d",&t);
		while( t -- ) solveB();
	}
	return 0;
}