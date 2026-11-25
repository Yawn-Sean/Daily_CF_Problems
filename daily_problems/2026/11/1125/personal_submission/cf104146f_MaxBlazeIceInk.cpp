#include<bits/stdc++.h>
using namespace std;

#define MAXN 1000005

int n,k;
vector<int> A[MAXN],ans1,ans2,A1,A2;
char s[MAXN];
vector< array<int,3> > P;

signed main(){
	scanf("%d%d",&n,&k);
	for( int i = 1 ; i <= n ; i ++ ){
		scanf("%s",s + 1);
		int len = strlen( s + 1 );
		for( int j = 1 ; j <= len ; j ++ ) A[i].emplace_back( s[j] - '0' );
	}
	//方案 1，Allin 奇数，只输一手多个 4/8/0，按优先级排序
	for( int i = 1 ; i <= n ; i ++ ){
		int p1 = 0,p2 = 0;
		for( int ele : A[i] ) p1 += ele % 2,p2 += ele % 4 == 0;
		P.emplace_back( array<int,3>{ p1 , p2 , i } );
	}
	sort( P.begin() , P.end() );
	reverse( P.begin() , P.end() );
	int vis = 0;
	for( int i = 0 ; i < k ; i ++ ){
		A1.emplace_back( get<2>(P[i]) );
		for( int ele : A[get<2>(P[i])] ){
			if( ele % 2 ) ans1.emplace_back( ele );
			if( ele % 4 == 0 && !vis ) ans1.emplace_back( ele ),vis = 1;
		}
	}
	//如果方案 1 实际上没有奇数，视作废方案
	if( vis && ans1.size() == 1 ) ans1.clear();
	//方案 2，Allin 偶数，使用纯 2/6 方案
	P.clear();
	for( int i = 1 ; i <= n ; i ++ ){
		int p1 = 0,p2 = 0;
		for( int ele : A[i] ) p1 += ele % 4 == 2;
		P.emplace_back( array<int,3>{ p1 , p2 , i } );
	}
	sort( P.begin() , P.end() );
	reverse( P.begin() , P.end() );
	for( int i = 0 , vis = 0 ; i < k ; i ++ ){
		A2.emplace_back( get<2>(P[i]) );
		for( int ele : A[get<2>(P[i])] ){
			if( ele % 4 == 2 ) ans2.emplace_back( ele );
		}
	}
	if( ans1.size() > ans2.size() ){
		for( int ele : A1 ) printf("%d ",ele); puts("");
		if( !ans1.size() ) puts("empty");
		for( int ele : ans1 ) printf("%d",ele); puts("");
	}
	else{
		for( int ele : A2 ) printf("%d ",ele); puts("");
		if( !ans2.size() ) puts("empty");
		for( int ele : ans2 ) printf("%d",ele); puts("");
	}
	return 0;
}