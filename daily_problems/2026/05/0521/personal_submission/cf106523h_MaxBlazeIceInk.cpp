#include<bits/stdc++.h>
using namespace std;

#define MAXN 100005

int Q,ptot,notp[MAXN],prime[MAXN],minp[MAXN],f[MAXN];

inline void pre(){
	notp[1] = 1;
	for( int i = 2 ; i < MAXN ; i ++ ){
		if( !notp[i] ) prime[++ptot] = i,minp[i] = i;
		for( int j = 1 ; j <= ptot && i * prime[j] < MAXN ; j ++ ){
			notp[i * prime[j]] = 1;
			minp[i * prime[j]] = prime[j];
			if( i % prime[j] == 0 ) break;
		}
	}
}

set<int> S;

signed main(){
	pre();
	scanf("%d",&Q);
	for( int i = 1 ; i <= Q ; i ++ ){
		int opt; scanf("%d",&opt);
		if( opt == 1 ){
			int x; scanf("%d",&x);
			while( x > 1 ){
				int p = minp[x],c = 0;
				while( x % p == 0 ) x /= p,c ++;
				f[p] += c;
				if( f[p] == c && S.find( p ) == S.end() ) S.insert( p );
			}
		}
		else if( opt == 2 ){
			int x; scanf("%d",&x);
			set<int> R;
			for( int ele : S ){
				f[ele] = min( 20 , f[ele] * x );
				if( f[ele] >= 20 ) R.insert( ele );
			}
			for( int ele : R ) S.erase( ele );
		}
		else{
			int x; scanf("%d",&x);
			bool flag = 1;
			while( x > 1 ){
				int p = minp[x],c = 0;
				while( x % p == 0 ) x /= p,c ++;
				if( c > f[p] ) flag = 0;
			}
			if( flag ) puts("Yes");
			else puts("No");
		}
		
	}
	return 0;
}