#include<bits/stdc++.h>
using namespace std;

#define int long long
#define MAXN 400005

int n,k,a[MAXN],f[MAXN];
vector<int> T[MAXN];
deque<int> Q[MAXN];

inline void solve(){
	scanf("%lld%lld",&n,&k);
	for( int i = 1 ; i <= n ; i ++ ) scanf("%lld",&a[i]);
	int ans = 0;
	for( int i = 1 ; i <= n ; i ++ ){
		for( int ele : T[a[i]] ){
			while( Q[ele].size() && Q[ele].front() < i - k ) Q[ele].pop_front();
			if( Q[ele].size() )
				f[i] = max( f[i] , f[Q[ele].front()] + ele );
			while( Q[ele].size() && f[Q[ele].back()] < f[i] )
				Q[ele].pop_back();
			Q[ele].push_back( i );
		}
	}
	for( int i = 1 ; i <= n ; i ++ ) ans = max( ans , f[i] ),f[i] = 0;
	printf("%lld\n",ans);
	for( int i = 1 ; i <= n ; i ++ )
		for( int ele : T[a[i]] ) Q[ele].clear();
}

signed main(){
	for( int i = 1 ; i < MAXN ; i ++ )
		for( int j = i ; j < MAXN ; j += i )
			T[j].emplace_back( i );
	int t; scanf("%lld",&t);
	while( t -- ) solve();
	return 0;
}