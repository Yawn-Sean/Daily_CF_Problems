#include<bits/stdc++.h>
using namespace std;

#define MAXN 1000005

int n;
char s[MAXN];

signed main(){
	scanf("%s",s + 1); n = strlen( s + 1 );
	int c1 = 0;
	long long SS = 0;
	for( int i = 1 ; i <= n ; i ++ ) c1 += s[i] == '1',SS += i * ( s[i] == '1' );
	long long S = 0;
	for( int i = n ; i >= n - c1 + 1 ; i -- ) S += i;
	// cerr << S << " " << SS << "\n";
	puts( ( S - SS ) % 3 ? "Alice" : "Bob" );
	return 0;
}