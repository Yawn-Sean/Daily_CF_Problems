#include<bits/stdc++.h>
using namespace std;

int k,s,e,to[1005];

vector<pair<int,int>> ans;

int S[1005][1005],cnt[1005];

signed main(){
	scanf("%d%d%d",&k,&s,&e);
	for( int i = 1 , c = 1 ; i <= k ; i ++ )
		if( i != s && i != e ) to[++c] = i;
	to[1] = s,to[k] = e;
	for( int i = k - 1 ; i > 1 ; i -- ){
		int aim = k - i + 1;
		for( int j = k ; j >= aim ; j -- ) ans.emplace_back( make_pair( 1 , j ) );
		for( int j = aim + 1 ; j <= k ; j ++ ) ans.emplace_back( make_pair( j , aim ) );
	}
	ans.emplace_back( make_pair( 1 , k ) );
	for( int i = k - 1 ; i >= 2 ; i -- ){
		int c = k - i + 1;
		for( int j = i + 1 ; j < k ; j ++ ) ans.emplace_back( make_pair( i , j ) );
		ans.emplace_back( i , 1 );
		ans.emplace_back( make_pair( i , k ) );
		ans.emplace_back( make_pair( 1 , k ) );
		for( int j = k - 1 ; j > i ; j -- ) ans.emplace_back( make_pair( j , k ) );
	}
	printf("%d\n",(int)ans.size());
	// for( int i = k * ( k - 1 ) / 2 ; i >= 1 ; i -- ) S[to[1]][++cnt[to[1]]] = i;
	for( auto [u,v] : ans ){
		printf("%d %d\n",to[u],to[v]);
		// S[to[v]][++ cnt[to[v]]] = S[to[u]][cnt[to[u]] --];
		// for( int i = 1 ; i <= k ; i ++ , cerr << "\n" )
			// for( int j = 1 ; j <= cnt[i] ; j ++ ) cerr << S[i][j] << " ";
		// cerr << "-----------------\n";
	}
	return 0;
}