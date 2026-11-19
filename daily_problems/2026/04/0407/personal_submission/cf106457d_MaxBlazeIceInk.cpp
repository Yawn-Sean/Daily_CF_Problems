#include<bits/stdc++.h>
using namespace std;

#define MAXN 1005

int n,t,b,cntin,cntline,up[MAXN],dn[MAXN],limu[MAXN],limd[MAXN];

inline int In(){
	char s[3]; scanf("%s",s + 1);
	if( s[1] == 'P' ) return 0;
	else if( s[1] == 'I' ) return 1;
	else if( s[1] == 'X' ) return 2;
}

inline int Ask( int x , int y ){
	printf("? %d %d\n",x,y);
	fflush( stdout );
	return In();
}

signed main(){
	scanf("%d%d%d",&n,&t,&b);
	cntline = 2;
	int U = t;
	while( U < n && Ask( 1 , U + 1 ) == 0 ) U ++,cntline ++;
	for( int l = 1 , now = U , typ = 0 ; l < n ; l ++ ){
		up[l] = now;
		limu[l] = typ == 0;
		//已知 (l,now) 为边界/内点
		int st = Ask( l + 1 , now );
		//如果内 -> 边界/外，必有转折
		if( typ == 1 && st != 1 ) break;
		if( st == 2 ) break;
		//内 -> 内,边界 -> 边界,边界 -> 内 都一直走直到变成外
		while( now < n ){
			int st = Ask( l + 1 , now + 1 );
			if( st != 2 ) now ++,typ = st;
			if( typ == 0 || st == 2 ) break;
		}
	}
	int D = t;
	while( D > 1 && Ask( 1 , D - 1 ) == 0 ) D --,cntline ++;
	for( int l = 1 , now = D , typ = 0 ; l < n ; l ++ ){
		dn[l] = now;
		limd[l] = typ == 0;
		int st = Ask( l + 1 , now );
		if( typ == 1 && st != 1 ) break;
		if( st == 2 ) break;
		if( st != 2 ) typ = st;
		while( now > 1 ){
			int st = Ask( l + 1 , now - 1 );
			if( st != 2 ) now --,typ = st;
			if( typ == 0 || st == 2 ) break;
		}
	}
	
	U = b;
	while( U < n && Ask( n , U + 1 ) == 0 ) U ++,cntline ++;
	for( int l = n , now = U , typ = 0 ; l > 1 ; l -- ){
		up[l] = now;
		limu[l] = typ == 0;
		//已知 (l,now) 为边界/内点
		int st = Ask( l - 1 , now );
		//如果内 -> 边界/外，必有转折
		if( typ == 1 && st != 1 ) break;
		if( typ == 0 && st == 0 ) break;
		if( st == 2 ) break;
		typ = st;
		//内 -> 内,边界 -> 边界,边界 -> 内 都一直走直到变成外
		while( now < n ){
			int st = Ask( l - 1 , now + 1 );
			if( st != 2 ) now ++,typ = st;
			if( typ == 0 || st == 2 ) break;
		}
	}
	D = b;
	while( D > 1 && Ask( n , D - 1 ) == 0 ) D --,cntline ++;
	for( int l = n , now = D , typ = 0 ; l > 1 ; l -- ){
		dn[l] = now;
		limd[l] = typ == 0;
		int st = Ask( l - 1 , now );
		if( typ == 1 && st != 1 ) break;
		if( st == 2 ) break;
		if( typ == 0 && st == 0 ) break;
		typ = st;
		while( now > 1 ){
			int st = Ask( l - 1 , now - 1 );
			if( st != 2 ) now --,typ = st;
			if( typ == 0 || st == 2 ) break;
		}
	}
	for( int i = 2 ; i < n ; i ++ ){
		cntin += up[i] - dn[i] + 1;
		if( limd[i] ) cntin --,cntline ++;
		if( limu[i] ) cntin --,cntline ++;
	}
	//2S = 2I + B - 2
	// cerr << cntin << " " << cntline << "\n";
	// for( int i = 1 ; i <= n ; i ++ ) cerr << i << " " << up[i] << " " << dn[i] << " " << limd[i] << " " << limu[i] << "\n";
	printf("! %d",2 * cntin + cntline - 2); //本题行末不能有空格
	fflush( stdout );
	return 0;
}