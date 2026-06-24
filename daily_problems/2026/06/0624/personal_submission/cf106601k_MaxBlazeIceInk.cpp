#include<bits/stdc++.h>
using namespace std;

#define MAXN 300005
#define MAXV 1000005

const int V = 1000000;

int n,q,a[MAXN],cnt[MAXV],ans[MAXV];
vector<int> f[MAXV];

inline void modi( int x , int i ){
	for( int ele : f[x] ) ans[ele] += i;
}

signed main(){
	for( int i = 1 ; i <= V ; i ++ )
		for( int j = i ; j <= V ; j += i ) f[j].emplace_back( i );
	scanf("%d%d",&n,&q);
	for( int i = 1 ; i <= n ; i ++ ) scanf("%d",&a[i]),cnt[a[i]] ++;
	for( int i = 1 ; i <= V ; i ++ ) modi( cnt[i] , 1 );
	for( int i = 1 ; i <= q ; i ++ ){
		int op; scanf("%d",&op);
		if( op == 1 ){
			int p,c; scanf("%d%d",&p,&c);
			modi( cnt[a[p]] , -1 );
			cnt[a[p]] --;
			modi( cnt[a[p]] , 1 );
			a[p] = c;
			modi( cnt[a[p]] , -1 );
			cnt[a[p]] ++;
			modi( cnt[a[p]] , 1 );
		}
		else{
			int x; scanf("%d",&x);
			printf("%d\n",ans[x]);
		}
	}
	return 0;
}