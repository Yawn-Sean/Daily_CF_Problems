#include<bits/stdc++.h>
using namespace std;

#define int long long
#define double long double
#define MAXN 100005

int n,x,y,X[MAXN],Y[MAXN],R[MAXN],cnt;
pair<double,double> dis[MAXN];

signed main(){
	scanf("%lld%lld%lld",&n,&x,&y);
	double K = 0;
	for( int i = 1 ; i <= n ; i ++ ){
		scanf("%lld%lld%lld",&X[i],&Y[i],&R[i]);
		double D = sqrtl( ( X[i] - x ) * ( X[i] - x ) + ( Y[i] - y ) * ( Y[i] - y ) );
		if( D <= R[i] ) K += R[i];
		else dis[++cnt] = make_pair( D - R[i] , R[i] );
	}
	sort( dis + 1 , dis + cnt + 1 );
	double Now = K,Ans = 0;
	for( int i = 1 ; i <= cnt ; i ++ ){
		if( Now >= dis[i].first ) Now += dis[i].second;
		else Ans = max( Ans , dis[i].first - Now ),Now += dis[i].second; 
	}
	printf("%.12Lf\n",Ans);
	return 0;
}