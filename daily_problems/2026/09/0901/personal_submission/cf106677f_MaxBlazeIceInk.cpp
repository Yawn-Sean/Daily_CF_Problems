#include<bits/stdc++.h>
using namespace std;

#define int long long
#define MAXN 410
#define INF (int)1e18

int n,u,v,m,a[MAXN],b[MAXN],c[MAXN],d[MAXN];
int xs[MAXN],xcnt,ys[MAXN],ycnt,D[MAXN][MAXN];
int dis[MAXN][MAXN][4],vis[MAXN][MAXN][4];
int X[MAXN][MAXN][4],Y[MAXN][MAXN][4];

//要写对啊！！！！
int dxp[4][2][3] = {{{-1,0,2},{0,-1,1}},{{-1,0,3},{0,1,0}},{{1,0,0},{0,-1,3}},{{1,0,1},{0,1,2}}};

struct node{
	int x,y,id,d;
	inline bool operator <( const node &b ) const{
		return b.d < d;
	}
};

inline int Abs( int x ){ return x < 0 ? -x : x; }

inline int Manha( int X1 , int Y1 , int id1 , int X2 , int Y2 , int id2 ){
	return Abs( X[X1][Y1][id1] - X[X2][Y2][id2] ) + Abs( Y[X1][Y1][id1] - Y[X2][Y2][id2] );
}

