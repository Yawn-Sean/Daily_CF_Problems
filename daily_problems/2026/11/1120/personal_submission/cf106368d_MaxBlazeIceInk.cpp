#include<bits/stdc++.h>
using namespace std;

#define MAXN 1000005

int n,T,t[MAXN],st[MAXN],top;

inline int In(){
	int x; scanf("%d",&x);
	return x;
}

signed main(){
	scanf("%d",&T); n = T / 2;
	int id = 0;
	for( int i = 1 ; i <= T ; i ++ ){
		vector< pair<int,int> > ans;
		char s[4]; scanf("%s",s + 1);
		if( s[1] == '+' ){
			t[++id] = In();
		}
		else{
			int x; scanf("%d",&x);
			ans.emplace_back( make_pair( 2 , st[top] ) ),top --;
		}
		int w = 2 * ( i & ( -i ) ) - 1;
		//排序最上面的 w 个元素
		vector<int> tmp;
		if( s[1] == '+' ) tmp.emplace_back( id );
		while( w && top ){
			w --;
			int v = st[top];
			ans.emplace_back( make_pair( 2 , v ) );
			tmp.emplace_back( v );
			top --;
		}
		sort( tmp.begin() , tmp.end() , [&]( int i , int j ){ return t[i] > t[j]; } );
		for( auto x : tmp ){
			ans.emplace_back( make_pair( 1 , x ) );
			st[++top] = x;
		}
		printf("%d\n",ans.size());
		for( auto [t,x] : ans ) printf("%d %d\n",t,x);
		fflush( stdout );
	}
	return 0;
}