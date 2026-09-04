#include<bits/stdc++.h>
using namespace std;

#define MAXN 1000005

int n,a[MAXN];

inline void solve(){
	scanf("%d",&n);
	for( int i = 1 ; i <= n ; i ++ ) scanf("%d",&a[i]);
	if( n == 1 ){ puts("1"); return; }
	int res = 0;
	for( int i = 1 ; i < n ; i ++ ) res += a[i] == a[i + 1];
	res += a[1] == a[n];
	if( res == 0 ){ puts("1"); return; }
	else if( res == 1 ){ puts("2"); return; }
	int lst = 1,ans = 0,fir = 0;
	vector< pair<int,int> > A;
	for( int i = 1 ; i < n ; i ++ ){
		if( a[i] == a[i + 1] ){
			ans ++;
			if( !fir ) fir = i;
			//如果 lst = 1 且 a[1] != a[n]，这里不能算
			if( lst < i ){
				if( a[i] == a[lst] )
					if( lst != 1 || a[1] == a[n] ) ans ++;
			}
			lst = i + 1;
		}
	}
	if( a[1] == a[n] ){
		ans ++;
		// if( fir > 1 && a[1] == a[fir] ) ans ++;
		if( lst < n && a[lst] == a[n] ) ans ++; 
	}
	else{
		if( a[lst] == a[fir] ) ans ++;
	}
	printf("%d\n",ans);
}

signed main(){
	int t; scanf("%d",&t);
	while( t -- ) solve();
	return 0;
}