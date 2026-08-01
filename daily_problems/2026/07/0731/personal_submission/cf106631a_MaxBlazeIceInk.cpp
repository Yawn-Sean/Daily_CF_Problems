#include<bits/stdc++.h>
using namespace std;

//开 long long
#define int long long
int R = 0;

inline int In(){
	R ++;
	int x; scanf("%lld",&x);
	return x;
}

inline void solve(){
	R = 0;
	printf("MUL 1\n"); fflush( stdout );
	int S = In(),tmp = S;
	vector<int> A;
	for( int p = 2 ; p * p <= tmp ; p ++ )
		if( tmp % p == 0 ){ A.emplace_back( p ); while( tmp % p == 0 ) tmp /= p; }
	if( tmp > 1 ) A.emplace_back( tmp );
	int ansa = 1,ansb = 1,siz = (int)A.size();
	for( int i = 0 ; i < siz ; i += 2 ){
		int p1 = A[i],p2 = i < siz - 1 ? A[i + 1] : 0;
		int c1 = 1,c2 = 1;
		while( p1 * A[i] <= 1000 ) p1 *= A[i],c1 ++;
		if( p2 ) while( p2 * A[i + 1] <= 1000 ) p2 *= A[i + 1],c2 ++;
		printf("MUL %lld\n",p1 * ( p2 ? p2 : 1 )); fflush( stdout );
		S = In();
		int cnt1 = 0,cnt2 = 0,tmp = S;
		while( tmp % A[i] == 0 ) tmp /= A[i],cnt1 ++;
		if( p2 ) while( tmp % A[i + 1] == 0 ) tmp /= A[i + 1],cnt2 ++;
		//乘了 c 之后有 cnt 个 p，爆了，说明原来有 cnt - c 个 p
		for( int j = 1 ; j <= cnt1 - c1 ; j ++ ) ansa *= A[i];
		if( p2 ) for( int j = 1 ; j <= cnt2 - c2 ; j ++ ) ansa *= A[i + 1];
		int R = 1;
		for( int j = 1 ; j <= cnt1 ; j ++ ) R *= A[i];
		if( p2 ) for( int j = 1 ; j <= cnt2 ; j ++ ) R *= A[i + 1];
		printf("DIV %lld\n",R); fflush(stdout);
		S = In();
		tmp = S;
		while( tmp % A[i] == 0 ) tmp /= A[i],ansb *= A[i];
		if( p2 ) while( tmp % A[i + 1] == 0 ) tmp /= A[i + 1],ansb *= A[i + 1];
	}
	printf("ANS %lld %lld\n",ansa,ansb); fflush( stdout );
}

signed main(){
	int t; scanf("%lld",&t);
	while( t -- ) solve();
	return 0;
}