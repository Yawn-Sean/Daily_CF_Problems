#include<bits/stdc++.h>
using namespace std;

#define int long long
#define MAXN 500005
#define mod 998244353

int n,a[MAXN],L,R,lst[MAXN],dp[MAXN],s[MAXN];

//维护 [0,L-1] 的最小值，[0,R] 的最小值

inline void chkadd( int &x , int k ){ x += k; if( x >= mod ) x -= mod; }

signed main(){
	scanf("%lld%lld%lld",&n,&L,&R);
	for( int i = 1 ; i <= n ; i ++ ) scanf("%lld",&a[i]);
	set<int> S,T;
	dp[0] = s[0] = 1;
	for( int r = 1 ; r <= n ; r ++ ){
		if( lst[a[r]] ){
			if( a[r] < L ) S.erase( S.find( lst[a[r]] ) );
			if( a[r] <= R ) T.erase( T.find( lst[a[r]] ) );
		}
		lst[a[r]] = r;
		if( a[r] < L ) S.insert( lst[a[r]] );
		if( a[r] <= R ) T.insert( lst[a[r]] );
		if( S.size() == L ){
			int l = S.size() ? *S.begin() : r;
			if( T.size() < R + 1 ) dp[r] = s[l - 1];
			else{
				int l0 = T.size() ? *T.begin() : r;
				if( l0 <= l ){
					dp[r] = ( s[l - 1] - s[l0 - 1] + mod ) % mod;
				}
			}
		}
		// cerr << r << " " << dp[r] << "\n";
		s[r] = ( s[r - 1] + dp[r] ) % mod;
	}
	printf("%lld\n",dp[n]);
	return 0;
}