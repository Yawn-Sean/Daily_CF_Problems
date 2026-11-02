#include<bits/stdc++.h>
using namespace std;

#define int long long
#define MAXN 1000005

#define BASE1 1000007
#define BASE2 998244353
#define mod1 1004535809
#define mod2 1000000007

int n,k,pw1[MAXN],pw2[MAXN],p[MAXN];

signed main(){
	scanf("%lld%lld",&n,&k);
	pw1[0] = pw2[0] = 1;
	int S1 = 0,S2 = 0;
	for( int i = 1 ; i <= k ; i ++ ) p[i] = i,pw1[i] = pw1[i - 1] * BASE1 % mod1,S1 = ( S1 + pw1[i] * i % mod1 ) % mod1;
	for( int i = 1 ; i <= k ; i ++ ) pw2[i] = pw2[i - 1] * BASE2 % mod2,S2 = ( S2 + pw2[i] * i % mod2 ) % mod2;
	map< pair<int,int> , int > M;
	M[make_pair( S1 , S2 )] = 1;
	int ans = 0;
	for( int i = 1 ; i <= n ; i ++ ){
		int x,y; scanf("%lld%lld",&x,&y);
		S1 = ( S1 - p[x] * pw1[x] % mod1 + mod1 ) % mod1;
		S2 = ( S2 - p[y] * pw2[y] % mod2 + mod2 ) % mod2;
		S1 = ( S1 - p[y] * pw1[y] % mod1 + mod1 ) % mod1;
		S2 = ( S2 - p[x] * pw2[x] % mod2 + mod2 ) % mod2;
		swap( p[x] , p[y] );
		S1 = ( S1 + p[x] * pw1[x] % mod1 + mod1 ) % mod1;
		S2 = ( S2 + p[y] * pw2[y] % mod2 + mod2 ) % mod2;
		S1 = ( S1 + p[y] * pw1[y] % mod1 + mod1 ) % mod1;
		S2 = ( S2 + p[x] * pw2[x] % mod2 + mod2 ) % mod2;
		ans += M[make_pair( S1 , S2 )];
		M[make_pair( S1 , S2 )] ++;
	}
	printf("%lld\n",ans);
	return 0;
}