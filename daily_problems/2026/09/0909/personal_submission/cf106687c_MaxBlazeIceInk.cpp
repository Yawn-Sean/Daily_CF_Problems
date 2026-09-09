#include<bits/stdc++.h>
using namespace std;

#define MAXN 105
#define int long long
#define mod 998244353

int a,b,c,ans[MAXN][MAXN][MAXN];

struct node{ int x,y,z; };
vector<node> N;

inline void solve(){
	scanf("%lld%lld%lld",&a,&b,&c);
	int m = min( { a,  b , c } );
	for( int i = 1 ; i <= m ; i ++ ){
		for( int j = i , k = 1 ; k <= m ; k ++ ){
			ans[i][j][k] = 1;
			j = j % m + 1;
		}
	}
	for( int i = m + 1 ; i <= a ; i ++ ){
		for( int j = 1 ; j <= m ; j ++ ){
			for( int k = 1 ; k <= m ; k ++ ){
				ans[i][j][k] = ans[( i - 1 ) % m + 1][j][k];
			}
		}
	}
	for( int i = 1 ; i <= a ; i ++ ){
		for( int j = m + 1 ; j <= b ; j ++ ){
			for( int k = 1 ; k <= m ; k ++ ){
				ans[i][j][k] = ans[i][( j - 1 ) % m + 1][k];
			}
		}
	}
	for( int i = 1 ; i <= a ; i ++ ){
		for( int j = 1 ; j <= b ; j ++ ){
			for( int k = m + 1 ; k <= c ; k ++ ){
				ans[i][j][k] = ans[i][j][( k - 1 ) % m + 1];
			}
		}
	}
	for( int i = 1 ; i <= a ; i ++ ){
		for( int j = 1 ; j <= b ; j ++ ){
			for( int k = 1 ; k <= c ; k ++ ){
				if( ans[i][j][k] ){
					N.emplace_back( node{ i , j , k } );
				}
			}
		}
	}
	printf("%lld\n",(int)N.size());
	for( node nn : N ){
		printf("%lld %lld %lld\n",nn.x,nn.y,nn.z);
	}
	for( int i = 1 ; i <= a ; i ++ ){
		for( int j = 1 ; j <= b ; j ++ ){
			for( int k = 1 ; k <= c ; k ++ ){
				ans[i][j][k] = 0;
			}
		}
	}
	N.clear();
}

signed main(){
	int t; scanf("%lld",&t);
	while( t -- ) solve();
	return 0;
}