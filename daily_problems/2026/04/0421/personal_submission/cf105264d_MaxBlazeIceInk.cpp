#include<bits/stdc++.h>
using namespace std;

#define int long long
#define MAXN 1000005

int n,cnt[10],a[MAXN];
char s[MAXN];

inline void solve(){
	scanf("%lld%s",&n,s + 1);
	if( n == 1 ){ puts("0 0"); return; }
	for( int i = 1 ; i <= n ; i ++ ) a[i] = s[i] - '0';
	memset( cnt , 0 , sizeof( cnt ) );
	int maxx = 0;
	for( int i = 1 ; i <= n ; i ++ ) maxx = max( maxx , a[i] ),cnt[a[i]] ++;
	if( cnt[maxx] >= 2 ){
		int ans1 = ( a[1] != maxx ) + ( a[n] != maxx );
		int ans2 = 11 * maxx;
		cnt[maxx] -= 2;
		for( int i = 0 ; i < 10 ; i ++ ) ans2 += cnt[i] * i * 11;
		printf("%lld %lld\n",ans1,ans2);
	}
	else{
		//最大值恰好有一个，考察任意次大值
		int v = 0;
		for( int i = 9 ; i >= 0 ; i -- ) if( cnt[i] && i != maxx ){ v = i; break; }
		int ans1 = ( a[1] != v ) + ( a[n] != maxx );
		if( a[1] == maxx && a[n] == v ) ans1 = 1;
		cnt[maxx] --,cnt[v] --;
		int ans2 = v * 10 + maxx;
		for( int i = 0 ; i < 10 ; i ++ ) ans2 += cnt[i] * i * 11;
		printf("%lld %lld\n",ans1,ans2);
	}
}

signed main(){
	int t; scanf("%lld",&t);
	while( t -- ) solve();
	return 0;
}