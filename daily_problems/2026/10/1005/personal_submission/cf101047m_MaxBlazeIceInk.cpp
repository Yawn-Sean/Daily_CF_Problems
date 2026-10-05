#include<bits/stdc++.h>
using namespace std;

#define MAXN 200005

int n;
char s[MAXN];

//从边界往外推

inline void solve(){
	scanf("%d%s",&n,s + 1);
	int l = 1;
	vector<int> ans,cr;
	while( l <= n ){
		if( s[l] == 'D' ){
			ans.emplace_back( l );
			while( cr.size() ) ans.emplace_back( cr.back() ),cr.pop_back();
			if( l < n ) s[l + 1] = 'D' + 'B' - s[l + 1];
			l ++;
		}
		else{
			cr.emplace_back( l ),l ++;
		}
	}
	if( !cr.size() ){
		puts("Y");
		for( int ele : ans ) printf("%d ",ele);
		puts("");
	}
	else puts("N");
	return;
}

signed main(){
	int t; scanf("%d",&t);
	while( t -- ) solve();
	return 0;
}