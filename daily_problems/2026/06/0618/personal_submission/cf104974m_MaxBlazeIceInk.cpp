#include<bits/stdc++.h>
using namespace std;

#define MAXN 1000005

inline int read(){
	int x = 0; char ch = getchar();
	while( ch < '0' || ch > '9' ) ch = getchar();
	while( ch >= '0' && ch <= '9' ) x = x * 10 + ch - 48,ch = getchar();
	return x;
}

void write( int x ){
	if( x >= 10 ) write( x / 10 );
	putchar( x % 10 + 48 );
}

int n,k,a[MAXN],c1[MAXN],c2[MAXN],vis[MAXN];
vector<int> E[MAXN],f[MAXN];

int Gcd( int u , int v ){ return v ? Gcd( v , u % v ) : u; }

signed main(){
	n = read(),k = read();
	// for( int i = 1 ; i <= (int)1e6 ; i ++ )
		// for( int j = i ; j <= (int)1e6 ; j += i ) f[j].emplace_back( i );
	for( int i = 1 ; i <= n ; i ++ ) a[i] = read(),c1[a[i]] ++;
	for( int i = 1 ; i < n ; i ++ ){
		int u = read(),v = read();
		c2[a[u]] ++,c2[a[v]] ++,c2[Gcd( a[u] , a[v] )] --;
		// for( int ele : f[a[u]] ) c2[ele] ++,vis[ele] = 1;
		// for( int ele : f[a[v]] ) if( !vis[ele] ) c2[ele] ++;
		// for( int ele : f[a[u]] ) vis[ele] = 0;
	}
	// cerr << c2[3] << "\n";
	for( int i = 1 ; i <= k ; i ++ ){
		int lostp = 0,loste = 0;
		for( int j = i ; j <= (int)1e6 ; j += i )
			lostp += c1[j],loste += c2[j];
		write( ( n - lostp ) - ( n - 1 - loste ) ),putchar(' ');
	}
	return 0;
}