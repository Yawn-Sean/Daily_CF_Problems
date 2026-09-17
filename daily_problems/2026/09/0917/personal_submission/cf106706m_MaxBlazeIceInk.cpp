#include<bits/stdc++.h>
using namespace std;

//自然取优弱化 mex 即可

#define int long long
#define MAXN 500005

int n,a[MAXN],s[MAXN];
vector<int> T[MAXN];

inline void solve(){
	scanf("%lld",&n);
	for( int i = 1 ; i <= n ; i ++ ) scanf("%lld",&a[i]),T[a[i]].emplace_back( i ),s[i] = s[i - 1] + a[i];
	//少一种情况！
	int ans = n * ( n + 1 ) / 2 - ( n + 1 );
	for( int i = 1 ; i <= n ; i ++ ){
		int siz = (int)T[i].size();
		for( int j = 0 ; j < siz ; j ++ ){
			int l = j == 0 ? 1 : T[i][j - 1] + 1;
			int r = T[i][j] - 1;
			ans = max( ans , s[r] - s[l - 1] - i );
		}
		int l = T[i].size() ? T[i].back() : 0;
		ans = max( ans , s[n] - s[l] - i );
	}
	printf("%lld\n",ans);
	for( int i = 1 ; i <= n ; i ++ ) T[i].clear();
}

signed main(){
	int t; scanf("%lld",&t);
	while( t -- ) solve();
	return 0;
}