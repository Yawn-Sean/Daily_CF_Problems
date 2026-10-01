#include<bits/stdc++.h>
using namespace std;

#define MAXN 1000005
#define int long long
#define double long double

int n;
double X[MAXN],Y[MAXN],SX[MAXN],SY[MAXN],XX[MAXN],YY[MAXN],XY[MAXN];

//KK k^2 + KB kb + BB b^2 + K k + B b + C
//(2KK)*k + KB*b + K = 0
//(2BB)*b + KB*k + B = 0
//(2KK * KB) * k + KB*KB*b + K*KB = 0
//(2KK * KB) * k + 4*KK*BB*b + 2*B*KK = 0
inline pair<double,double> Solve( double KK , double KB , double BB , double K , double B ){
	return make_pair( -( 2 * K * BB - B * KB ) / ( 4 * KK * BB - KB * KB ) ,  -( 2 * B * KK - K * KB ) / ( 4 * KK * BB - KB * KB ) );
}

signed main(){
	scanf("%lld",&n);
	for( int i = 1 ; i <= n ; i ++ ){
		scanf("%Lf%Lf",&X[i],&Y[i]);
		XX[i] = XX[i - 1] + X[i] * X[i];
		YY[i] = YY[i - 1] + Y[i] * Y[i];
		SX[i] = SX[i - 1] + X[i];
		SY[i] = SY[i - 1] + Y[i];
		XY[i] = XY[i - 1] + X[i] * Y[i];
	}
	int m; scanf("%lld",&m);
	for( int i = 1 ; i <= m ; i ++ ){
		int l,r; double lam,xx; scanf("%lld%lld%Lf%Lf",&l,&r,&lam,&xx);
		pair<double,double> p = Solve( XX[r] - XX[l - 1] + lam , 2 * ( SX[r] - SX[l - 1] ) , r - l + 1 + lam , -2 * ( XY[r] - XY[l - 1] ) , -2 * ( SY[r] - SY[l - 1] ) );
		printf("%.15Lf\n",p.first * xx + p.second);
	}
	return 0;
}