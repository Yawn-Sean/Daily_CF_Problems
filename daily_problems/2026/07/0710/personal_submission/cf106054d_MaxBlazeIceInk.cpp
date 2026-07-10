#include<bits/stdc++.h>
using namespace std;

#define MAXN 400005
int n,m,cert[MAXN];
map<string,int> M;
map<int,string> R;

//区间赋值，区间和

int len[MAXN << 2],sum[MAXN << 2],tag[MAXN << 2],nxt[MAXN],ori[MAXN];
vector< pair<int,int> > T[MAXN];

inline void update( int t , int k ){ sum[t] = len[t] * k,tag[t] = k; }

inline void push_down( int t ){
	if( tag[t] != -1 )
		update( t << 1 , tag[t] ),update( t << 1 | 1 , tag[t] );
	tag[t] = -1;
}

void build( int t , int l , int r ){
	len[t] = sum[t] = r - l + 1; tag[t] = -1; if( l == r ) return;
	int mid = ( l + r ) >> 1;
	build( t << 1 , l , mid ),build( t << 1 | 1 , mid + 1 , r );
}

void modify( int t, int l , int r , int Ql , int Qr , int k ){
	if( Ql <= l && r <= Qr ){ update( t , k ); return; }
	push_down( t );
	int mid = ( l + r ) >> 1;
	if( Ql <= mid ) modify( t << 1 , l , mid , Ql , Qr , k );
	if( Qr > mid ) modify( t << 1 | 1 , mid + 1 , r , Ql , Qr ,k );
	sum[t] = sum[t << 1] + sum[t << 1 | 1];
}

int query( int t , int l , int r , int x ){
	if( l == r ) return sum[t];
	push_down( t );
	int mid = ( l + r ) >> 1;
	if( x <= mid ) return query( t << 1 , l , mid , x );
	else return query( t << 1 | 1 , mid + 1 , r , x );
}

signed main(){
	cin >> n >> m;
	int cnt = 0;
	for( int i = 1 ; i <= n + m ; i ++ ){
		int v1,v2;
		string S1,S2;
		cin >> v1 >> S1 >> v2 >> S2;
		if( !M[S1] ) M[S1] = ++cnt,R[cnt] = S1;
		if( !M[S2] ) M[S2] = ++cnt,R[cnt] = S2;
		cert[i] = -1;
		if( M[S1] == M[S2] ) cert[i] = v2 > v1 ? 0 : 1;
		if( cert[i] == -1 ){
			T[M[S1]].emplace_back( make_pair( i , 1 ) );
			T[M[S2]].emplace_back( make_pair( i , 0 ) );
		}
	}
	build( 1 , 1 , n + m );
	int lst = n + m + 1;
	for( int i = n + m ; i >= 1 ; i -- ){
		nxt[i] = lst;
		if( cert[i] != -1 ) modify( 1 , 1 , n + m , i , nxt[i] - 1 , cert[i] ),lst = i;
	}
	// cerr << sum[1] << "\n";
	for( int i = 1 ; i <= cnt ; i ++ ){
		//认为 i 是 trump
		for( pair<int,int> p : T[i] )
			ori[p.first] = query( 1 , 1 , n + m , p.first );
		for( pair<int,int> p : T[i] ){
			int id = p.first,val = p.second;
			modify( 1 , 1 , n + m , id , nxt[id] - 1 , val );
			// cerr << "modi" << id << " " << nxt[id] - 1 << " " << val << "\n";
		}
		int v = sum[1];
		if( v == n ){ cout << R[i] << "\n"; return 0; }
		for( pair<int,int> p : T[i] ){
			int id = p.first,val = p.second;
			modify( 1 , 1 , n + m , id , nxt[id] - 1 , ori[id] );
			// cerr << "modi" << id << " " << nxt[id] - 1 << " " << ori[id] << "\n";
		}
	}
	puts("*");
	return 0;
}