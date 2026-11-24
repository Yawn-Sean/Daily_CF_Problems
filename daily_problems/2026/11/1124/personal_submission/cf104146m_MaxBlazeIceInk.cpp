#include<bits/stdc++.h>
using namespace std;

#define MAXN 1205

//构造低手来了，你们聊

//1*x 很好用，但是我想到了不会用又怎么办呢

int n;

signed main(){
	scanf("%d",&n);
	if( n == 2 || n == 4 ){ puts("NO"); return 0; }
	if( n == 6 ){
		puts("YES");
		printf("ABBBBE\n");
		printf("CCCFFE\n");
		printf("DDDDDE\n");
		printf("DDDDDE\n");
		printf("DDDDDE\n");
		printf("DDDDDE\n");
		return 0;
	}
	if( n % 2 ){
		puts("YES");
		int now = 0;
		for( int i = 1 , j = 1 ; i <= n / 2 ; i ++ , j ++ ){
			if( now ){
				for( int k = 1 ; k <= j ; k ++ ) printf("A");
				for( int k = 1 ; k <= n - j ; k ++ ) printf("B");
				puts("");
			}
			else{
				for( int k = 1 ; k <= j ; k ++ ) printf("C");
				for( int k = 1 ; k <= n - j ; k ++ ) printf("D");
				puts("");
			}
			now ^= 1;
		}
		for( int j = 1 ; j <= n / 2 + 1 ; j ++ , puts("") ){
			for( int k = 1 ; k <= n ; k ++ ){
				printf("E");
			}
		}
		return 0;
	}
	else{
		/*
		n=8:
		ABBBBBBB
		CCDDDDDD
		EEEEEEEE
		FGGGHHHH
		FGGGHHHH
		FGGGHHHH
		FGGGHHHH
		FGGGHHHH
		*/
		puts("YES");
		int now = 0;
		for( int i = 1 , j = 1 ; i < n / 2 - 1 ; i ++ , j ++ ){
			if( now ){
				for( int k = 1 ; k <= j ; k ++ ) printf("A");
				for( int k = 1 ; k <= n - j ; k ++ ) printf("B");
				puts("");
			}
			else{
				for( int k = 1 ; k <= j ; k ++ ) printf("C");
				for( int k = 1 ; k <= n - j ; k ++ ) printf("D");
				puts("");
			}
			now ^= 1;
		}
		for( int i = 1 ; i <= n ; i ++ ) printf("E");
		puts("");
		for( int i = 1 ; i <= 2 ; i ++ ){
			printf("F");
			for( int j = 1 ; j <= n - 1 ; j ++ ) printf("G");
			puts("");
		}
		for( int i = 1 ; i <= n / 2 - 1 ; i ++ ){
			printf("F");
			for( int j = 1 ; j <= n - 1 ; j ++ ) printf("H");
			puts("");
		}
	}
	return 0;
}