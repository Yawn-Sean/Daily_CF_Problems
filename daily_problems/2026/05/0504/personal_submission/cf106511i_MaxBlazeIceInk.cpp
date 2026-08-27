#include<bits/stdc++.h>
using namespace std;

#define MAXN 405
int n,bel[MAXN],L[MAXN],R[MAXN],ans[MAXN];

const int B = 20;

inline int In(){
	int x; scanf("%d",&x);
	return x;
}

inline pair<int,int> Ask( set<int> A , vector<int> B ){
	printf("?");
	printf(" %d",(int)A.size());
	for( int ele : A ) printf(" %d",ele);
	printf(" %d",(int)B.size());
	for( int ele : B ) printf(" %d",ele); puts(""); fflush( stdout );
	pair<int,int> p; p.first = In(),p.second = In();
	return p;
}

signed main(){
	scanf("%d",&n);
	for( int i = 1 ; i <= n ; i ++ ) bel[i] = ( i - 1 ) / B + 1,ans[i] = -1;
	for( int i = 1 ; i <= n ; i ++ ) R[bel[i]] = i;
	for( int i = n ; i >= 1 ; i -- ) L[bel[i]] = i;
	for( int i = 1 ; i <= bel[n] ; i ++ ){
		set<int> A; vector<int> B;
		for( int j = L[i] ; j <= R[i] ; j ++ ) A.insert( j );
		for( int j = 1 ; j <= bel[n] ; j ++ ){
			B.clear();
			for( int k = L[j] ; k <= R[j] ; k ++ ) B.emplace_back( k );
			while( (int)A.size() ){
				pair<int,int> p = Ask( A , B );
				if( p.first != -1 ){
					ans[p.first] = p.second;
					A.erase( p.first );
				}
				else break;
			}
		}
	}
	printf("!");
	for( int i = 1 ; i <= n ; i ++ ) printf(" %d",ans[i]); puts(""); fflush( stdout );
	return 0;
}