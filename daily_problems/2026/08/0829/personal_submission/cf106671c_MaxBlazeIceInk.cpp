#include<bits/stdc++.h>
using namespace std;

//序列长度足够大的时候就不用管了，直接在单个上模拟，否则暴力复制

#define int long long
#define mod 998244353
#define MAXN 4000005

int n,q,a[MAXN],val[MAXN],S = 0;

inline void chkadd( int &x , int k ){ x += k; if( x >= mod ) x -= mod; }
inline int reduce( int x ){ return x < 0 ? x + mod : x; }

signed main(){
	scanf("%lld",&n);
	int L = 2000000,R = 1999999;
	//取模陷阱
	for( int i = 1 ; i <= n ; i ++ ) scanf("%lld",&a[i]),a[i] %= mod,val[++R] = a[i],chkadd( S , a[i] );
	scanf("%lld",&q);
	int w = 1;
	for( int i = 1 ; i <= q ; i ++ ){
		int op; scanf("%lld",&op);
		if( op == 1 ){
			int x; scanf("%lld",&x); x %= mod;
			if( w ) val[++R] = x,chkadd( S , x );
			else val[--L] = x,chkadd( S , x );
		}
		else if( op == 2 ){
			if( w ) S = reduce( S - val[R] ),R --;
			else S = reduce( S - val[L] ),L ++;
		}
		else if( op == 3 ){
			w ^= 1;
		}
		else if( op == 4 ){
			if( R - L + 1 <= 500000 ){
				if( w ){
					int len = R - L + 1;
					for( int i = 1 ; i <= len ; i ++ ) R ++,val[R] = val[R - len];
					S = S * 2 % mod;
				}
				else{
					int len = R - L + 1;
					for( int i = 1 ; i <= len ; i ++ ) L --,val[L] = val[L + len];
					S = S * 2 % mod;
				}
			}
			else S = S * 2 % mod;
		}
		else{
			printf("%lld\n",S);
		}
	}
	return 0;
}