#include<bits/stdc++.h>
using namespace std;

#define int long long 
#define MAXN 100005

int n,m,k,w[MAXN],v[MAXN],as[MAXN],acnt,b[MAXN],cnt[MAXN],c[MAXN];

inline int S( int x ){ return x * ( x + 1 ) / 2; }

inline bool check( int x ){
	//尝试把 x 完整取完
	int num = 0;
	for( int i = 1 ; i <= n ; i ++ ){
		if( v[i] <= x ) num += k - x + 1;
		else{
			num += k - v[i] + 1;
			if( b[i] >= x ) num ++;
		}
	}
	return num <= m;
}

inline int getans( int x ){
	//每个元素完整取到 x
	int rem = m,ans = 0;
	for( int i = 1 ; i <= n ; i ++ ){
		if( v[i] <= x ){
			rem -= k - x + 1;
			ans += S( k ) - S( x - 1 );
			c[i] = min( x - 1 , w[i] - ( S( k ) - S( x - 1 ) ) );
		}
		else{
			rem -= k - v[i] + 1;
			ans += S( k ) - S( v[i] - 1 );
			c[i] = b[i];
			if( b[i] >= x ) rem --,ans += b[i],c[i] = 0;
		}
		// cerr << i << " " << c[i] << " " << ans << "\n";
	}
	sort( c + 1 , c + n + 1 );
	for( int i = n ; i >= 1 ; i -- ){
		if( rem ){
			rem --;
			ans += c[i];
		}
		else break;
	}
	return ans;
}

signed main(){
	scanf("%lld%lld%lld",&n,&m,&k);
	for( int i = 1 ; i <= n ; i ++ ) scanf("%lld",&w[i]);
	vector<int> A;
	for( int i = 1 ; i <= n ; i ++ ){
		int l = 1,r = k,ans = k + 1;
		while( l <= r ){
			int mid = ( l + r ) >> 1;
			if( S( k ) - S( mid - 1 ) <= w[i] ) ans = mid,r = mid - 1;
			else l = mid + 1;
		}
		// cerr << i << " " << v[i] << "\n";
		//i 可以完整取到的部分
		v[i] = ans;
		///剩余部分
		b[i] = w[i] - ( S( k ) - S( ans - 1 ) );
	}
	//注意，有可能一个都取不干净/
	int l = 1,r = k,ans = k + 1;
	while( l <= r ){
		int mid = ( l + r ) >> 1;
		if( check( mid ) ) ans = mid,r = mid - 1;
		else l = mid + 1; 
	}
	// cerr << ans << "\n";
	//[ans,k] 可以完整取完
	printf("%lld\n",getans( ans ));
	return 0;
}