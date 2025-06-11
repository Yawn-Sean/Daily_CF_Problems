#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <string>
#include <cmath>
#include <set>

#define debug(x) cout << #x << " " << x << endl;
#define rep(x, y, z) for(int x = (y) ; x <= (z) ; ++x)
#define per(x, y, z) for(int x = (y) ; x >= (z) ; --x)
#define ll long long

using namespace std;

inline int read (){
	int a = 0, w = 1;
	char c = getchar();
	while (c < '0' || c > '9'){
		if(c == '-') w = -1;
		c = getchar();
    }
    while (c >='0' && c <= '9'){
    	a = (a << 1) + (a << 3) + (c ^ 48);
    	c = getchar();
	}
	return a * w;
}

inline ll readll (){
	ll a = 0, w = 1;
	char c = getchar();
	while (c < '0' || c > '9'){
		if(c == '-') w = -1;
		c = getchar();
    }
    while (c >='0' && c <= '9'){
    	a = (a << 1) + (a << 3) + (c ^ 48);
    	c = getchar();
	}
	return a * w;
}

int dp[1005][105][2];
int n_10[1005];
int main (){
	int n, k, m;
	n = read(), k = read(), m = read();
	memset (dp, 0, sizeof dp);
	n_10[0] = 1;
	rep(i, 1, n) {
		n_10[i] = (n_10[i - 1] * 10) % k;
	}//预处理每位权值。
	dp[0][0][0] = 1;
	rep(i, 0, n - 1) {
		rep(j, 0, k - 1) {
			rep(l, (i == n - 1) ? 1 : 0, 9) {
				int now = (j + n_10[i] * l) % k;
				if(l && now == 0) {//如果l == 0， 那么只能归到dp[i + 1][now][0]里。
					dp[i + 1][now][1] = (dp[i + 1][now][1] + dp[i][j][0]) % m;
				}
				else {
					dp[i + 1][now][0] = (dp[i + 1][now][0] + dp[i][j][0]) % m;
				}
				dp[i + 1][now][1] = (dp[i + 1][now][1] + dp[i][j][1]) % m;//无论 now == 0 或者 now != 0， 都可以从dp[i][j][1]，转移过来。
			}
		}
	}
	int ans = 0;
	rep(i, 0, k - 1) {
		ans = (ans + dp[n][i][1]) % m;
	}//累加答案
	cout << ans % m << endl;
	return 0;
}
