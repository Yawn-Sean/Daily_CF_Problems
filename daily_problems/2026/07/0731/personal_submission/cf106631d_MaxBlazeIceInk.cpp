#include<bits/stdc++.h>
using namespace std;

#define MAXN 300005
char s[MAXN];

int n;

inline void solve(){
	scanf("%d%s",&n,s + 1);
	if( n <= 2 ){ puts("Bob"); return; }
	else{
		int c = 0;
		for( int i = 1 ; i < n ; i ++ ) c += s[i] == s[1];
		if( c == n - 1 ){ puts("Bob");}
		else puts("Alice");
	}	
}

signed main(){
	int t; scanf("%d",&t);
	while( t -- ) solve();
	return 0;
}