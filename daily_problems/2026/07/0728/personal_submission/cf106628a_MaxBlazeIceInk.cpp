#include<bits/stdc++.h>
using namespace std;

#define MAXN 200005

int n,q,a[MAXN],A[MAXN],cnt,ans[MAXN];
int L[MAXN],R[MAXN],st[MAXN],top,tr[MAXN];

vector< pair<int,int> > Q[MAXN],Q2[MAXN];

inline void add( int x , int k ){ for( ; x <= n + 1 ; x += x & -x ) tr[x] += k; }
inline int sum( int x ){ int ret = 0; for( ; x ; x -= x & -x ) ret += tr[x]; return ret; }

inline void add2( int x , int k ){ for( ; x ; x -= x & -x ) tr[x] += k; }
inline int sum2( int x ){ int ret = 0; for( ; x <= n + 1 ; x += x & -x ) ret += tr[x]; return ret; }

inline void solve(){
	scanf("%d%d",&n,&q);
	for( int i = 1 ; i <= n ; i ++ ) scanf("%d",&a[i]),A[++cnt] = a[i];
	sort( A + 1 , A + cnt + 1 ),cnt = unique( A + 1 , A + cnt + 1 ) - ( A + 1 );
	for( int i = 1 ; i <= n ; i ++ ) a[i] = lower_bound( A + 1 , A + cnt + 1 , a[i] ) - A; 
	for( int i = 1 ; i <= n ; i ++ ){
		while( top && a[st[top]] < a[i] ) R[st[top]] = i,top --;
		st[++top] = i;
	} while( top ) R[st[top]] = n + 1,top --;
	for( int i = n ; i >= 1 ; i -- ){
		while( top && a[st[top]] < a[i] ) L[st[top]] = i,top --;
		st[++top] = i;
	} while( top ) L[st[top]] = 0,top --;
	for( int i = 1 ; i <= q ; i ++ ){
		int l,r; scanf("%d%d",&l,&r);
		Q[r].emplace_back( make_pair( l , i ) );
		Q2[l].emplace_back( make_pair( r , i ) );
	}
	// for( int i = 1 ; i <= n ; i ++ ) cerr << i << " " << L[i] << "\n";
	for( int r = 1 ; r <= n ; r ++ ){
		add2( L[r] , 1 );	
		for( pair<int,int> ele : Q[r] ) ans[ele.second] = ( r - ele.first + 1 ) - sum2( ele.first );
	}
	for( int i = 1 ; i <= n + 1 ; i ++ ) tr[i] = 0;
	for( int l = n ; l >= 1 ; l -- ){
		add( R[l] , 1 );	
		for( pair<int,int> ele : Q2[l] ) ans[ele.second] += ( ele.first - l + 1 ) - sum( ele.first );
	}
	for( int i = 1 ; i <= q ; i ++ ) printf("%d\n",ans[i] - 1);
	for( int i = 1 ; i <= n ; i ++ ) Q[i].clear(),Q2[i].clear();
	for( int i = 1 ; i <= n + 1 ; i ++ ) tr[i] = 0;
}

signed main(){
	int t; scanf("%d",&t);
	while( t -- ) solve();
	return 0;
}