#include<bits/stdc++.h>
using namespace std;

#define int long long
#define MAXN 2000005

int n,k,ans[MAXN];
pair<int,int> a[MAXN];

inline void solve(){
	scanf("%lld%lld",&n,&k);
	for( int i = 1 ; i <= k ; i ++ ) scanf("%lld",&a[i].first),a[i].second = i;
	sort( a + 1 , a + k + 1 );
	int now = 0;
	for( int i = 1 ; i <= k ; i ++ ){
		int ud = a[i].first - a[i - 1].first;
		if( ud * ( k - i + 1 ) <= n )
			now += ud,ans[a[i].second] = now,n -= ud * ( k - i + 1 );
		else{
			int x1 = n / ( k - i + 1 ),rem = n % ( k - i + 1 );
			// cerr << x1 << " " << rem << "\n";
			for( int j = i ; j <= i + rem - 1 ; j ++ ) ans[a[j].second] = now + x1 + 1;
			for( int j = i + rem ; j <= k ; j ++ ) ans[a[j].second] = now + x1;
			break;
		}
	}
	for( int i = 1 ; i <= k ; i ++ ) printf("%lld ",ans[i]);
	puts("");
	for( int i = 1 ; i <= k ; i ++ ) ans[i] = 0,a[i] = make_pair( 0ll , 0ll );
}

signed main(){
	int t; scanf("%lld",&t);
	while( t -- ) solve();
	return 0;
}