#include<bits/stdc++.h>
using namespace std;

#define int long long
#define INF (int)1e18
#define MAXN 200005

int N,P[MAXN],A[MAXN],B[MAXN],C[MAXN];
int rem[MAXN];

inline void solve(){
	scanf("%lld",&N);
	int S = 0;
	for( int i = 1 ; i <= N ; i ++ ) scanf("%lld",&P[i]),S += P[i];
	int K = S - 1;
	//总池 (K + 1)N
	//P[i] / S = occupy / (K+1)N
	for( int i = 1 ; i <= N ; i ++ ) P[i] *= N,rem[i] = P[i];
	for( int i = 1 ; i <= N ; i ++ ){
		int minn = INF,id = 0;
		for( int j = 1 ; j <= N ; j ++ )
			if( rem[j] && rem[j] < minn ) minn = rem[j],id = j;
		if( minn >= K + 1 ){
			A[i] = B[i] = id,C[i] = 0;
			rem[id] -= K + 1;
		}
		else{
			int ned = K + 1 - minn;
			rem[id] = 0;
			if( ned ){
				int id2 = 0;
				for( int j = 1 ; j <= N ; j ++ )
					if( rem[j] && rem[j] >= ned ){ id2 = j; break; }
				A[i] = id2,B[i] = id,C[i] = ned;
				rem[id2] -= ned;
			}
		}
	}
	printf("%lld\n",K);
	for( int i = 1 ; i <= N ; i ++ ){
		printf("%lld",A[i]);
		if( i < N ) printf(" ");
	}
	puts("");
	for( int i = 1 ; i <= N ; i ++ ){
		printf("%lld",B[i]);
		if( i < N ) printf(" ");
	}
	puts("");
	for( int i = 1 ; i <= N ; i ++ ){
		printf("%lld",C[i]);
		if( i < N ) printf(" ");
	}
	puts("");
	return;
}

signed main(){
	int t = 1;
	while( t -- ) solve();
	return 0;
}