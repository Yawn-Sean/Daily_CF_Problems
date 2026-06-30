#include<bits/stdc++.h>
using namespace std;

#define MAXN 100005

int n,k,a[MAXN];

inline int In(){ int x; scanf("%d",&x); return x; }

signed main(){
	scanf("%d%d",&n,&k);
	for( int i = 1 ; i <= n ; i ++ ) scanf("%d",&a[i]);
	set< pair<int,int> > S1,S2;
	for( int i = 1 ; i <= n ; i += 2 ) S1.insert( make_pair( a[i] , i ) );
	for( int i = 2 ; i <= n ; i += 2 ) S2.insert( make_pair( a[i] , i ) );
	while( S1.size() > k ) S1.erase( S1.begin() );
	while( S2.size() > k ) S2.erase( S2.begin() );
	for( int i = 1 ; i <= k ; i ++ ){
		int x; scanf("%d",&x);
		if( x == 2 ){
			pair<int,int> p = *S2.rbegin();
			printf("%d\n",p.second); fflush( stdout );
			In();
			S2.erase( p );
		}
		else{
			pair<int,int> p = max( *S1.rbegin() , *S2.rbegin() );
			if( (*S1.rbegin()).first >= (*S2.rbegin()).first ){
				p = *S1.rbegin();
				printf("%d\n",p.second); fflush( stdout );
				In();
				S1.erase( p ),S2.erase( S2.begin() );
			}
			else{
				if( (*S1.rbegin()).first >= (*S2.begin()).first ){
					p = *S1.rbegin();
					printf("%d\n",p.second); fflush( stdout );
					In();
					S1.erase( p ),S2.erase( S2.begin() );
				}
				else{
					p = *S2.rbegin();
					printf("%d\n",p.second); fflush( stdout );
					In();
					S2.erase( p );//S2.erase( S2.begin() );	
				}
			}
		}
	}
	return 0;
}