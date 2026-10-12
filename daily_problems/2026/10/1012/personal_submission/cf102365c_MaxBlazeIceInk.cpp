#include<bits/stdc++.h>
using namespace std;

#define MAXN 8005
#define INF (int)1e9

int n;

inline int In(){
	int x; scanf("%d",&x);
	return x;
}

inline int Ask( int a , int b , int c ){
	printf("? %d %d %d\n",a,b,c);
	fflush( stdout );
	return In();
}

signed main(){
	scanf("%d",&n);
	int ed = 2;
	for( int i = 3 ; i <= n ; i ++ ){
		if( Ask( 1 , ed , i ) ){
			ed = i;
		}
	}
	printf("! %d\n",ed);
	fflush( stdout );
	return 0;
}