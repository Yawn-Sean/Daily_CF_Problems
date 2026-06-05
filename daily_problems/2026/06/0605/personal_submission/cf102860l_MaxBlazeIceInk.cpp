#include<bits/stdc++.h>
using namespace std;

#define MAXN 200005

int n,q;

struct tag{
	int rev,adx,ady;
}T[MAXN << 2];

inline tag operator *( tag A , tag B ){
	if( B.rev ) swap( A.adx , A.ady ),A.rev ^= 1;
	A.adx += B.adx,A.ady += B.ady;
	return A;
}

int X[MAXN << 2],Y[MAXN << 2];

inline void update( int t , tag Tag ){
	if( Tag.rev ) swap( X[t] , Y[t] );
	X[t] += Tag.adx,Y[t] += Tag.ady;
	T[t] = T[t] * Tag;
}

inline void push_down( int t ){
	update( t << 1 , T[t] );
	update( t << 1 | 1 , T[t] );
	T[t] = tag{ 0 , 0 , 0 };
}

void modify( int t , int l , int r , int Ql , int Qr , tag Tag ){
	if( Ql <= l && r <= Qr ){ update( t , Tag ); return; }
	push_down( t );
	int mid = ( l + r ) >> 1;
	if( Ql <= mid ) modify( t << 1 , l , mid , Ql , Qr , Tag );
	if( Qr > mid ) modify( t << 1 | 1 , mid + 1 , r , Ql , Qr , Tag );
}

pair<int,int> query( int t , int l , int r , int x ){
	if( l == r ) return make_pair( X[t] , Y[t] );
	push_down( t );
	int mid = ( l + r ) >> 1;
	if( x <= mid ) return query( t << 1 , l , mid , x );
	return query( t << 1 | 1 , mid + 1 , r , x );
}

signed main(){
	scanf("%d%d",&n,&q);
	for( int i = 1 ; i <= n ; i ++ ) modify( 1 , 1 , n , i , i , tag{ 0 , i , 1 } );
	for( int i = 1 ; i <= q ; i ++ ){
		int op; scanf("%d",&op);
		if( op == 1 ){
			int l,r; scanf("%d%d",&l,&r);
			if( l == r ) continue;
			pair<int,int> p1 = query( 1 , 1 , n , l );
			// cerr << p1.first << " " << p1.second << "\n";
			modify( 1 , 1 , n , l , r , tag{ 1 , p1.first - p1.second , p1.second - p1.first } ); 
			p1 = query( 1 , 1 , n , 4 );
			// cerr << p1.first << " " << p1.second << "\n";
		}
		else{
			int x; scanf("%d",&x);
			pair<int,int> p1 = query( 1 , 1 , n , x );
			printf("%d %d\n",p1.first,p1.second - 1);
		}
	}
	return 0;
}