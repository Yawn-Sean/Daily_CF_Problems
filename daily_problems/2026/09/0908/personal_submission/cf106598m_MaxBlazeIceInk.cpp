#include<bits/stdc++.h>
using namespace std;

#define MAXN 2000005

string s[2];
int p,q;

signed main(){
	cin >> s[0] >> s[1] >> p >> q;
	if( !p || !q ) puts("=");
	else{
		if( s[0] + s[1] < s[1] + s[0] ) puts("<");
		else if( s[0] + s[1] > s[1] + s[0] ) puts(">");
		else puts("=");
	}
	return 0;
}