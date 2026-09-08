#include<bits/stdc++.h>
using namespace std;

#define int long long

int A,B;

vector< pair<int,int> > Ans;

signed main(){
	scanf("%lld%lld",&A,&B);
	while( A != B ){
		if( A % 2 == 0 ){
			Ans.emplace_back( make_pair( 1 , 1 ) );
			A /= 2;
		}
		else if( B % 2 == 0 ){
			Ans.emplace_back( make_pair( 0 , 0 ) );
			B /= 2;
		}
		else if( A > B ){
			Ans.emplace_back( make_pair( 0 , 1 ) );
			A += B;
		}
		else{
			Ans.emplace_back( make_pair( 1 , 0 ) );
			B += A;
		}
	}
	printf("%lld\n",(int)Ans.size());
	for( pair<int,int> p : Ans ){
		printf("%c+=%c\n",char( p.first + 'A' ),char( p.second + 'A' ));
	}
	return 0;
}