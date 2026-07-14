#include<bits/stdc++.h>
using namespace std;

#define MAXN 400005
#define INF (int)1e9

int n,m,p[MAXN],Q[MAXN],ava[MAXN];
pair<int,int> ans[MAXN];
set<int> S[MAXN],T[MAXN];

//存储 a[i] - i？

signed main(){
	scanf("%d%d",&n,&m);
	for( int i = 0 ; i < n ; i ++ ) scanf("%d",&p[i]);
	for( int i = 0 ; i < m ; i ++ ){ int t; scanf("%d",&t); Q[t] = i + 1; }
	//灭/亮的事件是在人到达之前先触发的,S 是灭事件,T 是亮事件
	set<int> Ava;
	for( int i = 0 ; i < n ; i ++ ){
		//位置 i 的鬼时间线前移 i，相当于先自己走 i 秒
		int t = i % ( 2 * p[i] );
		if( t < p[i] ) ava[i] = 1,S[p[i] - t].insert( i ),Ava.insert( i );
		else ava[i] = 0,T[2 * p[i] - t].insert( i );
	}
	//灭的时候，必然在 +p[i] 的时候亮起
	int V = 100000;
	for( int tim = 0 ; tim <= V + 5 ; tim ++ ){
		//如果一个灭的事件成功灭掉了就加，否则不加
		for( int ele : S[tim] ){
			if( !ava[ele] ) continue;
			ava[ele] = 0,Ava.erase( Ava.find( ele ) );
			//在第 tim + p[ele] 秒亮起
			T[tim + p[ele]].insert( ele );
		}
		//亮的事件是强制触发的
		for( int ele : T[tim] ){
			assert( !ava[ele] );
			Ava.insert( ele ),ava[ele] = 1;
			S[tim + p[ele]].insert( ele );
		}
		// cerr << tim << " " << ava[1] << "\n";
		int id = Q[tim];
		if( id ){
			id --;
			if( !Ava.size() ) ans[id] = make_pair( -1 , -1 );
			else{
				int pos = *Ava.begin();
				ans[id] = make_pair( pos , tim + pos );
				//已经平移过了，这里
				S[tim + 1].insert( pos );
			}
		}
	}
	for( int i = 0 ; i < m ; i ++ ) printf("%d %d\n",ans[i].first,ans[i].second);
	return 0;
}