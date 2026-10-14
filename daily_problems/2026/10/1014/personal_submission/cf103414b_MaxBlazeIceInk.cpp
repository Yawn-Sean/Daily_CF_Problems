#include<bits/stdc++.h>
using namespace std;

#define int long long
#define MAXN 10005

int n,ans[MAXN];
map< pair<int,int> , int > M;

inline int In(){
	int x; scanf("%lld",&x);
	return x;
}

inline void Ask( int l , int r ){
	printf("? %lld %lld\n",l,r);
	fflush( stdout );
}

signed main(){
	scanf("%lld",&n);
	for( int r = 1 ; r <= n ; r ++ ){
		for( int l = 1 ; l <= r ; l ++ ){
			if( M.count( make_pair( l , r ) ) ) continue;
			Ask( l , r );
			int s = In(),bl = In(),br = In();
			for( int k = l ; k < r ; k ++ ) s -= ans[k];
			ans[r] = s;
			M[make_pair( bl , br )] = 1;
			break;	
		}
	}
	printf("!\n");
	for( int i = 1 ; i <= n ; i ++ ) printf("%lld ",ans[i]); puts("");
	fflush( stdout );
	return 0;
}