#include<bits/stdc++.h>
using namespace std;

#define int long long
#define MAXN 200005

int n,m,b;
pair<int,int> p[MAXN];

inline void solve(){
	scanf("%lld%lld",&n,&m);
	for( int i = 1 ; i <= n ; i ++ ) scanf("%lld",&p[i].first),p[i].second = i;
	sort( p + 1 , p + n + 1 );
	for( int i = 3 ; i <= n ; i ++ ){
		if( p[i].first >= m ){
			if( p[i].first + p[1].first + p[2].first <= 2 * m ){
				printf("%lld %lld %lld\n",p[i].second,p[1].second,p[2].second);
				return;
			}
		}
	}
	b = 0;
	for( int i = 1 ; i <= n ; i ++ ) if( p[i].first < m ) b = i;
	if( b < 3 ){ puts("-1"); return; }
	else{
		int A[4][3] = { {1,2,3},{1,2,b},{1,b-1,b},{b-2,b-1,b}};
		for( int i = 0 ; i < 4 ; i ++ ){
			int s = 0;
			for( int j = 0 ; j < 3 ; j ++ ) s += p[A[i][j]].first;
			if( s >= m && s <= 2 * m ){
				printf("%lld %lld %lld\n",p[A[i][0]].second,p[A[i][1]].second,p[A[i][2]].second);
				return;
			}
		}
	}
	puts("-1");
}

signed main(){
	int t; scanf("%lld",&t);
	while( t -- ) solve();
	return 0;
}