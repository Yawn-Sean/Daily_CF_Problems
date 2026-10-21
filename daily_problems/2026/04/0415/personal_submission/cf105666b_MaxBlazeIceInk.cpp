#include<bits/stdc++.h>
using namespace std;

#define MAXN 200005

int n;
multiset<int> A[2],B[2];

inline void solve(){
	scanf("%d",&n);
	for( int i = 1 ; i <= n ; i ++ ){
		int p,typ; scanf("%d%d",&p,&typ);
		A[typ].insert( p );
	}
	for( int i = 1 ; i <= n ; i ++ ){
		int p,typ; scanf("%d%d",&p,&typ);
		B[typ].insert( p );
	}
	//贪心打同色
	for( int i = 0 ; i < 2 ; i ++ ){
		multiset<int> R;
		for( int ele : A[i] ){
			set<int>::iterator it = B[i].upper_bound( ele * 2 );
			if( it != B[i].begin() ){
				it --;
				//如果实际小于就跳过
				if( *it < ele ) continue;
				B[i].erase( it );
				R.insert( ele );
			}
		}
		for( int ele : R ) A[i].erase( A[i].find( ele ) );
	}
	//直接混着打
	for( int ele : A[1] ) A[0].insert( ele );
	for( int ele : B[1] ) B[0].insert( ele );
	// for( int ele : A[0] ) cerr << ele << " ";
	// cerr << "\n";
	for( int ele : A[0] ){
		set<int>::iterator it = B[0].upper_bound( ele );
		if( it != B[0].begin() ){
			it --;
			B[0].erase( it );
		}
		else{
			puts("NO");
			A[0].clear(),A[1].clear(),B[0].clear(),B[1].clear();
			return;
		}
	}
	puts("YES");
	A[0].clear(),A[1].clear(),B[0].clear(),B[1].clear();
}

signed main(){
	int t; scanf("%d",&t);
	while( t -- ) solve();
	return 0;
}