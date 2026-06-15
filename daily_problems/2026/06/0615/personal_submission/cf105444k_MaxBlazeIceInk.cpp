#include<bits/stdc++.h>
using namespace std;

#define MAXN 1000005

int len1 = 0,len2 = 0;
char s[MAXN],t[MAXN];
int a[MAXN],b[MAXN],c[MAXN];
int d1[MAXN],d2[MAXN],ans[MAXN];

signed main(){
	scanf("%s%s",s,t);
	len1 = strlen( s ),len2 = strlen( t );
	reverse( s , s + len1 ),reverse( t , t + len2 );
	for( int i = 0 ; i < len1 ; i ++ ) a[i] = s[i] - '0';
	for( int i = 0 ; i < len2 ; i ++ ) b[i] = t[i] - '0';
	int L = max( len1 , len2 ) + 1;
	for( int i = 0 ; i < L ; i ++ ){
		c[i] += a[i] + b[i];
		if( c[i] >= 10 ) c[i + 1] ++,c[i] -= 10;
	}
	//从上往下找到首个大于的，用增减量字典序维护
	for( int i = L - 1 ; i >= 0 ; i -- ){
		if( a[i] > c[i] ){
			for( int j = i ; j >= 0 ; j -- )
				d1[j] = a[j] - c[j];
			break;
		}
	}
	for( int i = L - 1 ; i >= 0 ; i -- ){
		if( b[i] > c[i] ){
			for( int j = i ; j >= 0 ; j -- )
				d2[j] = b[j] - c[j];
			break;
		}
	}
	for( int i = L - 1 ; i >= 0 ; i -- ){
		if( d1[i] == d2[i] ) continue;
		if( d1[i] > d2[i] ) memcpy( d1 , d2 , sizeof( d2 ) );
		break;
	}
	for( int i = 0 ; i < L ; i ++ ){
		ans[i] += d1[i];
		if( ans[i] < 0 ) ans[i + 1] --,ans[i] += 10;
	}
	int t = L; while( t && !ans[t] ) t --;
	if( t < 0 ){ puts("0"); return 0; }
	for( int i = t ; i >= 0 ; i -- ) printf("%d",ans[i]);
	return 0;
}