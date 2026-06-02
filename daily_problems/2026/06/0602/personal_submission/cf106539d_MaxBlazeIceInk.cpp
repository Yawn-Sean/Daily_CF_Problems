#include<bits/stdc++.h>
using namespace std;

int n,m;

inline void solve(){
	scanf("%d%d",&n,&m);
	printf("%d\n",min( n , m / 2 + 1 ));
}

signed main(){
	int t; scanf("%d",&t);
	while( t -- ) solve();
	return 0;
}