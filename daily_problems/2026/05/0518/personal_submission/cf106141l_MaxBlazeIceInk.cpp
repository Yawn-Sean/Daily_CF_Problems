#include<bits/stdc++.h>
using namespace std;

#define int long long
#define double long double
#define MAXN 10005

int n,a[MAXN],p3[MAXN],n3[MAXN],ans[MAXN];

signed main(){
	scanf("%lld",&n);
	for( int i = 1 ; i <= n ; i ++ ) scanf("%lld",&a[i]);
	vector< pair<int,int> > P,N;
	for( int i = 1 ; i <= n ; i ++ ) if( a[i] >= 0 ) P.emplace_back( make_pair( a[i] , i ) );
	for( int i = 1 ; i <= n ; i ++ ) if( a[i] < 0 ) N.emplace_back( make_pair( a[i] , i ) );
	sort( P.begin() , P.end() );
	reverse( P.begin() , P.end() );
	sort( N.begin() , N.end() );
	int siz1 = (int)P.size(),siz2 = (int)N.size();
	int S = 0;
	for( int i = 0 ; i < siz1 ; i ++ ) S += P[i].first;
	p3[0] = S;
	for( int i = 0 ; i < siz1 ; i ++ ) S += 2 * P[i].first,p3[i + 1] = S;
	S = 0;
	for( int i = 0 ; i < siz2 ; i ++ ) S -= N[i].first;
	n3[0] = S;
	for( int i = 0 ; i < siz2 ; i ++ ) S -= 2 * N[i].first,n3[i + 1] = S;
	double res = 0; int id1 = 0,id2 = 0;
	for( int i = 0 ; i <= siz1 ; i ++ ){
		for( int j = 0 ; j <= siz2 ; j ++ ){
			int P = p3[i] + n3[j];
			int Q = 9 * ( i + j ) + ( siz1 - i ) + ( siz2 - j );
			// cerr << P << " " << Q << "\n";
			double S = 1.0 * P / sqrtl( 1.0 * Q );
			if( S > res ) res = S,id1 = i,id2 = j;
		}
	}
	// cerr << id1 << " " << id2 << "\n";
	for( pair<int,int> ele : P ) ans[ele.second] = 1;
	for( int i = 0 ; i < id1 ; i ++ ) ans[P[i].second] = 3;
	for( pair<int,int> ele : N ) ans[ele.second] = -1;
	for( int i = 0 ; i < id2 ; i ++ ) ans[N[i].second] = -3;
	for( int i = 1 ; i <= n ; i ++ ) printf("%lld ",ans[i]); puts("");
	return 0;
}