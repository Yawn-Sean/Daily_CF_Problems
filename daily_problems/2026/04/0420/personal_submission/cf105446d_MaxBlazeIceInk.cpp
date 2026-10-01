#include<bits/stdc++.h>
#include<cassert>
using namespace std;

#define double long double

double p,r,y,A,B,C,D;

inline bool check( double n , double ans ){
	double e = n - D,s = B + D - n,K = C + B + D - n;
	if( max( { fabs( e ) , fabs( s ) , fabs( K ) , fabs( n ) } ) <= ans + ( 1e-7 ) ){
		printf("%.12Lf %.12Lf %.12Lf %.12Lf\n",n,C + B + D - n,n - D,B + D - n);
		return 1;
	}
	return 0;
}

inline void solve(){
	scanf("%Lf%Lf%Lf",&p,&r,&y);
	double ne = ( p + r + y ) / 2,sw = ( y - p - r ) / 2;
	A = ne,B = sw,C = p,D = r;
	double ll = 0,rr = 10.0,ans = -1;
	for( int i = 0 ; i <= 100 ; i ++ ){
		double mid = ( ll + rr ) / 2;
		double L = -mid,R = mid;
		//-mid <= x - D <= mid
		L = max( L , D - mid );
		R = min( R , mid + D );
		//-mid <= B - x + D <= mid
		L = max( L , B + D - mid );
		R = min( R , B + D + mid );
		//-mid <= C + B + D - x <= mid
		L = max( L , C + B + D - mid );
		R = min( R , C + B + D + mid );
		if( L <= R + (1e-9) ) ans = mid,rr = mid;
		else ll = mid;
	}
	if( !check( ans , ans ) ){
		if( !check( ans + D , ans ) ){
			if( !check( B + D - ans , ans ) ){
				if( !check( B + C + D - ans , ans ) ){
					if( !check( -ans , ans ) ){
		if( !check( -ans + D , ans ) ){
			if( !check( B + D + ans , ans ) ){
				if( !check( B + C + D + ans , ans ) ){
					assert( 0 );
				}
			}
		}
	}
				}
			}
		}
	}
	// if( max( { ans , ans - D , B + D - ans , C + B + D - ans } ) <= ans ){
		// printf("%.12Lf %.12Lf %.12Lf %.12Lf\n",ans,C + B + D - ans,ans - D,B + D - ans);
	// }
}

signed main(){
	int t; scanf("%d",&t);
	while( t -- ) solve();
	return 0;
}