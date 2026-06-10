#include<bits/stdc++.h>
using namespace std;

#define MAXN 2005
#define int long long
int n,m,a[MAXN],b[MAXN];

map<int,int> M;
vector<int> A;

signed main(){
	scanf("%lld%lld",&n,&m);
	for( int i = 1 ; i <= n ; i ++ ) scanf("%lld",&a[i]);
	for( int i = 1 ; i <= m ; i ++ ) scanf("%lld",&b[i]),M[b[i]] = i;
	if( n > m ){ puts("No"); return 0; }
	sort( a + 1 , a + n + 1 );
	sort( b + 1 , b + m + 1 );
	vector<int> ans;
	for( int i = 1 ; i <= m ; i ++ ){
		set<int> S;
		int now = b[i],f = 1;
		for( int j = 1 ; j <= n ; j ++ ){
			S.insert( 2 * a[j] - now );
			if( j < n ){
				now += ( a[j + 1] - a[j] ) * 2;
				if( !M.count( now ) ){ f = 0; break; }
			}
		}
		if( (int)S.size() == 1 && f ) ans.emplace_back( 2 * a[1] - b[i] );
	}
	for( int ele : ans )
		for( int i = 1 ; i <= n ; i ++ ) M[2 * a[i] - ele] &= 0;
	for( int i = 1 ; i <= m ; i ++ ) if( M[b[i]] ){ puts("No"); return 0; }
	sort( ans.begin() , ans.end() );
	puts("Yes");
	printf("%lld\n",(int)ans.size());
	for( int ele : ans ) printf("%lld ",ele);
	return 0;
}