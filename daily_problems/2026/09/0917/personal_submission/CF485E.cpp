#include<bits/stdc++.h>
using namespace std;

#define MAXN 1000005

int n,m,to[20][MAXN];
char s[MAXN],ans[MAXN];

inline pair<int,int> simu( int p , int x ){
	if( p == 1 ) return make_pair( 0 , 1 );
	//从 p 开始变换 x 次，最后到达哪里。如果中途到达了 1，返回经过的步数
	int tmp = p;
	for( int i = 19 ; i >= 0 ; i -- )
		if( x >= ( 1 << i ) )
			p = to[i][p],x -= 1 << i;
	if( p != 1 ) return make_pair( p , 0 );
	int res = 0; p = tmp;
	for( int i = 19 ; i >= 0 ; i -- ){
		if( to[i][p] == 1 ) continue;
		res += 1 << i,p = to[i][p];
	}
	return make_pair( res + 1 , 1 );
}

inline void transform( int k , int d ){
	for( int i = 1 , pnt = 1 ; i <= d ; i ++ ){
		for( int j = i ; j <= k ; j += d )
			to[0][j] = pnt - 1,pnt ++;
	}
	to[0][1] = 1;
	// for( int i = 1 ; i <= n ; i ++ ){
		// cerr << i << " " << to[0][i] << "\n";
	// }
	for( int i = 1 ; i < 20 ; i ++ )
		for( int j = 1 ; j <= k ; j ++ )
			to[i][j] = to[i - 1][to[i - 1][j]];
	for( int i = 1 ; i <= n ; i ++ ){
		auto [p,id] = simu( i < k ? i : k , min( n - i + 1 , n - k + 1 ) );
		if( id == 1 ){
			int st = i <= k ? 1 : i - k + 1;
			ans[st + p] = s[i];
		}
		else ans[n - k + p + 1] = s[i];
		// cerr << i << " " << p << " " << id << "\n";
	}
	for( int i = 1 ; i <= n ; i ++ ) s[i] = ans[i];
	// cerr << "\n";
}

signed main(){
	scanf("%s",s + 1); n = strlen( s + 1 );
	scanf("%d",&m);
	for( int i = 1 ; i <= m ; i ++ ){
		int k,d; scanf("%d%d",&k,&d);
		transform( k , d );
		printf("%s\n",s + 1);
	}
	return 0;
}