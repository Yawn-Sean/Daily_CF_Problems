#include<bits/stdc++.h>
using namespace std;

#define MAXN 1000005

typedef long long ll;

const int B = 325,V = 100000;

int n,q,a[MAXN];
vector<int> A[MAXN];

signed main(){
	scanf("%d",&n);
	for( int i = 1 ; i <= n ; i ++ ) scanf("%d",&a[i]),A[a[i]].emplace_back( i );
	int ans = 2 * n - 1;
	for( int i = 1 ; i <= V ; i ++ ){
		if( !A[i].size() ) continue;
		int siz = A[i].size(),p = 0;
		for( int j = 0 ; j + 1 < siz ; j ++ ) p = max( p , A[i][j + 1] - A[i][j] - 1 );
		p = max( p , A[i][0] + n - A[i][siz - 1] - 1 );
		ans = min( ans , p + n );
	}
	printf("%d\n",ans);
	return 0;
}