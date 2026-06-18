#include<bits/stdc++.h>
using namespace std;

#define int long long
#define MAXN 50005

int n,a[MAXN];

signed main(){
	scanf("%lld",&n);
	for( int i = 1 ; i <= n ; i ++ ) scanf("%lld",&a[i]);
	int ad = 0;
	sort( a + 1 , a + n + 1 );
	priority_queue<int> Q;
	for( int i = 1 ; i <= n ; i ++ ) Q.push( a[i] );
	int los = 0;
	for( int i = 1 ; i <= n ; i ++ ){
		int x; scanf("%lld",&x);
		ad += x;
		int L = Q.top(); Q.pop();
		los += ( L + ad ) / 2;
		Q.push( L - ( L + ad ) / 2 );
	}
	int ans = 0;
	while( !Q.empty() ) ans += Q.top() + ad,Q.pop();
	printf("%lld\n",ans);
	return 0;
}