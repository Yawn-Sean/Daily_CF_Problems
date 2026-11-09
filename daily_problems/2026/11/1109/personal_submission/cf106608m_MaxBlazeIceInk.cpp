#include<bits/stdc++.h>
using namespace std;

#define MAXN 405

int n,ans[MAXN],vis[MAXN];

inline int In(){
	int x; scanf("%d",&x);
	return x;
}

inline int ask( set<int> A , set<int> B ){
	printf("? %d %d\n",(int)A.size(),(int)B.size()); fflush( stdout );
	for( int ele : A ) printf("%d ",ele); puts(""); fflush( stdout );
	for( int ele : B ) printf("%d ",ele); puts(""); fflush( stdout );
	return In();
}

inline void Solve( set<int> S , set<int> T ){
	if( S.size() == 1 ){
		set<int> pp;
		int now = 0;
		for( int eval : T ){
			while( now < eval ) pp.insert( now ),now ++;
			int v = ask( S , pp );
			if( v != eval ){ ans[*S.begin()] = eval; return; }
		}
		return;
	}
	int mid = (int)S.size() / 2;
	set<int> S1,S2;
	for( int ele : S ){
		if( S1.size() == mid ){
			S2.insert( ele );
		}
		else S1.insert( ele );
	}
	// for( int ele : S )
	set<int> R,T1,T2; int now = 0;
	for( int eval : T ){
		while( now < eval ) R.insert( now ),now ++;
		int v = ask( S1 , R );
		if( v != eval ){
			T1.insert( eval );
			v = ask( S2 , R );
			if( v != eval ) T2.insert( eval );
		}
	//没有的直接归到 T2
		else T2.insert( eval );
	}
	Solve( S1 , T1 ),Solve( S2 , T2 );
}

inline void solve(){
	scanf("%d",&n);
	set<int> U1,U2,U3;
	memset( vis , 0 , sizeof( vis ) );
	for( int i = 1 ; i <= n ; i ++ ) U1.insert( i );
	int now = 0;
	while( now < n ){
		int v = ask( U1 , U3 );
		if( v > n ) break;
		vis[v] = 1;
		U3.insert( v ),now ++;
	}
	for( int i = 0 ; i <= n ; i ++ ) if( !vis[i] ) U2.insert( i );
	Solve( U1 , U2 );
	printf("! ");
	for( int i = 1 ; i <= n ; i ++ ) printf("%d ",ans[i]); puts("");
	fflush( stdout );
}

signed main(){
	int t; scanf("%d",&t);
	while( t -- ) solve();
	return 0;
}