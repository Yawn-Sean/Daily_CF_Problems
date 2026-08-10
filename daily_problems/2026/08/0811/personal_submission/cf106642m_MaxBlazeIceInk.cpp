#include<bits/stdc++.h>
using namespace std;

#define MAXN 200005

int n,a[MAXN],b[MAXN];

inline void solve(){
	scanf("%d",&n);
	for( int i = 1 ; i <= n ; i ++ ) scanf("%d",&a[i]);
	for( int i = 1 ; i <= n ; i ++ ) scanf("%d",&b[i]);
	long long ans = 0;
	map<int,int> M,N;
	map< pair<int,int> , int > P;
	for( int i = 1 ; i <= n ; i ++ ){
		ans += M[a[i] + b[i]];
		ans += N[a[i] - b[i]];
		ans -= P[make_pair( a[i] , b[i] )];
		M[a[i] + b[i]] ++,N[a[i] - b[i]] ++,P[make_pair( a[i] , b[i] )] ++;
	}
	printf("%lld\n",ans);
}

signed main(){
	int t; scanf("%d",&t);
	while( t -- ) solve();
	return 0;
}