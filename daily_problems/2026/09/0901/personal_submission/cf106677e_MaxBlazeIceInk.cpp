#include<bits/stdc++.h>
using namespace std;

#define int long long
#define MAXN 100005
#define INF (int)1e18

int n,a[MAXN],b[MAXN],p[MAXN],q[MAXN];

inline void solve(){
	int cnt = 0,cnt2 = 0,tot = 0;
	for( int i = 1 ; i <= n ; i ++ ){
		scanf("%lld%lld",&a[i],&b[i]);
		tot += b[i];
		if( b[i] ) p[++cnt] = a[i];
		else q[++cnt2] = a[i];
	}
	sort( p + 1 , p + cnt + 1 );
	sort( q + 1 , q + cnt2 + 1 );
	for( int i = 1 ; i <= cnt2 ; i ++ ) q[i] += q[i - 1];
	if( !cnt ){ printf("%lld\n",q[cnt2]); return; }
	int ans = q[cnt2] + p[1],S = 0;
	//有宝石回报的按价格排序肯定买一个前缀，枚举就行
	for( int i = 1 ; i <= cnt ; i ++ ){
		S += p[i];
		int Free = tot - cnt + i;
		ans = min( ans , S + q[max( 0ll , cnt2 - Free )] );
	}
	printf("%lld\n",ans);
}

signed main(){
	while( 1 ){
		scanf("%lld",&n);
		if( !n ) break;
		solve();
	}
	return 0;
}