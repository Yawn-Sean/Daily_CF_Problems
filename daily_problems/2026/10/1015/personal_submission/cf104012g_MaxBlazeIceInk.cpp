#include<bits/stdc++.h>
using namespace std;

#define MAXN 200005

int n,q,s[MAXN];

int getv( int x , int y ){
	if( !y ) return x;
	return getv( y , x / y );
}

vector<int> ans[MAXN];

signed main(){
	scanf("%d%d",&n,&q);
	int cnt = 0;
	for( int y = 2 ; y <= n ; y ++ ){
		for( int l = y ; l <= n ; l += y ){
			int r = min( l + y - 1 , n );
			int g = getv( l , y );
			int k = l / g * g;
			while( k < l ) k += g;
			while( k <= r ){
				if( gcd( k , y ) == g ) ans[k].emplace_back( y ),cnt ++;
				k += g;
			}
		}
	}
	for( int i = 1 ; i <= n ; i ++ ) s[i] = s[i - 1] + ans[i].size();
	for( int i = 1 ; i <= q ; i ++ ){
		int x; scanf("%d",&x); if( x > cnt ){ puts("-1 -1"); continue; }
		int l = 2,r = n,Ans = -1;
		while( l <= r ){
			int mid = ( l + r ) >> 1;
			if( x <= s[mid] ) Ans = mid,r = mid - 1;
			else l = mid + 1;
		}
		printf("%d %d\n",Ans,ans[Ans][x - s[Ans - 1] - 1]);
	}
	return 0;
}