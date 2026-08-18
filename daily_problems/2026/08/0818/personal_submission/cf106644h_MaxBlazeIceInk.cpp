#include<bits/stdc++.h>
using namespace std;

#define MAXN 200005

int n;
char s[MAXN];

inline void solve(){
	scanf("%d%s",&n,s + 1);
	if( n % 2 ){
		if( s[n / 2 + 1] == 'B' && ( s[n / 2] == 'B' || s[n / 2 + 2] == 'B' ) ) puts("Doludu");
		else puts("DoIudu");
	}
	else{
		if( s[n / 2] == 'B' || s[n / 2 + 1] == 'B' ) puts("Doludu");
		else puts("DoIudu");
	}
}

signed main(){
	int t; scanf("%d",&t);
	while( t -- ) solve();
	return 0;
}