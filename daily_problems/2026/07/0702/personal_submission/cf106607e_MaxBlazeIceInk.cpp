#include<bits/stdc++.h>
using namespace std;

#define int long long
#define MAXN 300005

int n,Y[MAXN],ycnt,tr[MAXN];
pair<int,int> P[MAXN];

inline void add( int x , int k ){ for( ; x <= ycnt ; x += x & -x ) tr[x] += k; }
inline int sum( int x ){ int ret = 0; for( ; x ; x -= x & -x ) ret += tr[x]; return ret; }

inline void solve(){
	scanf("%lld",&n);
	int c0 = 0,c1 = 0,c2 = 0;
	for( int i = 1 ; i <= n ; i ++ ){
		scanf("%lld%lld",&P[i].first,&P[i].second);
		if( P[i].first < P[i].second ) c0 ++;
		else if( P[i].first > P[i].second ) c2 ++;
		else c1 ++;
	}
	printf("%lld\n",c0 * c1 + c1 * c2 + c1 * ( c1 - 1 ) / 2 + c0 * c2); 
}

signed main(){
	int t; scanf("%lld",&t);
	while( t -- ) solve();
	return 0;
}