#include<bits/stdc++.h>
using namespace std;

#define int long long
#define mod 998244353
#define iv2 499122177

int N;

inline void solve(){
	scanf("%lld",&N);
	if( N == 1 ){ puts("1"); return; }
	int tmp = N,c = 0,minn = -1,lcm = 1;
	vector<int> A;
	for( int p = 2 ; p * p <= tmp ; p ++ ){
		if( tmp % p == 0 ){
			while( tmp % p == 0 ) tmp /= p;
			c ++;
			if( minn == -1 ) minn = p;
			A.emplace_back( p );
		}
	}
	if( tmp > 1 ) A.emplace_back( tmp );
	sort( A.begin() , A.end() );
	for( int ele : A ) lcm *= ele;
	int Ans = 0;
	if( !c ){
		//case1：N 为质数，一个周期内贡献是 p(p-1)/2
		printf("%lld\n",N % mod * ( ( N - 1 ) % mod ) % mod * iv2 % mod);
	}
	else{
		//case2：段长小于最小质因子，枚举段长即可
		assert( minn > 0 );
		for( int len = 1 ; len < minn ; len ++ ){
			//拆贡献，计算有多少个数的段长大于等于 len
			int res = 1;
			for( int ele : A )
				res *= ele - len,res %= mod;
			Ans += N / lcm % mod * res % mod;
			Ans %= mod;
		}
		printf("%lld\n",Ans);
	}
}

signed main(){
	int t; scanf("%lld",&t);
	while( t -- ) solve();
	return 0;
}