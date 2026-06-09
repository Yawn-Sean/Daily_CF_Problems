#include<bits/stdc++.h>
using namespace std;

#define MAXN 5005
#define int long long

int n,A;
vector< pair<int,int> > Ans;

inline void solve(){
	scanf("%lld%lld",&n,&A);
	if( 2 * ( A + 1 ) < n ){ puts("No"); return; }
	if( n == 4 ){
		puts("Yes");
		printf("%lld %lld\n%lld %lld\n%lld %lld\n",0ll,0ll,0ll,1ll,1ll,0ll);
		printf("%lld %lld\n",1ll,1 - 2 * A);
		return;
	}
	if( n % 2 ){
		int nowx = 0,nowy = 0,now = 0;
		for( int i = 1 ; i <= n / 2 ; i ++ ){
			Ans.emplace_back( make_pair( nowx , nowy ) );
			if( i == n / 2 ){ now ^= 1; break; }
			if( !now ) nowx --,nowy ++;
			else nowx ++,nowy ++;
			now ^= 1;
		}
		nowx ++;
		for( int i = n / 2 ; i >= 1 ; i -- ){
			Ans.emplace_back( make_pair( nowx , nowy ) );
			if( !now ) nowx ++,nowy --;
			else nowx --,nowy --;
			now ^= 1;
		}
		int rem = A - n / 2 + 1;
		Ans.emplace_back( make_pair( 0 , -rem * 2 ) );
	}
	else{
		int nowx = 0,nowy = 0,now = 0;
		for( int i = 1 ; i <= n / 2 - 1 ; i ++ ){
			Ans.emplace_back( make_pair( nowx , nowy ) );
			if( i == n / 2 - 1 ){ now ^= 1; break; }
			if( !now ) nowx --,nowy ++;
			else nowx ++,nowy ++;
			now ^= 1;
		}
		if( n / 2 % 2 == 0 ){
			nowy ++;
			Ans.emplace_back( make_pair( nowx , nowy ) );
			nowy --,nowx ++;
		}
		else{
			nowx ++,nowy ++;
			Ans.emplace_back( make_pair( nowx , nowy ) );
			nowy --;
		}
		for( int i = n / 2 - 1 ; i >= 1 ; i -- ){
			Ans.emplace_back( make_pair( nowx , nowy ) );
			if( !now ) nowx ++,nowy --;
			else nowx --,nowy --;
			now ^= 1;
		}
		int rem = A * 2 - n + 3;
		//4 -> 0.5
		//6 -> 1.5
		//8 -> 2.5
		//A - n / 2 - 1.5
		Ans.emplace_back( make_pair( 0 , -rem ) );
	}
	puts("Yes");
	for( pair<int,int> ele : Ans ) printf("%lld %lld\n",ele.first,ele.second);
	Ans.clear();
}

signed main(){
	int t; scanf("%lld",&t);
	while( t -- ) solve();
	return 0;
}