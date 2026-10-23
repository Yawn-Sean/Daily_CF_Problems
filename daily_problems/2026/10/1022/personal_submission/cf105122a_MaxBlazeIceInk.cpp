#include<bits/stdc++.h>
using namespace std;

#define int long long

int n,k;
mt19937_64 rnd(time(0));

signed main(){
	scanf("%lld%lld",&k,&n);
	int X = k * ( k + 1 ) / 2;
	for( int i = 1 ; i <= n ; i ++ ){
		int u = rnd() % X;
		int l = 1,r = k,ans = k + 1;
		while( l <= r ){
			int mid = ( l + r ) >> 1;
			if( k * ( k + 1 ) / 2 - mid * ( mid - 1 ) / 2 <= u ) ans = mid,r = mid - 1;
			else l = mid + 1; 
		}
		printf("%lld %lld\n",k - ans + 2,u - k * ( k + 1 ) / 2 + ans * ( ans - 1 ) / 2 + k - ans + 2);
	}
	return 0;
}