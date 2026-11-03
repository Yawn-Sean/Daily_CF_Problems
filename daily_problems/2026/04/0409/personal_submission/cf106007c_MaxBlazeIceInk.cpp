#include<bits/stdc++.h>
using namespace std;

#define MAXN 200005

int n,m,a[MAXN],s[MAXN];

inline void solve(){
	scanf("%d%d",&n,&m);
	for( int i = 1 ; i <= n ; i ++ ) scanf("%d",&a[i]),s[i] = s[i - 1] + a[i];
	for( int d = 1 ; d <= m ; d ++ ){
		int now = 1;
		while( now <= n ){
			//最大的 x 使得 s[x] - s[now - 1] <= m - d
			//意义不明的暴力题
			//直接对前缀和开桶标记位置可以去掉二分
			int l = now,r = n,ans = now - 1;
			while( l <= r ){
				int mid = ( l + r ) >> 1;
				if( s[mid] - s[now - 1] <= m - d ) ans = mid,l = mid + 1;
				else r = mid - 1;
			}
			//吃完 ans，走到 ans + 1
			if( ans == n ){
				now = n + 1;
				break;
			}
			if( m - ( s[ans] - s[now - 1] ) < a[ans + 1] ){ now = -1; break; }
			now = ans + 2;
		}
		if( now == n + 1 ){
			printf("%d\n",d);
			return;
		}
	}
}

signed main(){
	int t; scanf("%d",&t);
	while( t -- ) solve();
	return 0;
}