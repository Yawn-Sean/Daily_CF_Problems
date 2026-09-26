#include<bits/stdc++.h>
using namespace std;

inline int In(){
	char s[5]; scanf("%s",s + 1);
	if( s[1] == 'Y' ) return 1;
	else return 0;
}

inline int Ask( int u , int k ){
	printf("? %d %d\n",u,k); fflush( stdout );
	return In();
}

int n;

signed main(){
	scanf("%d",&n);
	int p = n;
	for( int i = 1 ; i <= n ; i ++ )
		while( p && Ask( i , p ) ) p --;
	//显然是均摊
	//p = 环长 - 1
	vector<int> ans;
	for( int i = 1 ; i <= n ; i ++ ){
		if( Ask( i , p + 1 ) ) ans.emplace_back( i );
	}
	printf("! %d",(int)ans.size());
	for( int ele : ans ) printf(" %d",ele); puts(""); fflush( stdout );
	return 0;
}