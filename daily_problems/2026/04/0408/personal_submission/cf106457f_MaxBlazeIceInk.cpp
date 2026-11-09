#include<bits/stdc++.h>
using namespace std;

//猜测可以区间 dp，都一定占一个区间
//需要求出有多少区间是 [l,r] 的超集。考虑暴力二维前缀和

#define MAXN 5005

int n,q,s[MAXN],a[MAXN],v[MAXN][MAXN],dp[MAXN][MAXN];
vector<int> T[MAXN];

signed main(){
	scanf("%d%d",&n,&q);
	for( int i = 1 ; i <= q ; i ++ ){
		int l,r; scanf("%d%d",&l,&r);
		T[r].emplace_back( l );
	}
	for( int i = n ; i >= 1 ; i -- ){
		for( int ele : T[i] ) a[ele] ++;
		for( int j = 1 , now = 0 ; j <= n ; j ++ ) now += a[j],s[j] += now,v[j][i] = s[j];
		for( int ele : T[i] ) a[ele] --;
	}
	for( int i = 1 ; i <= n ; i ++ ) dp[i][i] = v[i][i];
	for( int len = 2 ; len <= n ; len ++ ){
		for( int l = 1 ; l + len - 1 <= n ; l ++ ){
			int r = l + len - 1;
			dp[l][r] = max( dp[l][r - 1] + v[l][r] , dp[l + 1][r] + v[l][r] );
		}
	}
	printf("%d\n",dp[1][n]);
	return 0;
}