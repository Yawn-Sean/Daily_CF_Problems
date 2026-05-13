#include<bits/stdc++.h>
using namespace std;

#define int __int128

#define MAXN 200005

int n,P,h[MAXN],p[MAXN],hs[MAXN],hcnt;
vector<int> T[MAXN];

int sump[MAXN << 2],sumh[MAXN << 2],minn[MAXN << 2];

void modify( int t , int l , int r , int x ){
	if( l == r ){ sumh[t] = hs[h[l]],sump[t] = minn[t] = p[l]; return; }
	int mid = ( l + r ) >> 1;
	if( x <= mid ) modify( t << 1 , l , mid , x );
	else modify( t << 1 | 1 , mid + 1 , r , x );
	sump[t] = sump[t << 1] + sump[t << 1 | 1];
	sumh[t] = sumh[t << 1] + sumh[t << 1 | 1];
	minn[t] = min( minn[t << 1] , minn[t << 1 | 1] );
}

int find_nxt( int t , int l , int r , int L , int S , int &sum , int &hap ){
	if( l == r ){
		if( sum + sump[t] <= S ){ sum += sump[t],hap += sumh[t]; return -1; }
		else return l;
	}
	int mid = ( l + r ) >> 1;
	if( L == l ){
		if( S < sum + sump[t << 1] ) return find_nxt( t << 1 , l , mid , L , S , sum , hap );
		sum += sump[t << 1],hap += sumh[t << 1];
		return find_nxt( t << 1 | 1 , mid + 1 , r , mid + 1 , S , sum , hap );
	}
	if( L <= mid ){
		int tt = find_nxt( t << 1 , l , mid , L , S , sum , hap );
		if( tt != -1 ) return tt;
		return find_nxt( t << 1 | 1 , mid + 1 , r , mid + 1 , S , sum , hap );
	}
	return find_nxt( t << 1 | 1 , mid + 1 , r , L , S , sum , hap );
}

int nxt_miner( int t , int l , int r , int L , int S ){
	if( l == r ) return minn[t] <= S ? l : -1;
	int mid = ( l + r ) >> 1;
	if( L <= mid && minn[t << 1] <= S ){
		int tt = nxt_miner( t << 1 , l , mid , L , S );
		if( tt != -1 ) return tt;
	}
	return nxt_miner( t << 1 | 1 , mid + 1 , r , L , S );
}

inline int read(){
	int x = 0; char ch = getchar();
	while( ch < '0' || ch > '9' ) ch = getchar();
	while( ch >= '0' && ch <= '9' ) x = x * 10 + ch - 48,ch = getchar();
	return x;
}

inline void solve(){
	n = read(),P = read();
	for( int i = 1 ; i <= 4 * n ; i ++ ) minn[i] = (int)2e18;
	for( int i = 1 ; i <= n ; i ++ ) h[i] = read(),p[i] = read(),hs[++hcnt] = h[i];
	hs[++hcnt] = 0;
	sort( hs + 1 , hs + hcnt + 1 );
	hcnt = unique( hs + 1 , hs + hcnt + 1 ) - ( hs + 1 );
	for( int i = 1 ; i <= n ; i ++ ) h[i] = lower_bound( hs + 1 , hs + hcnt + 1 , h[i] ) - hs,T[h[i]].emplace_back( i );
	int ans1 = 0,ans2 = hs[hcnt];
	for( int i = hcnt ; i >= 1 ; i -- ){
		for( int ele : T[i] ) modify( 1 , 1 , n , ele );
		int now = 1,tmp = P,ans = 0;
		while( 1 ){
			int sum = 0,res = 0;
			int nxt = find_nxt( 1 , 1 , n , now , tmp , sum , res );
			tmp -= sum,ans += res;
			if( nxt == -1 ) break;
			nxt = nxt_miner( 1 , 1 , n , nxt , tmp );
			// if( nxt <= now ) break;
			if( nxt == -1 ) break;
			now = nxt;
		}
		if( ans > ans1 ) ans1 = ans,ans2 = hs[i - 1];
		else if( ans1 == ans ) ans2 = hs[i - 1];
	}
	printf("%lld %lld\n",(long long)ans1,(long long)ans2);
	for( int i = 1 ; i <= 4 * n ; i ++ ) sumh[i] = sump[i] = minn[i] = 0;
	for( int i = 1 ; i <= hcnt ; i ++ ) T[i].clear();
	hcnt = 0;
}

signed main(){
	int t = read();
	while( t -- ) solve();
	return 0;
}