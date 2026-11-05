#include<bits/stdc++.h>
using namespace std;

#define int long long
#define MAXN 200005

int n,a[MAXN];

signed main(){
	scanf("%lld",&n);
	int S = 0;
	map<int,int> M;
	for( int i = 1 ; i <= n ; i ++ ) scanf("%lld",&a[i]),S += a[i],M[a[i]] ++;
	sort( a + 1 , a + n + 1 );
	//只要存在一个子集可行即可
	int s = 0;
	for( int i = 1 ; i <= n ; i ++ ){
		if( a[i] <= s ){ puts("possible"); return 0; }
		s += a[i];
	}
	puts("impossible");
	return 0;
}