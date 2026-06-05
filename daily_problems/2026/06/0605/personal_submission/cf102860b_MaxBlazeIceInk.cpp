#include<bits/stdc++.h>
using namespace std;

#define int long long
#define MAXN 600005

int n,L,a[MAXN];

signed main(){
	scanf("%lld%lld",&n,&L);
	for( int i = 1 ; i <= n ; i ++ ) scanf("%lld",&a[i]);
	sort( a + 1 , a + n + 1 );
	for( int i = 1 ; i <= n ; i ++ ) a[i + n] = a[i] + L;
	int l = 1,r = 1,ans = 0;
	while( r <= 2 * n && 2 * ( a[r] - a[l] ) < L ) r ++;
	int ini = r;
	for( ; r < ini + n ; r ++ ){
		while( l <= r && 2 * ( a[r] - a[l] ) >= L ) l ++;
		int c = r - l;
		ans += c * ( c - 1 ) / 2;
	}
	int Ans = n * ( n - 1 ) * ( n - 2 ) / 6 - ans;
	printf("%lld\n",Ans);
	return 0;
}