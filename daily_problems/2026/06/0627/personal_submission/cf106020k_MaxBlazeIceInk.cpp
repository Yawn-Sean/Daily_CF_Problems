#include<bits/stdc++.h>
using namespace std;

#define int long long
#define MAXN 100005

int n,k,f[30][30];
int ans[MAXN];

inline void fill( int x , int k , int bas ){
	vector<int> fre( x + 1 , 0ll ),used( x + 1 , 0ll );
	//是否为自由位置
	// cerr << f[2][1] << "\n";
	int Fre = 0;
	for( int i = 1 ; i <= x ; i ++ ){
		int op = fre[i],id = 0;
		for( int j = 1 ; j <= x ; j ++ ){
			if( used[j] || j == i ) continue;
			if( j <= i ){
				//<=i 的数如果放下来则自由元数量不变
				int upd = f[x - i][Fre - op];
				id = j;
				if( k > upd ) k -= upd;
				else break;
			}
			else{
				//否则自由元数量 +1
				int upd = f[x - i][Fre + 1 - op];
				id = j;
				if( k > upd ) k -= upd;
				else break;
			}
		}
		//确定填 id
		used[id] = fre[id] = 1,ans[i + bas - 1] = id + bas - 1;
		if( id > i ) Fre += 1 - op;
		else Fre -= op;
		// cerr << k << " " << Fre << " " << id << "\n";
	}
}

inline void solve(){
	scanf("%lld%lld",&n,&k);
	int l = 1,N = n;
	while( N - 2 >= 21 ) ans[l] = l + 1,ans[l + 1] = l,l += 2,N -= 2;
	fill( N , k , l );
	for( int i = 1 ; i <= n ; i ++ ) printf("%lld ",ans[i]); puts("");
}

//2 1 4 3
//2 3 4 1
//2 4 1 3
//3 1 4 2
//3 4 1 2
//3 4 2 1
//4 1 2 3
//4 3 1 2
//4 3 2 1

//2

signed main(){
	f[0][0] = 1;
	for( int i = 1 ; i < 30 ; i ++ )
		for( int j = 0 ; j <= i ; j ++ ){
			if( j ){
				f[i][j] += f[i - 1][j - 1] * j;
				f[i][j] += f[i - 1][j] * ( i - j );
			}
			else f[i][j] = ( i - 1 ) * ( f[i - 1][j] + f[i - 2][j] );
		}
	// cerr << f[21][0] << "\n";
	int t; scanf("%lld",&t);
	while( t -- ) solve();
}