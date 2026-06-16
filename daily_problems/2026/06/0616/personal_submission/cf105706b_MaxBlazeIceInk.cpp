#include<bits/stdc++.h>
using namespace std;

#define int long long
#define MAXN 200005

int n,q,dif[MAXN],ans[MAXN];
pair<int,int> Q[MAXN];
vector< pair<int,int> > E[MAXN],G[MAXN];

struct Set{
	vector<int> key;
	Set(){}
	Set( int x ){ key.emplace_back( x ); }
	inline void insert( int x ){
		// assert( !cnt || x >= key[cnt] );
		while( key.size() >= 2 && 2 * key[key.size() - 2] >= x ) key.pop_back();
		// while( cnt && key[cnt] == x ) cnt --;
		// while( cnt >= 2 && 2 * key[cnt - 1] >= x ) cnt --;
		//?????????????????
		// if( cnt == 149 ) exit( 0 );
		key.emplace_back( x );
		// key[++cnt] = x;
		// if( cnt > 140 ){ cerr <<" ?????????"; exit( 0 ); }
	}
}S[MAXN],T[MAXN];

inline Set operator +( Set A , int w ){
	for( int &ele : A.key ) ele += w;
	return A;
}

inline Set operator +( Set A , Set B ){
	Set C;
	int i = 0,j = 0;
	while( i < A.key.size() && j < B.key.size() ){
		if( A.key[i] < B.key[j] ) C.insert( A.key[i] ),i ++;
		else C.insert( B.key[j] ),j ++;
	}
	while( i < A.key.size() ) C.insert( A.key[i] ),i ++;
	while( j < B.key.size() ) C.insert( B.key[j] ),j ++;
	return C;
}

void init( int x , int fa ){
	//S[x] 等于所有 v 加一个 w 之后再拼起来
	for( pair<int,int> p : E[x] ){
		int v = p.first,w = p.second;
		if( v == fa ) continue;
		init( v , x );
		S[x] = S[x] + ( S[v] + w ) + Set( w );
		// if( S[v].cnt > 0 )cerr <<"asd\n";
	}
}

//换根！
void get_ans( int x , int fa ){
	Set Now = T[x] + S[x];
	for( int i = 0 ; i < Now.key.size() ; i ++ ){
		int val = Now.key[i];
		int l = lower_bound( Q + 1 , Q + q + 1 , make_pair( ( val + 1 ) / 2 , 0ll ) ) - Q;
		int r = upper_bound( Q + 1 , Q + q + 1 , make_pair( val , q + 1 ) ) - Q;
		if( l < r ) dif[l] ++,dif[r] --;
	}
	int son = 0;
	for( pair<int,int> p : E[x] )
		if( p.first != fa ) G[x].emplace_back( p ),son ++;
	{
		vector<Set> suf( son );
		for( int i = son - 1 ; i >= 0 ; i -- ){
			int v = G[x][i].first,w = G[x][i].second;
			if( i == son - 1 ) suf[i] = ( S[v] + w ) + Set( w );
			else suf[i] = suf[i + 1] + ( S[v] + w ) + Set( w );
		}
		Set pre;
		for( int i = 0 ; i < son ; i ++ ){
			int v = G[x][i].first,w = G[x][i].second;
			if( i < son - 1 )
				T[v] = ( ( T[x] + pre + suf[i + 1] ) + w ) + Set( w );
			else T[v] = ( T[x] + pre + w ) + Set( w );
			pre = pre + ( S[v] + w ) + Set( w );
		}
	}
	for( int i = 0 ; i < son ; i ++ ) get_ans( G[x][i].first , x );
}

inline void solve(){
	scanf("%lld%lld",&n,&q);
	for( int i = 1 ; i < n ; i ++ ){
		int u,v,w; scanf("%lld%lld%lld",&u,&v,&w);
		E[u].emplace_back( make_pair( v , w ) );
		E[v].emplace_back( make_pair( u , w ) );
	}
	for( int i = 1 ; i <= q ; i ++ )
		scanf("%lld",&Q[i].first),Q[i].second = i;
	sort( Q + 1 , Q + q + 1 );
	init( 1 , 0 );
	get_ans( 1 , 0 );
	for( int i = 1 ; i <= q ; i ++ ) dif[i] += dif[i - 1];
	for( int i = 1 ; i <= q ; i ++ ) if( dif[i] ) ans[Q[i].second] = 1;
	for( int i = 1 ; i <= q ; i ++ ) printf("%lld",ans[i]);
	puts("");
	
	for( int i = 1 ; i <= n ; i ++ ){
		S[i] = T[i] = Set();
		E[i].clear(),G[i].clear();
	}
	for( int i = 1 ; i <= q + 1 ; i ++ ) ans[i] = dif[i] = 0,Q[i] = make_pair( 0 , 0 );
}

signed main(){
	// printf("1\n200000 1\n");
	// for( int i = 1 ; i < 200000 ; i ++ ){
		// printf("%lld %lld 20\n",i,i+1);
	// }
	// printf("20000");
	int t; scanf("%lld",&t);
	while( t -- ) solve();
	return 0;
}