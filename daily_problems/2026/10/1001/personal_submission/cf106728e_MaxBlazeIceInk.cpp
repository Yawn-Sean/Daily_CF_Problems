#include<bits/stdc++.h>
using namespace std;

#define MAXN 105

int n,a[MAXN][MAXN],dir[MAXN][MAXN],ori[MAXN][MAXN],to[MAXN][MAXN];

//横向/纵向

signed main(){
	scanf("%d",&n);
	for( int i = 1 ; i <= n ; i ++ )
		for( int j = 1 ; j <= n ; j ++ ) scanf("%d",&a[i][j]);
	for( int i = 1 ; i <= n ; i ++ ){
		for( int j = 1 ; j <= n ; j ++ ){
			int oi = ( a[i][j] + n - 1 ) / n,oj = a[i][j] % n; if( !oj ) oj = n;
			if( oi != i && oj != j ){ puts("No"); return 0; }
			if( oi != i ) dir[i][j] = 1,to[i][j] = oi;
			if( oj != j ) dir[i][j] = 2,to[i][j] = oj;
			// cerr << i << " " << j << " " << dir[i][j] << "\n";
		}
	}
	for( int i = 1 ; i <= n ; i ++ ){
		for( int j = 1 ; j <= n ; j ++ ){
			if( !dir[i][j] ){
				//不移动的元素不能被从两个方向同时穿过
				int c1 = 0,c2 = 0;
				for( int k = 1 ; k < i ; k ++ )
					if( dir[k][j] == 1 && to[k][j] > i ) c1 = 1;
				for( int k = i + 1 ; k <= n ; k ++ )
					if( dir[k][j] == 1 && to[k][j] < i ) c1 = 1;
				for( int k = 1 ; k < j ; k ++ )
					if( dir[i][k] == 2 && to[i][k] > j ) c2 = 1;
				for( int k = j + 1 ; k <= n ; k ++ )
					if( dir[i][k] == 2 && to[i][k] < j ) c2 = 1;
				// cerr << i << " " << j << " " << c1 << " " << c2 << "\n";
				if( c1 && c2 ){ puts("No"); return 0; }
			}
		}
	}
	//两个元素不能相向穿过
	for( int i = 1 ; i <= n ; i ++ ){
		for( int j = 1 ; j <= n ; j ++ ){
			for( int k = j + 1 ; k <= n ; k ++ ){
				if( dir[i][j] == 2 && dir[i][k] == 2 && to[i][j] > to[i][k] ){
					// cerr << "cross" << i << " " << j << " " << k << "\n";
					puts("No"); return 0;
				}
			}
		}
		for( int j = 1 ; j <= n ; j ++ ){
			for( int k = j + 1 ; k <= n ; k ++ ){
				if( dir[j][i] == 1 && dir[k][i] == 1 && to[j][i] > to[k][i] ){
					puts("No"); return 0;
				}
			}
		}
	}
	puts("Yes");
	return 0;
}