#include<bits/stdc++.h>
using namespace std;

signed main(){
	int t;
	cin >> t;
	while( t -- ){
		int n,m;
		cin >> n >> m;
		vector< pair<int,int> > lines( n );
		for(  auto &[k,b] : lines ) cin >> k >> b;
		
		bool flg = 1,sing = 0;
		int x;
		long long y;
		
		for( int i = 1 ; i < n ; i ++ ){
			auto [k1,b1] = lines[0];
			auto [k2,b2] = lines[i];
			if( k1 == k2 ){
				if( b1 != b2 ) flg = 0;
			}
			else{
				sing = 1;
				x = -( b2 - b1 ) / ( k2 - k1 );
				y = 1ll * k1 * x + b1;
			}
		}
		
		if( sing ){
			for( int i = 0 ; i < n ; i ++ ){
				auto [k,b] = lines[i];
				if( y != 1ll * k * x + b ){
					flg = 0;
				}
			}
		}
		
		if( m ){
			while( m -- ){
				int x0;
				cin >> x0;
				if( sing && x0 != x ){
					flg = 0;
				}
			}
		}
		else flg = 1;
		
		cout << ( flg ? "YES" : "NO" ) << "\n";
	}
	return 0;
}