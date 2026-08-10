#include<bits/stdc++.h>
using namespace std;

#define MAXN 1005
int n,m,k,swa;
int a[MAXN][MAXN];

inline void Output(){
	puts("YES");
	if( swa ){
		for( int i = 1 ; i <= m ; i ++ , puts("") )
			for( int j = 1 ; j <= n ; j ++ ) printf("%d",a[j][i]);
	}
	else{
		for( int i = 1 ; i <= n ; i ++ , puts("") )
			for( int j = 1 ; j <= m ; j ++ ) printf("%d",a[i][j]);
	}
}

signed main(){
	scanf("%d%d%d",&n,&m,&k); if( n > m ) swap( n , m ),swa = 1;
	if( n == 1 ){
		for( int i = 1 ; i <= m - k + 1 ; i ++ ) a[1][i] = 1;
		for( int i = m - k + 2 ; i <= m ; i ++ ) a[1][i] = a[1][i - 1] ^ 1;
	}
	else if( k == n * m - 1 ){ puts("NO"); return 0; }
		//nm - 1 构造不出
	else{
		if( k <= m ){
			for( int i = 0 ; i < n ; i ++ )
				for( int j = 0 ; j < m ; j ++ )
					a[i + 1][j + 1] = min( j , k - 1 ) % 2;
		}
		else{
			int first = ( k - 1 ) / m + 1;
			for( int i = 0 ; i < first ; i ++ ){
				for( int j = 0 ; j < m ; j ++ ){
					if( i * m + j <= k ) a[i + 1][j + 1] = ( i + j ) % 2;
					else a[i + 1][j + 1] = 1 - ( i + j ) % 2;
				}
			}
			
			for( int i = first ; i < n ; i ++ ){
				for( int j = 0 ; j < m ; j ++ ){
					a[i + 1][j + 1] = a[i][j + 1];	
				}
			}
			
			if( k % m == m - 1 ) a[first][m] = a[first - 1][m];
		}
	}
	Output();
	return 0;
}