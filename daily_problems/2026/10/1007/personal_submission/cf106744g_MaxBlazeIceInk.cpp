#include<bits/stdc++.h>
using namespace std;

#define int long long
#define MAXN 200005

int n,k;
vector<int> Ans;

inline bool check( int x ){
	Ans.clear();
	int tmp = n;
	for( int i = k ; i >= 1 ; i -- ){
		int use = min( x , tmp / i );
		tmp -= use * i;
		Ans.emplace_back( use );
	}
	return tmp == 0;
}

signed main(){
	scanf("%lld%lld",&n,&k);
	int l = 1,r = (int)1e18,ans = -1;
	while( l <= r ){
		int mid = ( l + r ) >> 1;
		if( check( mid ) ) ans = mid,r = mid - 1;
		else l = mid + 1;
	}
	check( ans );
	reverse( Ans.begin() , Ans.end() );
	for( int ele : Ans ) printf("%lld ",ele);
	return 0;
}