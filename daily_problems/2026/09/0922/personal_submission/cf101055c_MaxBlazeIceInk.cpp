#include<bits/stdc++.h>
using namespace std;

#define int long long
#define MAXN 1000005

int n,f[MAXN];

//小于等于 x 的满足条件的数的个数
//随便容斥一下.jpg
inline int F( int x ){
	int maxx = 0;
	while( ( maxx + 1 ) * ( maxx + 1 ) <= x ) maxx ++;
	int ans = x;
	for( int i = maxx ; i >= 2 ; i -- ){
		f[i] = x / ( i * i );
		for( int j = 2 * i ; j <= maxx ; j += i )
			f[i] -= f[j];
		ans -= f[i];
	}
	return ans;
}

inline void solve(){
	scanf("%lld",&n);
	int l = 1,r = (int)1e11,ans = -1;
	while( l <= r ){
		int mid = ( l + r ) >> 1;
		if( F( mid ) >= n ) ans = mid,r = mid - 1;
		else l = mid + 1;
	}
	printf("%lld\n",ans);
}

signed main(){
	int t; scanf("%lld",&t);
	while( t -- ) solve();
	return 0;
}