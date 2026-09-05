#include<bits/stdc++.h>
using namespace std;

int n;

inline int In(){
	int x; scanf("%d",&x);
	return x;
}

inline int ask( int l , int r ){
	printf("? %d %d\n",l,r); fflush( stdout );
	return In();
}

inline int Solve( int len , int L , int R ){
	int l = L,r = R,ans = -1;
	while( l <= r ){
		int mid = ( l + r ) >> 1;
		if( ask( mid - len + 1 , mid ) ) ans = mid,r = mid - 1;
		else l = mid + 1;
	}
	return ans;
}

inline void report( int x ){
	printf("! %d\n",x); fflush( stdout );
	return;
}

inline void solve(){
	scanf("%d",&n);
	int l = 1;
	for( int l = 1 , now = 1 ; ; l <<= 1 ){
		int r = now + l - 1;
		if( r > n ){
			// cerr << now << " " << n << "\n";
			report( Solve( l , now , n ) );
			return;
		}
		else{
			int p = ask( now , now + l - 1 );
			if( p ){
				report( Solve( l , now , now + l - 1 ) );
				return;
			}
			else{
				now += l;
			}
		}
	}
}

signed main(){
	int t = 1;
	while( t -- ) solve();
	return 0;
}