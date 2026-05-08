#include<bits/stdc++.h>
using namespace std;

#define MAXN 100005

int n;

char s[MAXN];

inline void solve(){
	scanf("%d%s",&n,s + 1);
	int c = 0;
	if( strlen( s + 1 ) == 3 && s[1] != s[2] && s[2] != s[3] && s[1] != s[3] ){ puts("NO"); return; }
	for( int i = 1 ; i < n ; i ++ ){
		if( s[i] != s[n] ){ c = 1; break; }
	}
	if( !c ) puts("NO");
	else puts("YES");
}

signed main(){
	int t; scanf("%d",&t);
	while( t -- ) solve();
	return 0;
}