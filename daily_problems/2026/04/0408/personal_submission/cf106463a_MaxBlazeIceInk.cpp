#include<bits/stdc++.h>
using namespace std;

#define MAXN 500005

int n,k,x,y,a[MAXN],s[MAXN],lst[MAXN],to[MAXN];

inline void solve(){
	scanf("%d%d%d%d",&n,&k,&x,&y);
	for( int i = 1 ; i <= k ; i ++ ) scanf("%d",&a[i]),s[i] = ( s[i - 1] + a[i] ) % n;
	for( int i = k ; i >= 1 ; i -- ){
		int tar = ( x - y + n + s[i] ) % n;
		if( lst[tar] ) to[i] = to[lst[tar]];
		else to[i] = i;
		lst[s[i]] = i;
	}
	for( int st = 0 ; st < n ; st ++ ){
		if( st == x ) continue;
		int r = ( x - st + n ) % n;
		if( lst[r] ){
			int res = y,sum = ( s[k] - s[to[lst[r]]] + n ) % n;
			printf("%d ",( y + sum ) % n);
		}
		else{
			printf("%d ",( st + s[k] ) % n);
		}
	}
	puts("");
	for( int i = 0 ; i < n ; i ++ ) lst[i] = 0;
	for( int i = 0 ; i <= k ; i ++ ) to[i] = 0;
}

signed main(){
	int t; scanf("%d",&t);
	while( t -- ) solve();
	return 0;
}