#include<bits/stdc++.h>
using namespace std;

#define int long long
#define MAXN 150005

int n,k,c[MAXN];
pair<int,int> p[MAXN];
vector<int> T[MAXN];

priority_queue< int , vector<int> , greater<int> > B;
int ans = 0;

signed main(){
	scanf("%lld%lld",&n,&k);
	for( int i = 1 ; i <= n ; i ++ ) scanf("%lld",&c[i]);
	sort( c + 1 , c + n + 1 );
	for( int i = 1 ; i <= k ; i ++ ) scanf("%lld",&p[i].first);
	for( int i = 1 ; i <= k ; i ++ ) scanf("%lld",&p[i].second);
	sort( p + 1 , p + k + 1 );
	
	int pnt = 0;
	for( int i = 1 ; i <= n ; i ++ )
		while( pnt + 1 <= k && c[i] >= p[pnt + 1].first ) pnt ++,T[i].emplace_back( p[pnt].second );
	for( int i = n ; i >= 1 ; i -- ){
		for( int v : T[i] ){
			// cerr << i << "add" << v << "\n";
			if( (int)B.size() < n - i + 1 ){
				ans += v;
				B.push( v );
			}
			else{
				if( B.top() < v ){
					ans -= B.top();
					B.pop();
					ans += v;
					B.push( v );
				}
			}
		}
	}
	printf("%lld\n",ans);
	return 0;
}