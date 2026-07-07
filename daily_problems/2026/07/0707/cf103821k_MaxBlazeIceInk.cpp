#include<bits/stdc++.h>
using namespace std;

#define int long long
#define MAXN 200005
#define mod 1000000007

int N,M,L[MAXN],R[MAXN],dif[MAXN],d2[MAXN];

inline void solve(){
	scanf("%lld%lld",&N,&M);
	for( int i = 1 ; i <= N ; i ++ ) scanf("%lld%lld",&L[i],&R[i]),dif[L[i]] += M - R[i] + 1;
	for( int i = M - 1 ; i >= 1 ; i -- ) dif[i] += dif[i + 1];
	for( int i = 1 ; i <= N ; i ++ ) d2[R[i]] += L[i];
	int Ans = 0;
	for( int i = 1 ; i <= M ; i ++ ){
		Ans += dif[i + 1] * d2[i] % mod;
	}
	printf("%lld\n",Ans % 1000000007);
	for( int i = 0 ; i <= M + 1 ; i ++ ) dif[i] = d2[i] = 0;
}

signed main(){
	int t; scanf("%lld",&t);
	while( t -- ) solve();
	return 0;
}