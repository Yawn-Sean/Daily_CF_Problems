#include<bits/stdc++.h>
using namespace std;

#define int long long
#define double long double
#define MAXN 500005
#define mod 998244353

int n,m,x[MAXN],typ[MAXN],p[MAXN];

inline bool cmp( int u , int v ){ return x[u] < x[v]; }
inline bool cmp2( int u , int v ){ return x[u] > x[v]; }

//直接猜排序是对的

inline double getmax(){
	sort( p + 1 , p + m + 1 , cmp );
	int sum = 0;
	for( int i = 1 ; i <= m ; i ++ ){
		int id = p[i];
		if( typ[id] == 1 ){
			sum += x[id];
		}
		else{
			//( sum + v ) / i = x
			int target = x[id] * i;
			if( target <= sum ) sum ++;
			else sum = min( sum + n , target );
		}
	}
	return (double)1.0 * sum / m;
}

inline double getmin(){
	sort( p + 1 , p + m + 1 , cmp2 );
	int sum = 0;
	for( int i = 1 ; i <= m ; i ++ ){
		int id = p[i];
		if( typ[id] == 1 ){
			sum += x[id];
		}
		else{
			//( sum + v ) / i = x
			int target = x[id] * i;
			if( target <= sum ) sum ++;
			else sum = min( sum + n , target );
		}
	}
	return (double)1.0 * sum / m;
}

signed main(){
	scanf("%lld%lld",&n,&m);
	for( int i = 1 ; i <= m ; i ++ ){
		char t[3]; scanf("%s%lld",t + 1,&x[i]);
		typ[i] = t[1] == 'S' ? 1 : 2; 
		p[i] = i;
	}
	printf("%.12Lf %.12Lf\n",getmin(),getmax());
	return 0;
}