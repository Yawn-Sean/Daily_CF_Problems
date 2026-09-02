#include<bits/stdc++.h>
using namespace std;

int n;
char s[3];

inline int In(){
	scanf("%s",s + 1);
	if( s[1] == '<' ) return -1;
	else if( s[1] == '>' ) return 1;
	return 0;
}

inline int Ask( int x ){
	printf("%d\n",x); fflush( stdout );
	return In();
}

inline void solve(){
	scanf("%d",&n);
	int l = 1,r = n,ans = -1;
	while( l <= r ){
		int mid = ( l + r ) >> 1;
		int p = Ask( mid );
		if( p == 0 ){ ans = mid; break; }
		if( p == 1 ) l = mid + 1;
		else r = mid - 1;
	}
	l = 1,r = ans - 1; int ans2 = -1;
	while( l <= r ){
		int mid = ( l + r ) >> 1;
		int p = Ask( mid );
		if( p == 0 ){ ans2 = mid; break; }
		if( p == 1 ) l = mid + 1;
		else r = mid - 1;
	}
	if( ans2 != -1 ){
		if( ans > ans2 ) swap( ans , ans2 );
		printf("! %d %d\n",ans,ans2); fflush( stdout );
		return;
	}
	l = ans + 1,r = n,ans2 = -1;
	while( l <= r ){
		int mid = ( l + r ) >> 1;
		int p = Ask( mid );
		if( p == 0 ){ ans2 = mid; break; }
		if( p == 1 ) l = mid + 1;
		else r = mid - 1;
	}
	if( ans > ans2 ) swap( ans , ans2 );
	printf("! %d %d\n",ans,ans2); fflush( stdout );
}

signed main(){
	int t = 1;
	while( t -- ) solve();
	return 0;
}