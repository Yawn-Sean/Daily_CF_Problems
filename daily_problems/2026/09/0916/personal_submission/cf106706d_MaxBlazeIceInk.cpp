#include<bits/stdc++.h>
using namespace std;

#define MAXN 405

inline int In(){
	int x; scanf("%d",&x);
	return x;
}

inline int Ask( vector<int> A ){
	printf("? %d",(int)A.size());
	for( int ele : A ) printf(" %d",ele);
	puts(""); fflush( stdout );
	return In();
}

int n,ans[MAXN],p[MAXN];

//1 x ->
//如果有 2：
//如果有 1，那些 1 的一定是 F，自己一定是 T
//如果有 0，自己一定是 M 2 的一定是 T
//找到 T 了，就结束了

//没有 2，自己一定是 F，如果有 1 就是 T

inline void judgeF( int x ){
	//ans[x] = 'F'
	for( int i = 1 ; i <= n ; i ++ ){
		if( i == x || ans[i] == 'F' ) continue;
		vector<int> A;
		A.emplace_back( x ),A.emplace_back( i );
		if( Ask( A ) == 1 ) ans[i] = 'T';
		else ans[i] = 'M';
	}
}

inline void judgeT( int x ){
	//ans[x] = 'T'
	for( int i = 1 ; i <= n ; i ++ ){
		if( i == x || ans[i] == 'T' ) continue;
		vector<int> A;
		A.emplace_back( x ),A.emplace_back( i );
		if( Ask( A ) == 1 ) ans[i] = 'F';
		else ans[i] = 'M';
	}
}

signed main(){
	scanf("%d",&n);
	vector<int> A; A.emplace_back( 1 );
	int maxx = 0;
	for( int i = 2 ; i <= n ; i ++ ){
		A.emplace_back( i );
		p[i] = Ask( A );
		A.pop_back();
		maxx = max( maxx , p[i] );
	}
	if( maxx == 2 ){
		//有 2
		int c1 = 0;
		for( int i = 2 ; i <= n ; i ++ ) c1 |= p[i] == 1;
		if( c1 ){
			ans[1] = 'T';
			int id = 0;
			for( int i = 2 ; i <= n ; i ++ )
				if( p[i] == 1 ) ans[i] = 'F',id = i;
			//找到某个 F 去问
			judgeF( id );
		}
		else{
			//没有 1，自己一定是 M。随便找一个 T
			int id = 0;
			for( int i = 2 ; i <= n ; i ++ )
				if( p[i] == 2 ) ans[i] = 'T',id = i;
			//找到某个 F 去问
			judgeT( id );
		}
	}
	else{
		//自己一定是 F，找一个 T
		//没有 1，自己一定是 M。随便找一个 T
		int id = 0;
		for( int i = 2 ; i <= n ; i ++ )
			if( p[i] == 1 ) ans[i] = 'T',id = i;
		//找到某个 F 去问
		judgeT( id );
	}
	printf("! ");
	for( int i = 1 ; i <= n ; i ++ ) printf("%c",(char)(ans[i]));
	puts(""); fflush( stdout );
	return 0;
}