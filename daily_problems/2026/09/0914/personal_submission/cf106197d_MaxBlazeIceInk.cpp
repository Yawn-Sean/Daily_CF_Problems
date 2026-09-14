#include<bits/stdc++.h>
using namespace std;

#define int long long
#define MAXN 205
#define MAXP 200005
#define INF (int)1e18

int n,k,ans[MAXN];
char s[MAXN];

inline int Abs( int x ){ return x < 0 ? -x : x; }

inline void solve(){
	//余数大战
	scanf("%lld%lld%s",&n,&k,s + 1);
	for( int i = 1 ; i <= n ; i ++ ){
		int v = 1ll << ( i - 1 );
		if( k % ( 1ll << i ) == 0 ){ ans[i] = 0; continue; }
		else{
			k += s[i] == '-' ? v : -v;
			// cerr << k << " " << v << "\n";
			if( k % ( 1ll << i ) ){ puts("-1"); return; }
			ans[i] = 1;
		}
	}
	if( !k ){
		for( int i = 1 ; i <= n ; i ++ ) printf("%c",ans[i] ? '#' : '.');
		puts("");
	}
	else puts("-1");
}

signed main(){
	int t; scanf("%lld",&t);
	while( t -- ) solve();
	return 0;
}