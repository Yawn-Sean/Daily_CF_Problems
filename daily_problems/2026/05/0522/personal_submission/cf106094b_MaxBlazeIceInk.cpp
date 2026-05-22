#include<bits/stdc++.h>
using namespace std;

#define int long long
#define MAXN 200005

int n,T,ans[MAXN];
pair<int,int> d[MAXN];

inline void solve(){
	scanf("%lld%lld",&n,&T);
	int Ans = 0;
	for( int i = 1 ; i <= n ; i ++ ) scanf("%lld",&d[i].first),d[i].second = i,Ans += 50,T -= d[i].first / 2,ans[i] = 2;
	sort( d + 1 , d + n + 1 );
	int P = 0,res = 0,lst = 0,Fans = 0;
	for( int i = 1 ; i <= n ; i ++ ){
		if( P + d[i].first / 2 <= T ){
			P += d[i].first / 2,res += 50;
			lst = i;
		}
		else{
			while( lst && P + d[i].first / 6 > T ){
				res -= 25,ans[d[lst].second] = 3,P -= d[lst].first / 2 - d[lst].first / 6,lst --;
			}
			if( P + d[i].first / 6 <= T ){
				P += d[i].first / 6,res += 25;
			}
		}
		// else break;
		if( P <= T ) Fans = max( Fans , Ans + res );
	}	
	printf("%lld\n",Fans);
	
	P = 0,res = 0,lst = 0;
	for( int i = 1 ; i <= n ; i ++ ){
		if( P + d[i].first / 2 <= T ){
			P += d[i].first / 2,res += 50,ans[d[i].second] = 1;
			lst = i;
		}
		else{
			while( lst && P + d[i].first / 6 > T ){
				res -= 25,ans[d[lst].second] = 3,P -= d[lst].first / 2 - d[lst].first / 6,lst --;
			}
			if( P + d[i].first / 6 <= T ){
				P += d[i].first / 6,res += 25,ans[d[i].second] = 3;
			}
		}
		// else break;
		if( Ans + res == Fans ) break;
	}	
	
	for( int i = 1 ; i <= n ; i ++ ){
		if( ans[i] == 3 ) printf("1.5 ");
		else printf("%lld ",ans[i]);
	}
	puts("");
}

signed main(){
	int t; scanf("%lld",&t);
	while( t -- ) solve();
	return 0;
}