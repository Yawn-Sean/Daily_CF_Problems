#include<bits/stdc++.h>
using namespace std;

#define MAXN 10000005

bool notp[MAXN];
int n,prime[MAXN],ptot,c = 0;
int prep[100005];

inline void sieve(){
	notp[1] = 1;
	for( int i = 2 ; i < MAXN ; i ++ ){
		if( !notp[i] ) prime[++ptot] = i;
		for( int j = 1 ; j <= ptot && i * prime[j] < MAXN ; j ++ ){
			notp[i * prime[j]] = 1;
			if( i % prime[j] == 0 ) break;
		}
	}
	for( int i = 3 ; i < ptot && c <= 100000 ; i ++ )
		if( prime[i] + 2 == prime[i + 1] ) prep[++c] = prime[i];
}

vector< pair<int,int> > Ans;

inline void solve(){
	scanf("%d",&n);
	Ans.emplace_back( make_pair( 0 , 0 ) );
	Ans.emplace_back( make_pair( 0 , -2 ) );
	Ans.emplace_back( make_pair( -2 , 0 ) );
	Ans.emplace_back( make_pair( -2 , -2 ) );
	for( int i = 1 ; i <= ( n + 3 ) / 4 ; i ++ )
		Ans.emplace_back( make_pair( prep[i * 2 - 1] , prep[i * 2] ) );
	printf("%d\n",(int)Ans.size());
	for( pair<int,int> p : Ans ) printf("%d %d\n",p.first,p.second);
	int now = 0;
	for( int i = 1 ; i <= ( n + 3 ) / 4 ; i ++ ){
		now ++;
		printf("%d %d %d\n",1,2,i + 4);
		if( now == n ) break;
		now ++;
		printf("%d %d %d\n",3,4,i + 4);
		if( now == n ) break;
		now ++;
		printf("%d %d %d\n",1,3,i + 4);
		if( now == n ) break;
		now ++;
		printf("%d %d %d\n",2,4,i + 4);
		if( now == n ) break;
	}
	Ans.clear();
}

signed main(){
	sieve();
	int t; scanf("%d",&t);
	while( t -- ) solve();
	return 0;
}