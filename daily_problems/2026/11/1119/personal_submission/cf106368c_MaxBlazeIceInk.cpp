#include<bits/stdc++.h>
using namespace std;

#define int long long
#define MAXN 300005

int n,D,t,d[MAXN],b[MAXN],Ans[MAXN],inn[MAXN];

//我草，答案怎么他妈是若干最大值之和
//倒着做就行了

signed main(){
	scanf("%lld%lld%lld",&n,&D,&t);
	for( int i = 1 ; i <= n ; i ++ ) scanf("%lld%lld",&d[i],&b[i]);
	int now = 0,siz = 0,ans = 0;
	priority_queue< pair<int,int> , vector< pair<int,int> > , greater< pair<int,int> > > Q;
	for( int i = n ; i >= 1 ; i -- ){
		siz += ( i == n ? D + 1 : d[i + 1] ) - d[i];
		if( Q.size() < siz ) Q.push( make_pair( b[i] , i ) ),inn[i] = 1,ans += b[i];
		else{
			auto [v,id] = Q.top();
			if( b[i] > v ) Q.pop(),inn[id] = 0,inn[i] = 1,Q.push( make_pair( b[i] , i ) ),ans -= v,ans += b[i];
		}
	}
	printf("%lld\n",ans);
	if( t == 1 ) return 0;
	now = D + 1;
	for( int i = n ; i >= 1 ; i -- ){
		if( now == D + 1 && !inn[i] ) Ans[i] = D;
		else
		if( inn[i] ) now --,Ans[i] = now;
		else Ans[i] = now;
	}
	for( int i = 1 ; i <= n ; i ++ ) printf("%lld ",Ans[i]);
	return 0;
}