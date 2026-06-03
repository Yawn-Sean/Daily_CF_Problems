#include<bits/stdc++.h>
using namespace std;

int n,d,pos[27];
char s[27];

inline void solve(){
	scanf("%s",s + 1);
	for( int i = 1 ; i <= 26 ; i ++ ) pos[s[i] - 'a' + 1] = i;
	if( pos[3] < max( { pos[5] , pos[16] , pos[26] } ) ){
		puts("NO");
	}
	else if( pos[16] < pos[26] ){
		puts("NO");
	}
	else puts("YES");
}

signed main(){
	int t; scanf("%d",&t);
	while( t -- ) solve();
	return 0;
}