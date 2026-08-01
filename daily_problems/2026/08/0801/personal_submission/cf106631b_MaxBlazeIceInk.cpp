#include<bits/stdc++.h>
using namespace std;

#define MAXN 300005
#define INF (int)1e9

int n;
char s[MAXN];

inline void solve(){
	scanf("%d%s",&n,s + 1);
	if( s[1] == '0' ){ puts("-1"); return; }
	if( n == 1 ){ printf("a\n"); return; }
	if( n == 2 ){ if( s[2] == '1' ) printf("aa\n"); else printf("ab\n"); return; }
	for( int i = 2 ; i < n ; i += 2 ){
		if( s[i] == '1' ){
			int c = 0;
			for( int j = 1 ; j <= n ; j ++ ) c += s[j] == '1';
			if( c < n ){ puts("-1"); return; }
			else{
				for( int i = 1 ; i <= n ; i ++ ) printf("a"); puts("");
				return;
			}
		}
	}
	//所有 <n 的偶数都不是
	if( n % 2 == 0 && s[n] == '1' ){
		//abba
		//abaaba
		int c = 0;
		for( int i = 1 ; i <= n ; i += 2 ) c += s[i] == '1';
		if( c != 1 ){ puts("-1"); return; }
		for( int i = 1 ; i <= n ; i ++ ) printf("%c",( i == n / 2 || i == n / 2 + 1 ) ? 'b' : 'a'); puts("");
		return;
	}
	for( int i = 3 ; i < n ; i += 2 ){
		if( s[i] == '1' ){
			int c = 0;
			//有奇数，所有的奇数都得是
			for( int i = 1 ; i <= n ; i += 2 ) c += s[i] == '1';
			if( c != ( n + 1 ) / 2 ){
				puts("-1");
				return;
			}
			//如果 n 是偶数且也是
			if( s[n] == '1' && n % 2 == 0 ){
				puts("-1");
				return;
			}
			for( int i = 1 ; i <= n ; i ++ ){
				printf("%c",i % 2 ? 'a' : 'b');
			}
			puts("");
			return;
		}
	}
	if( n % 2 && s[n] == '1' ){
		for( int i = 1 ; i <= n ; i ++ ) printf("%c",( i == n / 2 + 1 ) ? 'b' : 'a'); puts("");
		return;
	}
	//所有奇数都不是
	// if( n == 3 ){ printf("abb"); return; }
	for( int i = 1 ; i <= n ; i ++ ){
		printf("%c",i == n ? 'b' : 'a');
	}
	puts("");
	return;
}

signed main(){
	int t; scanf("%d",&t);
	while( t -- ) solve();
	return 0;
}