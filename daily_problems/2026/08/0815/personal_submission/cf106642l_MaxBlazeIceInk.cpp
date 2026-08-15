#include<bits/stdc++.h>
using namespace std;

#define MAXN 400005

int n,a[MAXN],L[MAXN],R[MAXN],tr[MAXN],tang[MAXN];

inline void add( int x , int k ){ for( ; x <= 2 * n ; x += x & -x ) tr[x] += k; }
inline int sum( int x ){ int ret = 0; for( ; x ; x -= x & -x ) ret += tr[x]; return ret; }

inline void solve(){
	scanf("%d",&n);
	for( int i = 1 ; i <= 2 * n ; i ++ ) scanf("%d",&a[i]);
	for( int i = 1 ; i <= 2 * n ; i ++ ) R[a[i]] = i;
	for( int i = 2 * n ; i >= 1 ; i -- ) L[a[i]] = i;
	int T = 0;
	for( int i = 1 ; i <= 2 * n ; i ++ ){
		if( R[a[i]] == i ){
			int id = a[i];
			tang[id] = sum( i ) - sum( L[id] );
			// cerr << id << " " << L[id] << " " << R[id] << "\n";
			add( L[id] , -1 ),add( R[id] , 1 );
			T += tang[id];
		}
	}
	// cerr << T << "\n";
	for( int i = 1 ; i <= 2 * n ; i ++ ) tr[i] = 0;
	for( int i = 2 * n ; i >= 1 ; i -- ){
		if( L[a[i]] == i ){
			int id = a[i];
			tang[id] += sum( R[id] ) - sum( i );
			// cerr << id << " " << tang[id] << "\n";
			add( L[id] , 1 ),add( R[id] , -1 );
		}
	}
	int ans = 0;
	vector<int> A;
	for( int i = 1 ; i <= n ; i ++ ){ ans += tang[i] == T; if( tang[i] == T ) A.emplace_back( i ); }
	printf("%d\n",(int)A.size());
	for( int ele : A ) printf("%d ",ele);
	for( int i = 1 ; i <= 2 * n ; i ++ ) L[i] = R[i] = tr[i] = tang[i] = 0;
}

signed main(){
	int t = 1;
	while( t -- ) solve();
	return 0;
}