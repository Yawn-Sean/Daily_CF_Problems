#include<bits/stdc++.h>
#include<cassert>
using namespace std;

#define MAXN 200005

int n,m,k,id[MAXN],sta[MAXN],c[MAXN];

int nodecnt,head,tail,siz,broken1 = 0,broken2 = 0;
pair<int,int> P[MAXN];
map<int,int> M;
vector<int> suf,pre;

inline int append( int id , int st ){
	++nodecnt; P[nodecnt] = make_pair( id , st );
	if( !st ){
		broken2 = nodecnt;
		if( !broken1 ) broken1 = nodecnt;
	}
	if( !siz ) head = tail = nodecnt;
	else{ suf[tail] = nodecnt,pre[nodecnt] = tail,tail = nodecnt; }
	siz ++;
	return nodecnt;
}

inline void delet( int x ){
	if( broken1 == x ){
		while( 1 ){
			broken1 = suf[broken1];
			if( !broken1 || P[broken1].second == 0 ) break;
		}
	}
	if( broken2 == x ){
		while( 1 ){
			broken2 = pre[broken2];
			if( !broken2 || P[broken2].second == 0 ) break;
		}
	}
	if( x == head ) head = suf[head],pre[head] = 0;
	else if( x == tail ) tail = pre[tail],suf[tail] = 0;
	else suf[pre[x]] = suf[x],pre[suf[x]] = pre[x];
	if( M[P[x].first] == x ) M[P[x].first] = 0;
	siz --;
	if( !siz ) head = tail = 0;
}

inline void solve(){
	scanf("%d%d%d",&n,&m,&k);
	pre.resize( n + 3 ),suf.resize( n + 3 );
	for( int i = 1 ; i <= n ; i ++ ) scanf("%d%d",&id[i],&sta[i]);
	for( int i = 1 ; i <= k ; i ++ ) scanf("%d",&c[i]);
	int pnt = 1,rev = 0;
	for( int i = 1 ; i <= n ; i ++ ){
		if( M[id[i]] ){
			int p = M[id[i]];
			M[id[i]] = append( id[i] , sta[i] );
			delet( p );
		}
		else if( siz < m ){
			M[id[i]] = append( id[i] , sta[i] );
		}
		else if( broken1 ){
			M[id[i]] = append( id[i] , sta[i] );
			delet( broken1 );
		}
		else if( sta[i] ){
			M[id[i]] = append( id[i] , sta[i] );
			delet( head );
		}
		if( pnt <= k && i == c[pnt] ){
			swap( suf , pre ),swap( head , tail ),swap( broken1 , broken2 );
			pnt ++,rev ^= 1;
		}
	}
	int cnt = 0;
	for( int i = head ; ; i = suf[i] ){ cnt ++; if( i == tail ) break; }
	assert( cnt );
	printf("%d\n",cnt);
	for( int i = head ; ; i = suf[i] ){
		printf("%d ",P[i].first);
		if( i == tail ) break;
	}
	puts("");
	for( int i = 1 ; i <= nodecnt ; i ++ ) id[i] = sta[i] = c[i] = head = tail = siz = 0,P[i] = make_pair( 0 , 0 );
	M.clear(); nodecnt = broken1 = broken2 = 0; pre.clear(),suf.clear();
	// if( rev ) swap( pre , suf ),rev = 0;
}

signed main(){
	int t; scanf("%d",&t);
	while( t -- ) solve();
	return 0;
}