#include<bits/stdc++.h>
using namespace std;

#define MAXN 205

int n,m,c1[3],c2[3],cnt1,cnt2;
char s[MAXN],t[MAXN],S[MAXN],T[MAXN];

inline void clear(){
	memset( c1 , 0 , sizeof( c1 ) );
	memset( c2 , 0 , sizeof( c2 ) );
	cnt1 = cnt2 = 0;
}

inline void solve(){
	scanf("%s%s",s + 1,t + 1);
	n = strlen( s + 1 ),m = strlen( t + 1 );
	for( int i = 1 ; i <= n ; i ++ ) c1[s[i] - 'A'] ^= 1;
	for( int i = 1 ; i <= m ; i ++ ) c2[t[i] - 'A'] ^= 1;
	for( int i = 0 ; i < 3 ; i ++ ){
		if( c1[i] != c2[i] ){
			puts("NO");
			clear();
			return;
		}
	}
	for( int i = 1 ; i <= n ; i ++ ){
		if( s[i] == 'B' ) continue;
		if( S[cnt1] == s[i] ) cnt1 --;
		else S[++cnt1] = s[i];
	}
	for( int i = 1 ; i <= m ; i ++ ){
		if( t[i] == 'B' ) continue;
		if( T[cnt2] == t[i] ) cnt2 --;
		else T[++cnt2] = t[i];
	}
	if( cnt1 != cnt2 ){ puts("NO"); clear(); return; }
	else{
		for( int i = 1 ; i <= cnt1 ; i ++ ) if( S[i] != T[i] ){ puts("NO"); clear(); return; }
	}
	puts("YES"); clear();
}

signed main(){
	int t; scanf("%d",&t);
	while( t -- ) solve();
	return 0;
}