#include<bits/stdc++.h>
using namespace std;

#define int long long
#define MAXN 200005

mt19937_64 rnd(20070414);

const int L = (int)1e9;

int n;

inline int In(){
	int x; scanf("%lld",&x);
	return x;
}

inline pair<int,int> ask( int d ){
	printf("? %lld\n",d); fflush( stdout );
	char s[5];
	scanf("%s",s + 1); int k = s[1] == 'N' ? 0 : 1;
	return make_pair( k , In() );
}

inline void report( int x ){
	printf("! %lld\n",x); fflush( stdout );
}

inline int dis( int x , int y ){ return min( abs( y - x ) , L - abs( x - y ) ); }

//爆 int 是人类吗

signed main(){
	scanf("%lld",&n);
	int st = rnd() % L + 1;
	auto [u,v] = ask( st ); if( u ) n --;
	int l = ( st - v + L - 1 ) % L + 1,r = ( st + v + L - 1 ) % L + 1;
	for( int i = 1 ; i < min( n - 1 , 29ll ) ; i ++ ){
		int t = rnd() % 2,now = t ? l : r;
		auto [u,v] = ask( now );
		if( !u ){ report( l + r - now ); return 0; }
		l = ( now - v + L - 1 ) % L + 1,r = ( now + v + L - 1 ) % L + 1;
	}
	if( l == r ) report( l );
	else{
		for( int i = 1 ; i <= L ; i ++ ){
			if( i != l && i != r && dis( i , l ) != dis( i , r ) ){
				auto [u,v] = ask( i );
				int ll = ( i - v + L - 1 ) % L + 1,rr = ( i + v + L - 1 ) % L + 1;
				if( ll == l || rr == l ){ report( l ); return 0; }
				report( r ); return 0;
			}
		}
	}
	return 0;
}