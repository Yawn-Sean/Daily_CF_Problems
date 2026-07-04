#include<bits/stdc++.h>
using namespace std;

#define int long long
#define MAXN 1005
int n,m;
int a[MAXN][MAXN],v[MAXN][MAXN];

signed main(){
	scanf("%lld%lld",&n,&m);
	for( int i = 1 ; i <= n ; i ++ )
		for( int j = 1 ; j <= m ; j ++ ) scanf("%lld",&a[i][j]);
	for( int i = 1 ; i <= n ; i ++ ){
		map<int,int> M;
		//a[i + t] + ( i + t ) = a[i] + i
		for( int j = m ; j >= 1 ; j -- )
			v[i][j] = M[a[i][j] + j],M[a[i][j] + j] ++;
	}
	int ans = 0;
	for( int j = 1 ; j <= m ; j ++ ){
		map<int,int> M;
		//a[i + t] - ( i + t ) = a[i] - i
		for( int i = n ; i >= 1 ; i -- )
			ans += v[i][j] * M[a[i][j] + i],M[a[i][j] + i] ++;
	}
	printf("%lld\n",ans);
	return 0;
}