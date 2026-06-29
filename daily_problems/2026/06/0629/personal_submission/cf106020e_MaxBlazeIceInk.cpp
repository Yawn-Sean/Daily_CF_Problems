#include<bits/stdc++.h>
using namespace std;

#define int long long
#define MAXN 1000005
#define INF (int)1e18

int n,p[MAXN],vis[MAXN];

inline void solve(){
	scanf("%lld",&n);
	for( int i = 1 ; i <= n ; i ++ ) scanf("%lld",&p[i]);
	int Ans = 0,cod = 0;
	vector<int> A;
	for( int i = 1 ; i <= n ; i ++ ){
		if( vis[i] ) continue;
		int now = i,siz = 0;
		while( !vis[now] ) siz ++,vis[now] = 1,now = p[now];
		int S = 0;
		for( int now = i , coef = 1 ; ; now = p[now] ){
			S += now * coef,coef = -coef;
			if( p[now] == i ) break;
		}
		if( siz % 2 == 0 ) Ans += max( S , -S );
		else{
			int maxx = S;
			// cerr << S << "\n";
			for( now = i ; ; now = p[now] ){
				S = -S + 2 * now;
			// cerr << S << "\n";
				maxx = max( maxx , S );
				if( p[now] == i ) break;
			}
			int minn = -maxx;
			Ans += minn,cod ++;
			A.emplace_back( maxx - minn );
			// cerr << minn << " " << maxx << "\n";
		}
	}
	// cerr << Ans << "\n";
	sort( A.begin() , A.end() );
	reverse( A.begin() , A.end() );
	for( int i = 0 ; i < cod ; i += 2 ) Ans += A[i];
	printf("%lld\n",Ans);
	for( int i = 1 ; i <= n ; i ++ ) p[i] = vis[i] = 0;
}

signed main(){
	int t; scanf("%lld",&t);
	while( t -- ) solve();
	return 0;
}