#include<bits/stdc++.h>
using namespace std;

#define int long long
#define MAXN 200005

int n,a[MAXN],b[MAXN];

signed main(){
	scanf("%lld",&n);
	int ans = 0;
	for( int i = 1 ; i <= 2 * n ; i ++ ) scanf("%lld",&a[i]),ans += a[i];
	for( int i = 1 ; i <= 2 * n ; i ++ ) scanf("%lld",&b[i]),b[i] = -b[i];
	priority_queue< int , vector<int> , greater<int> > Q;
	for( int i = 1 ; i <= 2 * n ; i ++ ){
		int d = b[i] - a[i];
		if( i % 2 == 0 ) Q.push( d ),ans += d;
		else{
			if( Q.size() && d > Q.top() ){
				ans -= Q.top();
				Q.pop();
				ans += d;
				Q.push( d );
			}
		}
	}
	printf("%lld\n",ans);
	return 0;
}