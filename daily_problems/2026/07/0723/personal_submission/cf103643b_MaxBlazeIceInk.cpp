#include<bits/stdc++.h>
using namespace std;

inline void solve(){
	int a,b; scanf("%d%d",&a,&b);
	map<double,int> M;
	M[a + b] = 1,M[a - b] = 1,M[b - a] = 1,M[a * b] = 1,M[1.0 * a / b] = 1,M[1.0 * b / a] = 1;
	printf("%d\n",(int)M.size());
}

signed main(){
	int t; scanf("%d",&t);
	while( t -- ) solve();
	return 0;
}