#include<bits/stdc++.h>
using namespace std;

#define int long long
#define mod 998244353
#define MAXN 100005

int fac[MAXN],inv[MAXN],ifac[MAXN],p2[MAXN];

int N,D;

inline int C( int n , int m ){ return fac[n] * ifac[m] % mod * ifac[n - m] % mod; }

signed main(){
	fac[0] = inv[1] = ifac[0] = 1;
	for( int i = 1 ; i < MAXN ; i ++ ) fac[i] = fac[i - 1] * i % mod;
	for( int i = 2 ; i < MAXN ; i ++ ) inv[i] = ( mod - mod / i ) * inv[mod % i] % mod;
	for( int i = 1 ; i < MAXN ; i ++ ) ifac[i] = ifac[i - 1] * inv[i] % mod;
	p2[0] = 1;
	for( int i = 1 ; i < MAXN ; i ++ ) p2[i] = p2[i - 1] * inv[2] % mod;
	scanf("%lld%lld",&N,&D);
	int cnt = N / 2,id = -1;
	for( int i = 0 ; i <= cnt ; i ++ ){
		int dinv = i - ( cnt - i );
		if( dinv == D ){ id = i; break; }
	}
	if( id == -1 ){ puts("0"); return 0; }
	if( N % 2 == 0 ){
		int ans = 0;
		for( int i = 0 , coef = 1 ; i <= cnt ; i ++ ){
			//i 对相邻
			ans = ( ans + C( cnt , i ) * fac[N - i] % mod * p2[cnt - i] % mod * coef % mod ) % mod;
			coef = mod - coef;
		}
		printf("%lld\n",ans * C( cnt , id ) % mod);
	}
	else{
		int ans1 = 0;
		for( int i = 0 , coef = 1 ; i <= cnt ; i ++ ){
			//i 对相邻
			ans1 = ( ans1 + C( cnt , i ) * fac[N - i - 1] % mod * p2[cnt - i] % mod * coef % mod ) % mod;
			coef = mod - coef;
		}
		ans1 = ans1 * N % mod;
		//钦定一个包和 N 放在一起，这个包视作自由元，N 个元素，减少
		//
		int ans2 = 0;
		for( int i = 0 , coef = 1 ; i < cnt ; i ++ ){
			//i 对相邻
			ans2 = ( ans2 + C( cnt - 1 , i ) * fac[N - i - 2] % mod * p2[cnt - 1 - i] % mod * coef % mod ) % mod;
			coef = mod - coef;
		}
		cerr << ans2 << "\n";
		ans2 = ans2 * cnt % mod;
		printf("%lld\n",( ans1 + ans2 ) % mod * C( cnt , id ) % mod);
	}
	return 0;
}

//0 1 2