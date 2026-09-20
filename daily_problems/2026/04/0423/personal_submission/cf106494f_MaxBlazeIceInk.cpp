#include<bits/stdc++.h>
using namespace std;

#define MAXN 1000005
#define mod 998244353
#define iv2 499122177
#define int long long

int n,q,a[MAXN],ans[MAXN << 2],coef[MAXN << 2],Ans,cnt[MAXN << 2];

struct node{
	int vl,vr,dif,len,ava;
}T[MAXN << 2];

inline node operator +( node A , node B ){
	node C; C.len = A.len + B.len;
	C.dif = A.dif + B.dif + ( A.vr <= B.vl );
	C.vr = B.vr,C.vl = A.vl;
	C.ava = C.dif == C.len - 1;
	return C;
}

inline void chkadd( int &x , int k ){ x += k; if( x >= mod ) x -= mod; }
inline int reduce( int x ){ return x < 0 ? x + mod : x; }

void build( int t , int l , int r , int c ){
	coef[t] = c;
	if( l == r ){
		T[t] = node{ a[l] , a[l] , 0 , 1 , 1 };
		ans[t] = T[t].len * coef[t] % mod;
		return;
	}
	int mid = ( l + r ) >> 1;
	build( t << 1 , l , mid , c * iv2 % mod );
	build( t << 1 | 1 , mid + 1 , r , c * iv2 % mod );
	T[t] = T[t << 1] + T[t << 1 | 1];
	ans[t] = T[t].len * coef[t] % mod;
	if( !T[t].ava ){
		if( T[t << 1].ava ) chkadd( Ans , ans[t << 1] ),cnt[t << 1] = 1;
		if( T[t << 1 | 1].ava ) chkadd( Ans , ans[t << 1 | 1] ),cnt[t << 1 | 1] = 1;
	}
}

vector<int> segs;
void modify( int t , int l , int r , int x , int k ){
	segs.emplace_back( t );
	if( l == r ){ T[t] = node{ k , k , 0 , 1 , 1 }; return; }
	int mid = ( l + r ) >> 1;
	if( x <= mid ) modify( t << 1 , l , mid , x , k );
	else modify( t << 1 | 1 , mid + 1 , r , x , k );
	segs.emplace_back( t << 1 ),segs.emplace_back( t << 1 | 1 );
	T[t] = T[t << 1] + T[t << 1 | 1];
}

inline int read(){
	int x = 0; char ch = getchar();
	while( ch < '0' || ch > '9' ) ch = getchar();
	while( ch >= '0' && ch <= '9' ) x = x * 10 + ch - 48,ch = getchar();
	return x;
}

signed main(){
	n = read(),q = read();
	for( int i = 1 ; i <= n ; i ++ ) a[i] = read();
	build( 1 , 1 , n , 1 );
	if( T[1].ava ) chkadd( Ans , ans[1] ),cnt[1] = 1;
	for( int i = 1 ; i <= q ; i ++ ){
		int p = read(),x = read();
		segs.clear();
		modify( 1 , 1 , n , p , x );
		for( int ele : segs ){
			int pt = T[ele].ava && !T[ele / 2].ava;
			//分步处理太好用了
			if( !pt && cnt[ele] ) Ans = reduce( Ans - ans[ele] ),cnt[ele] = 0;
			if( pt && !cnt[ele] ) chkadd( Ans , ans[ele] ),cnt[ele] = 1;
		}
		printf("%lld\n",Ans);
	}
	return 0;
}