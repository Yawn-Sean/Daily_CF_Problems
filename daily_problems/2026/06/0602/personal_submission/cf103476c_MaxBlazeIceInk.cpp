#include<bits/stdc++.h>
using namespace std;

#define MAXN 10

int n,p[MAXN],k[MAXN],cnt;

vector<int> ans;

inline void Output(){
	printf("%d\n",(int)ans.size());
	for( int ele : ans ) printf("%d ",ele);
	puts("");
}

inline void solA( int id ){
	int i2 = 0;
	for( int i = 1 ; i <= cnt ; i ++ )
		if( i != id ){ i2 = i; break; }
	//画一个蛇
	int now = 1; ans.emplace_back( 1 );
	for( int i = 1 ; i <= k[id] ; i ++ ){
		now *= p[id];
		ans.emplace_back( now );
	}
	int dir = 0; now *= p[i2];
	for( int i = k[id] ; i >= 0 ; i -- ){
		if( !dir ){
			for( int j = 1 ; j <= k[i2] ; j ++ ){
				ans.emplace_back( now );
				if( j < k[i2] ) now *= p[i2];
			}
		}
		else{
			for( int j = k[i2] ; j >= 1 ; j -- ){
				ans.emplace_back( now );
				if( j > 1 ) now /= p[i2];
			}
		}
		now /= p[id],dir ^= 1;
	}
	for( int i = 1 ; i <= cnt ; i ++ ){
		if( i == id || i == i2 ) continue;
		//依次插入剩下的。每一次
		int siz = (int)ans.size();
		vector<int> tmp;
		for( int j = 0 ; j < siz ; j += 2 ){
			tmp.emplace_back( ans[j] );
			int now = ans[j];
			for( int t = 1 ; t <= k[i] ; t ++ ){
				now *= p[i];
				tmp.emplace_back( now );
			}
			now = now / ans[j] * ans[j + 1];
			for( int t = 1 ; t <= k[i] ; t ++ ){
				tmp.emplace_back( now );
				now /= p[i];
			}
			tmp.emplace_back( ans[j + 1] );
		}
		ans = tmp;
	}
}

inline void solB(){
	//1 和 2 拼一个缺位
	int now = 1; ans.emplace_back( 1 );
	int id = 1,i2 = 2;
	for( int i = 1 ; i <= k[id] ; i ++ ){
		now *= p[id];
		ans.emplace_back( now );
	}
	int dir = 0; now *= p[i2];
	for( int i = k[id] ; i >= 2 ; i -- ){
		if( !dir ){
			for( int j = 1 ; j <= k[i2] ; j ++ ){
				ans.emplace_back( now );
				if( j < k[i2] ) now *= p[i2];
			}
		}
		else{
			for( int j = k[i2] ; j >= 1 ; j -- ){
				ans.emplace_back( now );
				if( j > 1 ) now /= p[i2];
			}
		}
		now /= p[id],dir ^= 1;
	}
	ans.emplace_back( now ),now /= p[id];
	ans.emplace_back( now ),now /= p[i2];
	ans.emplace_back( now );
	int x0 = now * p[id],x1 = x0 * p[i2];
	for( int j = k[i2] - 2 ; j >= 1 ; j -= 2 ){
		now /= p[i2];
		ans.emplace_back( now );
		now *= p[id];
		ans.emplace_back( now );
		now /= p[i2];
		ans.emplace_back( now );
		now /= p[id];
		ans.emplace_back( now );
	}
	for( int i = 3 ; i <= cnt ; i ++ ){
		if( i == id || i == i2 ) continue;
		//依次插入剩下的。每一次
		int siz = (int)ans.size();
		vector<int> tmp;
		for( int j = 0 ; j < siz ; j += 2 ){
			tmp.emplace_back( ans[j] );
			int now = ans[j];
			for( int t = 1 ; t <= k[i] ; t ++ ){
				now *= p[i];
				tmp.emplace_back( now );
			}
			now = now / ans[j] * ans[j + 1];
			int con = 0;
			for( int t = 1 ; t <= k[i] ; t ++ ){
				tmp.emplace_back( now );
				if( ans[j + 1] == x1 ){
					if( !con ){
						tmp.emplace_back( now / x1 * x0 );
						tmp.emplace_back( now / x1 * x0 / p[i] );
					}
				}
				con ^= 1;
				now /= p[i];
			}
			tmp.emplace_back( ans[j + 1] );
		}
		ans = tmp;
	}
}

signed main(){
	scanf("%d",&n);
	for( int i = 2 ; i * i <= n ; i ++ ){
		if( n % i ) continue;
		p[++cnt] = i;
		while( n % i == 0 ) n /= i,k[cnt] ++;
	}
	if( n > 1 ) p[++cnt] = n,k[cnt] = 1;
	if( cnt == 1 ){
		printf("2\n1 %d\n",p[1]);
		return 0;
	}
	for( int i = 1 ; i <= cnt ; i ++ ){
		if( k[i] & 1 ){
			//存在一个偶数
			solA( i );
			Output();
			return 0;
		}
	}
	//全是奇数
	solB();
	Output();
	return 0;
}