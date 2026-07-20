#include<bits/stdc++.h>
using namespace std;

#define int long long
//?????????????????????????????????
#define MAXN 200005

int n,p[MAXN],pos[MAXN];

int tr[MAXN];

inline void add( int x , int k ){ for( ; x <= n ; x += x & -x ) tr[x] += k; }
inline int sum( int x ){ int ret = 0; for( ; x ; x -= x & -x ) ret += tr[x]; return ret; }

inline void solve(){
	scanf("%lld",&n);
	for( int i = 1 ; i <= n ; i ++ ) scanf("%lld",&p[i]),pos[p[i]] = i;
	int ans = pos[1] - 1;
	for( int i = 1 ; i <= n ; i ++ ) add( i , 1 );
	for( int i = 1 ; i < n ; i ++ ){
		//i 先归位，此时可以判断出 i+1 在哪
		if( pos[i] < pos[i + 1] ){
			ans += sum( pos[i + 1] ) - sum( pos[i] ) - 1;
			// cerr << "asd" << i << " " << ans << "\n";
		}
		else ans += sum( pos[i + 1] ) + ( sum( n ) - sum( pos[i] ) ) - 1;
		// cerr << i << " " << ans << "\n";
		add( pos[i] , -1 );
	}
	printf("%lld\n",ans);
	for( int i = 1 ; i <= n ; i ++ ) tr[i] = 0; 
}

signed main(){
	int t; scanf("%lld",&t);
	while( t -- ) solve();
	return 0;
}