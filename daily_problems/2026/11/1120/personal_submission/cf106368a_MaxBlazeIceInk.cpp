#include<bits/stdc++.h>
using namespace std;

#define MAXN 2000005
#define INF (int)1e9

int a,m,b,n,dis[MAXN],vis[MAXN],pre[MAXN],prepp[MAXN];

vector<int> ans,tmp;
int Ans;

inline void bfs( int x , int st ){
	for( int i = 0 ; i < n ; i ++ ) dis[i] = INF,vis[i] = pre[i] = prepp[i] = 0;
	queue<int> Q;
	Q.push( x ),dis[x] = 0;
	while( !Q.empty() ){
		int u = Q.front(); Q.pop();
		int nu = ( u + m ) % n;
		if( dis[nu] > dis[u] + 1 ){
			dis[nu] = dis[u] + 1;
			pre[nu] = 0,prepp[nu] = u;
			Q.push( nu );
		}
		nu = ( ( u - m ) % n + n ) % n;
		if( dis[nu] > dis[u] + 1 ){
			dis[nu] = dis[u] + 1;
			pre[nu] = 1,prepp[nu] = u;
			Q.push( nu );
		}
		nu = 1ll * u * m % n;
		if( dis[nu] > dis[u] + 1 ){
			dis[nu] = dis[u] + 1;
			pre[nu] = 2,prepp[nu] = u;
			Q.push( nu );
		}
	}
	// cerr << dis[b] << "\n";
	if( dis[b] + st < Ans ){
		Ans = dis[b] + st;
		int now = b;
		ans.clear();
		while( now != x ){
			int op = pre[now],lst = prepp[now];
			if( op == 0 ) ans.emplace_back( '+' );
			else if( op == 1 ) ans.emplace_back( '-' );
			else ans.emplace_back( '*' );
			now = lst;
		}
		reverse( tmp.begin() , tmp.end() );
		for( int ele : tmp ) ans.emplace_back( ele );
		reverse( ans.begin() , ans.end() );
	}
}

signed main(){
	scanf("%d%d%d%d",&a,&m,&b,&n);
	Ans = INF;
	bfs( ( a % n + n ) % n , 0 );
	tmp.emplace_back( '%' );
	bfs( ( a % m + m ) % m % n , 1 );
	tmp.clear();
	tmp.emplace_back( '*' );
	tmp.emplace_back( '%' );
	bfs( 0 , 2 );
	if( Ans == INF ) puts("-1");
	else{
		printf("%d\n",Ans);
		for( int ele : ans ) printf("%c",(char)ele);
	}
	return 0;
}