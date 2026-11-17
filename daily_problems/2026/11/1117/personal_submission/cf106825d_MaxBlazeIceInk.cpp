#include<bits/stdc++.h>
using namespace std;

#define int long long
#define MAXN 200005

int n,a[MAXN];

inline bool check( int x ){
	int soup = 0,dump = 0;
	//简单反悔。
	//上一天存的汤数，总共存的饺子数
	for( int i = 1 ; i <= n ; i ++ ){
		if( a[i] <= soup ){
			//注意奇偶性陷阱
			if( soup % 2 == a[i] % 2 || !a[i] ){
				soup -= a[i];
				dump += soup / 2,soup = x;
			}
			else{
				soup -= max( a[i] - 1 , 0ll );
				dump += soup / 2,soup = x - 1;
			}
		}
		else if( a[i] <= x + soup ){
			soup = x + soup - a[i];
		}
		else{
			int ned = a[i] - x;
			if( soup < ned ){
				ned -= soup; soup = 0; //少一句话太变态了
				if( dump < ned ) return 0;
				dump -= ned;
			}
			else{
				if( !dump || soup % 2 == ned % 2 ) soup -= ned,dump += soup / 2,soup = 0;
				else{
					soup -= ned - 1,dump += soup / 2 - 1,soup = 0;
				}
			}
		}
		// if( x == 5 ) cerr << soup << " " << dump << "\n";
	}
	return 1;
}

signed main(){
	scanf("%lld",&n);
	for( int i = 1 ; i <= n ; i ++ ) scanf("%lld",&a[i]);
	int l = 0,r = (int)1e9,ans = -1;
	while( l <= r ){
		int mid = ( l + r ) >> 1;
		if( check( mid ) ) ans = mid,r = mid - 1;
		else l = mid + 1;
	}
	printf("%lld\n",ans);
	return 0;
}