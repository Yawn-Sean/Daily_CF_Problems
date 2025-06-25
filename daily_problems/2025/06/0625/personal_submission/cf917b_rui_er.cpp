//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;
const int N = 105;

int n, m, dp[N][N][26];
vector<tuple<int, int> > e[N];
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}
int dfs(int u, int d, int now) {
	if(~dp[u][d][now]) return dp[u][d][now];
	for(auto i : e[u]) {
		int v = get<0>(i), w = get<1>(i);
		if(w < now) continue;
		if(!dfs(d, v, w)) return dp[u][d][now] = 1;
	}
	return dp[u][d][now] = 0;
}

int main() {
	memset(dp, -1, sizeof(dp));
	scanf("%d%d", &n, &m);
	rep(i, 1, m) {
		int u, v, w;
		scanf("%d%d %c", &u, &v, &w);
		e[u].push_back(make_tuple(v, w-'a'));
	}
	rep(i, 1, n) {
		rep(j, 1, n) {
			putchar('A'+!dfs(i, j, 0));
		}
		puts("");
	}
	return 0;
}
