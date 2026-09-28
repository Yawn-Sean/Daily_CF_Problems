#include<bits/stdc++.h>
using namespace std;

#define int long long
#define MAXN 2005
#define INF (int)1e18

const int W = 500,Lim = 2000,B = 20000000;

int n,ord;

//不妨变成递归的问题

int Solve( int n , int ord ){
	if( ord % 2 ) return ord / 2 + 1;
	if( n % 2 == 0 ) return n / 2 + Solve( n / 2 , ord / 2 );
	else return n / 2 + 1 + Solve( n / 2 , ( ord / 2 - 1 == 0 ? n / 2 : ord / 2 - 1 ) );
}

inline void solve(){
	scanf("%lld%lld",&n,&ord);
	printf("%lld\n",Solve( n , ord ));
}

signed main(){
	int t; scanf("%lld",&t);
	while( t -- ) solve();
	return 0;
}