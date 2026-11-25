#include<bits/stdc++.h>
#include<cassert>
using namespace std;

int w[16],p[16];

inline void weigh( int x ){
	//令 R - L = x
	vector<int> A,B;
	//取出 x 的三进制表示
	//15 = 9 + 3 * 2 -> 2 * 9 - 3 -> 15 - 9 - 3
	int tmp = x;
	for( int i = 14 ; i >= 0 ; i -- ){
		p[i] = tmp / ( w[i] / 2 );
		tmp %= ( w[i] / 2 );
	}
	for( int i = 0 ; i < 14 ; i ++ ){
		if( p[i] == 2 ){
			p[i + 1] ++,p[i] = -1;
		}
		else if( p[i] == 3 ) p[i + 1] ++,p[i] = 0;
	}
	for( int i = 0 ; i <= 14 ; i ++ ){
		if( p[i] == 1 ) B.emplace_back( i + 1 );
		if( p[i] == -1 ) A.emplace_back( i + 1 );
	}
	A.emplace_back( 0 );
	printf("%d\n",A.size());
	for( int ele : A ) printf("%d ",ele);
	puts("");
	printf("%d\n",B.size());
	for( int ele : B ) printf("%d ",ele);
	puts("");
	fflush( stdout );
	// int s1 = 0,s2 = 0;
	// for( int ele : A ) s1 += w[ele - 1];
	// for( int ele : B ) s2 += w[ele - 1];
	// assert( s2 - s1 == x * 2 );
}

inline int ask( int x ){
	if( x == 0 ) return 1;
	//问 2*x
	puts("WEIGH");
	weigh( x );
	char s[10]; scanf("%s",s + 1);
	if( s[1] == '<' ) return -1;
	if( s[1] == '>' ) return 1;
	return 0;
}

inline void solve(){
	// int s = 0;
	// for( int i = 0 ; i < 15 ; i ++ ) s += w[i];
	// cerr << s / 2 << "\n";
	int l = 0,r = 7174453,ans = -1;
		char s[10];
	while( l <= r ){
		// cerr << l << " " << r << "\n";
		int mid = ( l + r ) >> 1;
		int p = ask( mid );
		if( p == 0 ){
			puts("VERDICT\nEXACT");
			printf("%d\n",2 * mid);
			fflush( stdout );
			scanf("%s",s + 1);
			return;
		}
		if( p == 1 ){
			l = mid + 1;
			if( ask( l ) == -1 ){
				puts("VERDICT\nEXACT");
				printf("%d\n",2 * l - 1);
				fflush( stdout );
				scanf("%s",s + 1);
				return;
			}
		}
		else{
			r = mid - 1;
			if( ask( r ) == 1 ){
				puts("VERDICT\nEXACT");
				printf("%d\n",2 * r + 1);
				fflush( stdout );
				scanf("%s",s + 1);
				return;
			}
		}
	}
	puts("VERDICT\nHEAVY");
	fflush( stdout );
	scanf("%s",s + 1);
}

signed main(){
	w[0] = 2;
	for( int i = 1 ; i <= 14 ; i ++ ) w[i] = w[i - 1] * 3;
	puts("15");
	for( int i = 0 ; i < 15 ; i ++ ) printf("%d ",w[i]); puts("");
	puts("14148906");
	int M = 1414;
	fflush( stdout );
	int t; scanf("%d",&t);
	while( t -- ) solve();
	//没问题
	// for( int i = 0 ; i <= 7174453 ; i ++ ){
		// weigh( i );
	// }
	return 0;
}