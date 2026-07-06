#include<bits/stdc++.h>
using namespace std;

#define int long long
#define MAXN 500005
int n,X[MAXN],R[MAXN];

vector<int> pos,neg;

inline bool Test( int st ){
	int ad = 0,coe = 1;
	map<int,int> M; M[st] =1 ;
	for( int i = 2 ; i <= n ; i ++ ){
		int dis = X[i] - X[i - 1];
		ad = dis - ad,coe *= -1;
		M[coe * st + ad] ++;
	}
	for( int i = 1 ; i <= n ; i ++ ){ if( M[R[i]] <= 0 ) return 0; M[R[i]] --; }
	return 1;
}

inline void output( int st ){
	printf("%lld",st);
	int ad = 0,coe = 1;
	for( int i = 2 ; i <= n ; i ++ ){
		int dis = X[i] - X[i - 1];
		ad = dis - ad,coe *= -1;
		printf(" %lld",coe * st + ad);
	}
}

signed main(){
	scanf("%lld",&n);
	for( int i = 1 ; i <= n ; i ++ ) scanf("%lld",&X[i]);
	int ad = 0,coe = 1;
	pos.emplace_back( 0 );
	for( int i = 2 ; i <= n ; i ++ ){
		int dis = X[i] - X[i - 1];
		ad = dis - ad,coe *= -1;
		if( coe == -1 ) neg.emplace_back( ad );
		else pos.emplace_back( ad );
	}
	sort( pos.begin() , pos.end() );
	sort( neg.begin() , neg.end() );
	for( int i = 1 ; i <= n ; i ++ ) scanf("%lld",&R[i]);
	sort( R + 1 , R + n + 1 );
	//钦定 R[1] 是 pos[0]/neg[0]
	if( Test( R[1] - pos[0] ) ){ output( R[1] - pos[0] ); return 0; }
	if( Test( neg[0] - R[1] ) ) output( neg[0] - R[1] );
	return 0;
}