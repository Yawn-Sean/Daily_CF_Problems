#include<bits/stdc++.h>
using namespace std;

#define int long long
#define MAXN 100005
int n;
pair<int,int> T[MAXN];

inline bool check( int x ){
	int ans = 0;
	for( int i = 1 ; i <= n ; i ++ ) if( T[i].first >= x ) ans += T[i].second;
	return ans >= x;
}

signed main(){
	scanf("%lld",&n);
	for( int i = 1 ; i <= n ; i ++ ){ scanf("%lld%lld",&T[i].first,&T[i].second); if( T[i].first < T[i].second ) swap( T[i].first , T[i].second ); }
	int l = 1,r = (int)1e9,ans = -1;
	while( l <= r ){
		int mid = ( l + r ) >> 1;
		if( check( mid ) ) ans = mid,l = mid + 1;
		else r = mid - 1;
	}
	printf("%lld\n",ans);
	return 0;
}