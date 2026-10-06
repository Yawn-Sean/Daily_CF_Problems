#include<bits/stdc++.h>
using namespace std;

#define int long long
#define MAXN 2005

int n,H,K;

pair<int,int> P[MAXN];

//(9,8),(1,1)

inline bool cmp( pair<int,int> A , pair<int,int> B ){
	return A.first - A.second > B.first - B.second;
}

inline void solve(){
	scanf("%lld%lld%lld",&n,&H,&K);
	vector< pair<int,int> > S,T;
	for( int i = 1 ; i <= n ; i ++ ){
		scanf("%lld%lld",&P[i].first,&P[i].second);
		if( P[i].first <= P[i].second ){
			S.emplace_back( make_pair( P[i].first , P[i].second - P[i].first ) );
		}
		else{
			T.emplace_back( make_pair( P[i].first , P[i].first - P[i].second ) );
		}
	}
	sort( S.begin() , S.end() );
	int res = 0;
	for( int i = 0 ; i < (int)S.size() ; i ++ ){
		if( H > S[i].first ) H += S[i].second;
		else{ res += S.size() - i; break; }
	}
	// cerr << H << " " << res << "\n";
	sort( T.begin() , T.end() , cmp );
	priority_queue<int> Q;
	int sum = 0,c = (int)T.size();
	for( int i = 0 ; i < (int)T.size(); i ++ ){
    	int d = T[i].second;
    	int y = T[i].first - d;
    	int deadline = H - y - 1;    
   	 	sum += d; Q.push(d),c --;
    	if( sum > deadline ){ c ++,sum -= Q.top(); Q.pop(); }
	}
	if( res + c > K ) puts("N");
	else puts("Y");
}

signed main(){
	int t; scanf("%lld",&t);
	while( t -- ) solve();
	return 0;
}