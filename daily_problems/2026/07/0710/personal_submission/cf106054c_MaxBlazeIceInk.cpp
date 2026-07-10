#include<bits/stdc++.h>
using namespace std;

#define int long long
#define MAXN 400005
int n,p[MAXN];

signed main(){
	scanf("%lld",&n);
	for( int i = 1 ; i <= n ; i ++ ) scanf("%lld",&p[i]);
	int ans = n;
	map<int,int> M;
	for( int i = n ; i >= 1 ; i -- ){
		ans += M[p[i] + i] * 2,ans += M[p[i] + i + n] * 2;
		M[p[i] + i] ++;
	}
	printf("%lld\n",ans);
	return 0;
}