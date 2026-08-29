#include<bits/stdc++.h>
#pragma GCC optimize("Ofast,unroll-loops")
using namespace std;

#define MAXN 12
#define int long long

const int pw[13] = {1,3,9,27,81,243,729,2187,6561,19683,59049,177147,531441};
int k,A[531441],B[531441];

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

inline void aplyad( int len , int *A , int *B ){
	for( int i = 0 ; i < len ; i ++ ) A[i] += B[i];
}

inline void aplysb( int len , int *A , int *B ){
	for( int i = 0 ; i < len ; i ++ ) A[i] -= B[i];
}

int* calc( int len , int *A , int *B ){
	if( len == 1 ){
		int* C = new int[1]; C[0] = A[0] * B[0];
		return C;
	}
	int *a[3],*b[3],*c[3];
	const int P = len / 3;
	for( int i = 0 ; i < 3 ; i ++ ) a[i] = new int[P],b[i] = new int[P];
	for( int i = 0 ; i < P ; i ++ ){
		a[0][i] = A[i],b[0][i] = B[i];
		a[1][i] = A[i + P],b[1][i] = B[i + P];
		a[2][i] = A[i + ( P << 1 )],b[2][i] = B[i + ( P << 1 )];
	}
	c[2] = calc( P , a[0] , b[1] );
	aplyad( P , c[2] , calc( P , a[1] , b[0] ) );
	aplyad( P , a[1] , a[2] ),aplyad( P , b[1] , b[2] );
	c[0] = calc( P , a[1] , b[1] );
	aplyad( P , a[0] , a[1] ),aplyad( P , b[0] , b[1] );
	c[1] = calc( P , a[0] , b[0] );
	aplysb( P , c[1] , c[0] );
	aplysb( P , c[1] , c[2] );
	int *D = new int[len];
	for( int i = 0 ; i < P ; i ++ ) D[i] = c[0][i],D[i + P] = c[1][i],D[i + ( P << 1 )] = c[2][i];
	for( int i = 0 ; i < 3 ; i ++ ){ delete a[i]; delete b[i]; delete c[i]; }
	return D;
}

signed main(){
	k = read();
	for( int i = 0 ; i < pw[k] ; i ++ ) A[i] = read();
	for( int i = 0 ; i < pw[k] ; i ++ ) B[i] = read();
	int *C = calc( pw[k] , A , B );
	for( int i = 0 ; i < pw[k] ; i ++ ) write( C[i] ),putchar(' ');
	return 0;
}