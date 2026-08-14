#include<bits/stdc++.h>
using namespace std;

#define int long long

int a,b;

signed main(){
	scanf("%lld%lld",&a,&b);
	vector<int> A;
	int tmp = b; while( tmp ) A.emplace_back( tmp % ( a + 1 ) ),tmp /= ( a + 1 );
	printf("%lld\n",(int)A.size());
	for( int ele : A ) printf("%lld ",ele);
	return 0;
}