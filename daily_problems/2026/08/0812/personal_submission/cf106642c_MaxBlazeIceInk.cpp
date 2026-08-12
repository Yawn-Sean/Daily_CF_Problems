#include<bits/stdc++.h>
using namespace std;

#define MAXN 200005

int n,m,k,a[MAXN],lst[20][2];

inline void solve(){
	scanf("%d%d%d",&n,&m,&k);
	long long ans = 0;
	for( int i = 1 ; i <= n ; i ++ ){
		scanf("%d",&a[i]);
		for( int j = 0 ; j < m ; j ++ ) lst[j][a[i] >> j & 1] = i;
		vector<int> A;
		for( int j = 0 ; j < m ; j ++ ){
			int L = min( lst[j][0] , lst[j][1] );
			A.emplace_back( L );
		}
		sort( A.begin() , A.end() );
		reverse( A.begin() , A.end() );
		ans += ( k ? A[k - 1] : i ) - ( k == m ? 0 : A[k] );
	}
	printf("%lld\n",ans);
	for( int i = 0 ; i < m ; i ++ ) lst[i][0] = lst[i][1] = 0;
}

signed main(){
	int t; scanf("%d",&t);
	while( t -- ) solve();
	return 0;
}