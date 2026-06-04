#include<bits/stdc++.h>
using namespace std;

#define MAXN 5005
#define mod 998244353
int n,a[MAXN],pos[MAXN],to[MAXN],vis[MAXN],p2[MAXN],danger[MAXN];

inline int solx( int x ){
	memset( to , 0 , sizeof( to ) );
	memset( vis , 0 , sizeof( vis ) );
	memset( danger , 0 , sizeof( danger ) );
	for( int i = 1 ; i <= n ; i ++ )
		if( i + x >= 1 && i + x <= n ) to[i] = pos[i + x];
	int cnt = 0;
	for( int i = 1 ; i <= n ; i ++ ){
		if( vis[i] ) continue;
		int now = i,c = 1;
		vector<int> res;
		while( !vis[now] ){
			if( !to[now] || danger[now] ){ c = 0; break; }
			// if( x == -1 ) cerr << "asd" << now << " " << to[now] << "\n";
			vis[now] = 1;
			res.emplace_back( now ),now = to[now];
			if( !now || danger[now] ){ c = 0; break; }
		}
		// if( x == -1 ) cerr << i << "out" << c << "\n";
		if( c ) cnt ++;
		else{
			for( int ele : res ) danger[ele] = 1;
		}
	}
	return ( p2[cnt] - 1 + mod ) % mod;
}

signed main(){
	p2[0] = 1;
	for( int i = 1 ; i < MAXN ; i ++ ) p2[i] = 1ll * p2[i - 1] * 2 % mod;
	scanf("%d",&n);
	for( int i = 1 ; i <= n ; i ++ ) scanf("%d",&a[i]),pos[a[i]] = i;
	int ans = 0;
	for( int x = -n ; x <= 0 ; x ++ ){
		ans = ( ans + solx( x ) ) % mod;
		// cerr << x << " " << solx( x ) << "\n";
	}
	printf("%d\n",ans);
	return 0;
}