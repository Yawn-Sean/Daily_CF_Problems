#include<bits/stdc++.h>
using namespace std;

#define MAXN 1000005

int n,k,a[MAXN],notp[MAXN],prime[MAXN],ptot,cnt[30];
vector< pair<int,int> > C[MAXN];

int f[2][MAXN];

signed main(){
	notp[1] = 1;
	for( int i = 2 ; i < MAXN ; i ++ ){
		if( !notp[i] ){
			prime[++ptot] = i;
			for( int j = 2 * i ; j < MAXN ; j += i ) notp[j] = 1;
		}
	}
	scanf("%d%d",&n,&k);
	int g = 0;
	for( int i = 1 ; i <= n ; i ++ ) scanf("%d",&a[i]),g = gcd( g , a[i] );
	int ans = 1,c = 0;
	for( int id = 1 ; id <= ptot ; id ++ ){
		int p = prime[id];
		if( p > 1000 ) ans *= gcd( g , p ),g /= gcd( g , p );
		else{
			memset( cnt , 0 , sizeof( cnt ) );
			for( int i = 1 ; i <= n ; i ++ ){
				int c = 0,tmp = a[i];
				while( tmp % p == 0 ) tmp /= p,c ++;
				cnt[c] ++;
			}
			int coef = 1;
			for( int i = 1 ; i <= 20 ; i ++ ){
				//能不能凑到 i		
				int A = 0,B = 0; coef *= p; if( coef > MAXN ) break;
				for( int j = 0 ; j < i ; j ++ ) A += ( i - j ) * cnt[j];
				for( int j = i + 1 ; j <= 20 ; j ++ ) B += ( j - i ) * cnt[j];
				if( B >= A ){
					C[p].emplace_back( make_pair( A , coef ) );
					// cerr << p << " " << A << " " << coef << "\n";
				}
			}
		}
	}
	for( int i = 0 ; i <= k ; i ++ ) f[0][i] = f[1][i] = 0;
	f[0][0] = 1; int now = 0;
	for( int id = 1 ; id <= ptot ; id ++ ){
		int p = prime[id];
		if( p > 1000 ) continue;
		for( int j = 0 ; j <= k ; j ++ ) f[now ^ 1][j] = f[now][j];
		for( int j = 0 ; j <= k ; j ++ ){
			for( pair<int,int> t : C[p] ){
				int cost = t.first,val = t.second;
				if( f[now][j] && j + cost <= k ){
					f[now ^ 1][j + cost] = max( f[now ^ 1][j + cost] , f[now][j] * val );
				}
			}
		}
		now ^= 1;
	}
	int res = g;
	for( int i = 1 ; i <= k ; i ++ ){
		res = max( res , f[now][i] );
		printf("%d ",res * ans);
	}
	return 0;
}