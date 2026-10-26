#include<bits/stdc++.h>
using namespace std;

int n;

vector<int> ans;

//简单构造

signed main(){
	scanf("%d",&n);
	ans.emplace_back( 1 );
	ans.emplace_back( 1 );
	for( int i = 2 ; i <= n ; i ++ ){
		vector<int> B;
		for( int ele : ans ){
			if( ele == i - 1 ){
			B.emplace_back( i );
			B.emplace_back( i );
			}
			B.emplace_back( ele );
		}
		ans = B;
	}
	printf("%d\n",ans.size());
	for( int ele : ans ) printf("%d ",ele);
	return 0;
}