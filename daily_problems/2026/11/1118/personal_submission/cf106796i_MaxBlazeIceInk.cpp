#include<bits/stdc++.h>
using namespace std;

#define MAXN 300005
#define INF (int)1e9

//不难发现对 5 取模之后答案不变，3 4 可以合并
int n,p[MAXN],cnt[5];

inline int chkmax( int &x , int k ){ x = max( x , k ); }

signed main(){
	scanf("%d",&n);
	for( int i = 1 ; i <= n ; i ++ ){
		int x; scanf("%d",&x);
		cnt[x % 5] ++;
	}
	// cerr << cnt[1] << " " << cnt[2] << " " << cnt[3] << " " << cnt[4] << "\n";
	int ans = cnt[1] + 2 * cnt[2];
	int t = min( cnt[3] , cnt[4] );
	ans += 2 * t;
	cnt[3] -= t,cnt[4] -= t;
	if( cnt[3] ){
		ans += cnt[3] / 2;
		ans -= cnt[3] % 2 * 2;
	}
	else{
		ans += cnt[4] / 3 * 2;
		ans -= cnt[4] % 3;
	}
	printf("%d\n",ans);
	return 0;
}