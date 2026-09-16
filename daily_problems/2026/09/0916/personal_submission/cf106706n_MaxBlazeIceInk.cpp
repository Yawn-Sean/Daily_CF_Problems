#include<bits/stdc++.h>
using namespace std;

#define MAXN 3005

int n,ans[MAXN];
pair<int,int> A[MAXN],B[MAXN];

inline void solve(){
	scanf("%d",&n);
	for( int i = 1 ; i <= n ; i ++ ) scanf("%d",&A[i].first),A[i].second = i;
	for( int i = 1 ; i <= n ; i ++ ) scanf("%d",&B[i].first),B[i].second = i;
	sort( A + 1 , A + n + 1 );
	sort( B + 1 , B + n + 1 );
	for( int i = 1 ; i <= n ; i ++ ) ans[A[i].second] = B[n - i + 1].second;
	for( int i = 1 ; i <= n ; i ++ ) printf("%d ",ans[i]); puts("");
}

signed main(){
	int t; scanf("%d",&t);
	while( t -- ) solve();
	return 0;
}