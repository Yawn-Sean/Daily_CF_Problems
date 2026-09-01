#include<bits/stdc++.h>
using namespace std;

inline void solve( int s , int k ){
	int now = 1;
	if( k == 1 ){ printf("%d\n",s); return; }
	else{
		for( int i = 1 ; i <= s ; i ++ ){
			now ++;
			if( now == k ){ printf("%d\n",i); return; }
			if( k <= now + 2 * ( s - i ) ){
				if( ( k - now ) % 2 ){ printf("%d\n",i); return; }
				printf("%d\n",i + ( k - now ) / 2);
				return;
			}
			else{
				now += 2 * ( s - i );
			}
		}
	}
	int peri = 2 * s;
	int rem = k - now;
	if( rem % peri == 0 ){ printf("%d\n",s); return; }
	else{
		int rt = s + 1 + rem / peri;
		if( rem % 2 ) printf("%d\n",rt);
		else{
			printf("%d\n",rem % peri / 2);
		}
	}
}

signed main(){
	int s,k;
	while( 1 ){
		scanf("%d%d",&s,&k);
		if( s ) solve( s , k );
		else break;
	}
	return 0;
}