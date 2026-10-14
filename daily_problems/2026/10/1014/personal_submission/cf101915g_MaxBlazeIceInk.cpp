#include<bits/stdc++.h>
using namespace std;

#define MAXN 100005

int n,q,L[MAXN],R[MAXN];
vector< pair<int,int> > E[MAXN],T;

void dfs( int x , int fa ){
	int now = (int)1e9,c = 0;
	// cerr << x << " " << L[x] << " " << R[x] << "\n";
	for( auto &[w,v] : E[x] ){
		if( v == fa ) continue;
		R[v] = now,L[v] = w;
		now = w - 1;
		R[v] = min( R[v] , R[x] );
		L[v] = max( L[v] , L[x] );
		c ++;
		if( L[v] <= R[v] ) dfs( v , x );
	}
	if( !c ){
		T.emplace_back( make_pair( R[x] , x ) );
	}
	//对 R[x] 取 min 不能忘
	else if( now >= L[x] ) T.emplace_back( make_pair( min( now , R[x] ) , x ) );
}

inline void solve(){
	scanf("%d%d",&n,&q);
	for( int i = 1 ; i < n ; i ++ ){
		int u,v,w; scanf("%d%d%d",&u,&v,&w);
		E[u].emplace_back( make_pair( w , v ) );
		E[v].emplace_back( make_pair( w , u ) );
	}
	for( int i = 1 ; i <= n ; i ++ ){
		sort( E[i].begin() , E[i].end() );
		reverse( E[i].begin() , E[i].end() );
	}
	L[1] = 0,R[1] = (int)1e9;
	dfs( 1 , 0 );
	sort( T.begin() , T.end() );
	// for( auto &[r,id] : T ) cerr << r << " " << id << "\n"; 
	long long res = 0;
	for( int i = 1 ; i <= q ; i ++ ){
		int x; scanf("%d",&x); x --;
		int l = 0,r = T.size() - 1,ans = -1;
		while( l <= r ){
			int mid = ( l + r ) >> 1;
			if( T[mid].first >= x ) ans = mid,r = mid - 1;
			else l = mid + 1;
		}
		res += T[ans].second;
		// printf("%lld\n",T[ans].second);
	}
	printf("%lld\n",res);
	for( int i = 1 ; i <= n ; i ++ ) E[i].clear();
	T.clear();
}

signed main(){
	int t; scanf("%d",&t);
	while( t -- ) solve();
	return 0;
}