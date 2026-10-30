#include<bits/stdc++.h>
using namespace std;

//mod 3 trick

#define MAXN 200005

int n;
char s[MAXN];

signed main(){
	scanf("%d%s",&n,s + 1);
	int md = 0,c = 0;
	for( int i = 1 ; i <= n ; i ++ ){
		if( s[i] == 'G' ) md = ( md + 1 ) % 3;
		else md = ( md + 2 ) % 3;
		if( i < n ) c += s[i] != s[i + 1];
	}
	if( c == n - 1 ) printf("%d\n",n);
	else if( md ) puts("1");
	else puts("2");
	return 0;
}