inline void solve(){
	scanf("%lld",&m);
	xs[++xcnt] = 1,xs[++xcnt] = n + 1,ys[++ycnt] = 1,ys[++ycnt] = n + 1;
	xs[++xcnt] = u,xs[++xcnt] = u + 1,ys[++ycnt] = v,ys[++ycnt] = v + 1;
	for( int i = 1 ; i <= m ; i ++ ){
		scanf("%lld%lld%lld%lld",&a[i],&b[i],&c[i],&d[i]);
		xs[++xcnt] = a[i],xs[++xcnt] = b[i] + 1;
		ys[++ycnt] = c[i],ys[++ycnt] = d[i] + 1;
	}
	sort( xs + 1 , xs + xcnt + 1 );
	sort( ys + 1 , ys + ycnt + 1 );
	xcnt = unique( xs + 1 , xs + xcnt + 1 ) - ( xs + 1 );
	ycnt = unique( ys + 1 , ys + ycnt + 1 ) - ( ys + 1 );
	// for( int i = 1 ; i <= xcnt ; i ++ ) cerr << xs[i] << " "; cerr << "\n";
	// for( int i = 1 ; i <= ycnt ; i ++ ) cerr << ys[i] << " "; cerr << "\n";
	for( int i = 1 ; i <= xcnt ; i ++ ){
		for( int j = 1 ; j <= ycnt ; j ++ ){
			X[i][j][0] = xs[i],Y[i][j][0] = ys[j];
			X[i][j][1] = xs[i],Y[i][j][1] = ys[j + 1] - 1;
			X[i][j][2] = xs[i + 1] - 1,Y[i][j][2] = ys[j];
			X[i][j][3] = xs[i + 1] - 1,Y[i][j][3] = ys[j + 1] - 1;
			// for( int k = 0 ; k < 4 ; k ++ )
			// cerr << i << " " << j << " " << k << " " << X[i][j][k] << " " << Y[i][j][k] << "\n"; 
		}
	}
	for( int i = 1 ; i <= m ; i ++ ){
		int xl = lower_bound( xs + 1 , xs + xcnt + 1 , a[i] ) - xs;
		int xr = lower_bound( xs + 1 , xs + xcnt + 1 , b[i] + 1 ) - xs - 1;
		int yl = lower_bound( ys + 1 , ys + ycnt + 1 , c[i] ) - ys;
		int yr = lower_bound( ys + 1 , ys + ycnt + 1 , d[i] + 1 ) - ys - 1;
		D[xl][yl] ++,D[xl][yr + 1] --,D[xr + 1][yl] --,D[xr + 1][yr + 1] ++;
	}
	for( int i = 1 ; i <= xcnt ; i ++ )
		for( int j = 1 ; j <= ycnt ; j ++ ) D[i][j] += D[i][j - 1];
	for( int j = 1 ; j <= ycnt ; j ++ )
		for( int i = 1 ; i <= xcnt ; i ++ ) D[i][j] += D[i - 1][j];
	
	// for( int i = 1 ; i <= xcnt ; i ++ ){
		// for( int j = 1 ; j <= ycnt ; j ++ ){
			// cerr << i << " " << j << " " << D[i][j] << "\n";
			// // cerr << i << " " << j << " " << k << " " << X[i][j][k] << " " << Y[i][j][k] << "\n"; 
		// }
	// }
	int sx = lower_bound( xs + 1 , xs + xcnt + 1 , u ) - xs;
	int sy = lower_bound( ys + 1 , ys + ycnt + 1 , v ) - ys;
	for( int i = 1 ; i <= xcnt ; i ++ )
		for( int j = 1 ; j <= ycnt ; j ++ )
			for( int k = 0 ; k < 4 ; k ++ ) dis[i][j][k] = INF;
	priority_queue<node> Q;
	for( int k = 0 ; k < 4 ; k ++ ) dis[sx][sy][k] = 0,Q.push( node{ sx , sy , k , 0 } );
	while( !Q.empty() ){
		node u = Q.top(); Q.pop();
		//01
		//23
		int x = u.x,y = u.y,id = u.id;
		// cerr << x << " " << y << " " << id << "(" << X[x][y][id] << "," << Y[x][y][id] << ")" << dis[x][y][id] << "\n";
		if( vis[x][y][id] ) continue;
		vis[x][y][id] = 1;
		if( !D[x][y] ){
			for( int k = 0 ; k < 4 ; k ++ ){
				if( k == id ) continue;
				int w = Manha( x , y , id , x , y , k );
				if( dis[x][y][k] > dis[x][y][id] + w ){
					dis[x][y][k] = dis[x][y][id] + w;
					Q.push( node{ x , y , k , dis[x][y][k] } );
				}
			}
		}
		for( int k1 = 0 ; k1 < 2 ; k1 ++ ){
			int nx = x + dxp[id][k1][0],ny = y + dxp[id][k1][1],nid = dxp[id][k1][2];
			if( nx < 1 || nx >= xcnt || ny < 1 || ny >= ycnt || D[nx][ny] ) continue;
			int w = Manha( x , y , id , nx , ny , nid );
			if( dis[nx][ny][nid] > dis[x][y][id] + w ){
				dis[nx][ny][nid] = dis[x][y][id] + w;
				Q.push( node{ nx , ny , nid , dis[nx][ny][nid] } );
			}
		}
	}
	int q; scanf("%lld",&q);
	while( q -- ){
		int qx,qy; scanf("%lld%lld",&qx,&qy);
		int ans = INF;
		int nx = upper_bound( xs + 1 , xs + xcnt + 1 , qx ) - xs - 1;
		int ny = upper_bound( ys + 1 , ys + ycnt + 1 , qy ) - ys - 1;
		for( int k = 0 ; k < 4 ; k ++ ){
			int w = Abs( X[nx][ny][k] - qx ) + Abs( Y[nx][ny][k] - qy );
			ans = min( ans , w + dis[nx][ny][k] );
		}
		if( ans == INF ) puts("no");
		else printf("%lld\n",ans);
	}
	for( int i = 1 ; i <= xcnt ; i ++ ){
		for( int j = 1 ; j <= ycnt ; j ++ ){
			D[i][j] = 0;
			for( int k = 0 ; k < 4 ; k ++ )
				X[i][j][k] = Y[i][j][k] = dis[i][j][k] = vis[i][j][k] = 0;
		}
	}
	xcnt = ycnt = 0;
}

signed main(){
	while( 1 ){
		scanf("%lld%lld%lld",&n,&u,&v);
		if( !n ) break;
		solve();
	}
	return 0;
}