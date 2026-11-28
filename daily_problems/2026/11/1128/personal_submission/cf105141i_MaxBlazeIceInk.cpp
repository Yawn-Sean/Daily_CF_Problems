#include<bits/stdc++.h>
using namespace std;

#define int long long
#define MAXN 100005

int n,s[MAXN],w[MAXN],d[MAXN],sum[MAXN],cnt[MAXN],Max[MAXN];

const int V = 100000;

signed main(){
	scanf("%lld%lld%lld",&n,&s[0],&w[0]);
	for( int i = 1 ; i <= n ; i ++ ) scanf("%lld%lld%lld",&s[i],&w[i],&d[i]),sum[d[i]] += d[i],cnt[d[i]] ++;
	for( int i = 1 ; i <= V ; i ++ ) sum[i] += sum[i - 1],cnt[i] += cnt[i - 1];
	int maxx = 0;
	for( int i = 1 ; i <= n ; i ++ ){
		int r = sum[s[i]] + ( ( s[i] < d[i] ) ? d[i] : 0 );
		int rc = cnt[s[i]] + ( ( s[i] < d[i] ) ? 1 : 0 );
		if( r > w[i] ){
			continue;
		}
		else{
			int d = w[i] - r + 1;
			//再来一个 d 就会飞走
			if( d > s[i] ){
				//一定飞不走
				maxx = max( maxx , rc );
			}
			else{
				Max[d] = max( Max[d] , rc );
			}
		}
	}
	for( int i = V ; i >= 1 ; i -- ) Max[i] = max( Max[i] , Max[i + 1] );
	int my = sum[s[0]],sol = cnt[s[0]];
	//枚举我提出的问题难度
	for( int i = 1 ; i <= V ; i ++ ){
		int ww = my + i;
		if( ww > w[0] ) continue;
		if( sol + 1 <= maxx ) continue;
		if( Max[i + 1] >= sol + 1 ) continue;
		puts("Yes");
		return 0;
	}
	puts("No");
	return 0;
}