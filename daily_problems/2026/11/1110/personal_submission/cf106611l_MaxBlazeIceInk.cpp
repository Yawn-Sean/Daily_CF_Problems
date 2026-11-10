#include<bits/stdc++.h>
using namespace std;

#define MAXN 100005

int n,cert[MAXN];

vector<int> E[MAXN];
char s[MAXN];

//刷两遍应该够了
void dfs( int x ){
	for( int v : E[x] ){
		if( !cert[v] ){
			cert[v] = -cert[x];
			dfs( v );
		}
	}
}

signed main(){
	scanf("%d%s",&n,s + 1);
	for( int i = 1 ; i <= n ; i ++ ){
		if( s[i] == '2' ){
			cert[i - 1] = cert[i + 1] = 1;
		}
		if( s[i] == '1' ){
			int notL = i == 1 || s[i - 1] != '?';
			int notR = i == n || s[i + 1] != '?';
			if( notL ) cert[i + 1] = 1;
			else if( notR ) cert[i - 1] = 1; 
			else{
				E[i - 1].emplace_back( i + 1 );
				E[i + 1].emplace_back( i - 1 );
			}
		}
		if( s[i] == '0' ){
			//判是否是问号
			if( s[i - 1] == '?' ) cert[i - 1] = -1;
			if( s[i + 1] == '?' ) cert[i + 1] = -1;
		}
	}
	for( int i = 1 ; i <= n ; i ++ ) if( cert[i] ) dfs( i );
	for( int i = n ; i >= 1 ; i -- ) if( cert[i] ) dfs( i );
	int ans = 0;
	for( int i = 1 ; i <= n ; i ++ ) ans += cert[i] == -1;
	printf("%d\n",ans);
	return 0;
}