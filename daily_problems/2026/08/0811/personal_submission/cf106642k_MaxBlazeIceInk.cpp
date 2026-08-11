#include<bits/stdc++.h>
using namespace std;

#define int long long
#define MAXN 200005

int n,m,R[MAXN],C[MAXN];
vector<int> E[MAXN],ans[MAXN];
char s[MAXN];

inline void solve(){
	scanf("%lld%lld",&n,&m);
	for( int i = 1 ; i <= n ; i ++ ){
		E[i].resize( m + 1 ),ans[i].resize( m + 1 );
		scanf("%s",s + 1);
		for( int j = 1 ; j <= m ; j ++ ) E[i][j] = s[j] - '0';
	}
	for( int i = 1 ; i <= n ; i ++ )
		for( int j = 1 ; j <= m ; j ++ ) R[i] += E[i][j],C[j] += E[i][j];
	for( int i = 1 ; i <= n ; i ++ ){
		int c = 0;
		for( int j = 1 ; j <= m ; j ++ ){
			if( E[i][j] ) c += C[j] - 1;
			else ans[i][j] += c;
		}
		c = 0;
		for( int j = m ; j >= 1 ; j -- ){
			if( E[i][j] ) c += C[j] - 1;
			else ans[i][j] += c;
		}
	}
	for( int j = 1 ; j <= m ; j ++ ){
		int c = 0;
		for( int i = 1 ; i <= n ; i ++ ){
			if( E[i][j] ) c += R[i] - 1;
			else ans[i][j] += c;
		}
		c = 0;
		for( int i = n ; i >= 1 ; i -- ){
			if( E[i][j] ) c += R[i] - 1;
			else ans[i][j] += c;
		}
	}
	int Ans = 0,tot = 0,idx = 0;
	for( int i = 1 ; i <= n ; i ++ )
		for( int j = 1 ; j <= m ; j ++ ){
			if( !E[i][j] ){
				ans[i][j] += R[i] * C[j];
				if( ans[i][j] >= Ans ) Ans = ans[i][j];
			}
			else tot += ( R[i] - 1 ) * ( C[j] - 1 );
		}
	for( int i = 1 ; i <= n ; i ++ )
		for( int j = 1 ; j <= m ; j ++ ){
			if( !E[i][j] ){
				if( ans[i][j] == Ans ) idx ++;
			}
		}
	printf("%lld %lld\n",Ans + tot,idx);
	for( int i = 1 ; i <= n ; i ++ ) ans[i].clear(),E[i].clear();
	for( int i = 1 ; i <= max( n , m ) ; i ++ ) R[i] = C[i] = 0;
}

signed main(){
	int t; scanf("%lld",&t);
	while( t -- ) solve();
	return 0;
}