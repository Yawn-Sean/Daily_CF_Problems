#include<bits/stdc++.h>
using namespace std;

#define MAXN 255

int n,a[MAXN];

signed main(){
	scanf("%d",&n);
	for( int i = 1 ; i <= n ; i ++ ){
		scanf("%d",&a[i]);
	}
	int cnt = 0;
	vector<int> ans;
	while( 1 ){
		if( a[1] > a[2] && !( a[1] == n && a[2] == 1 ) ) ans.emplace_back( 1 ),swap( a[1] , a[2] ),cnt = 0;
		else{
			cnt ++;
			ans.emplace_back( 2 );
			int tmp = a[1];
			for( int i = 1 ; i < n ; i ++ ) a[i] = a[i + 1];
			a[n] = tmp; 
		}
		if( cnt == n ) break;
	}
	while( 1 ){
		if( a[1] == 1 ) break;
		ans.emplace_back( 2 );
			int tmp = a[1];
			for( int i = 1 ; i < n ; i ++ ) a[i] = a[i + 1];
			a[n] = tmp; 
	}
	if( !ans.size() ) puts("empty");
	for( int ele : ans ) printf("%c",ele == 1 ? 'S' : 'P');
	return 0;
}