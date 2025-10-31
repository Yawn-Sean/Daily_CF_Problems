#include <bits/stdc++.h>
using namespace std;

inline int rd() {
	int x = 0;
	bool f = 0;
	char c = getchar();
	for (; !isdigit(c); c = getchar()) f |= (c == '-');
	for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ 48);
	return f ? -x : x;
}

#define rep(i, a, b) for (int i = (a); i <= (b); ++i)

constexpr int N = 30007;

int deg[N], sum[N];

int main() {
	int n = rd();
	printf("QUERY ");
	rep(i, 1, n) putchar('1');
	puts(""); fflush(stdout);
	rep(i, 1, n) deg[i] = rd();
	rep(j, 0, 14) {
		printf("QUERY ");
		rep(i, 1, n) putchar('0' + ((i >> j) & 1));
		puts(""); fflush(stdout);
		rep(i, 1, n) sum[i] += (rd() << j);
	}
	
	puts("ANSWER");
	queue<int> q;
	rep(i, 1, n) if (deg[i] == 1) q.push(i);
	rep(i, 2, n) {
		int u = q.front(); q.pop();
		printf("%d %d\n", u, sum[u]);
		sum[sum[u]] -= u;
		--deg[sum[u]];
		if (deg[sum[u]] == 1) q.push(sum[u]);
	}
	fflush(stdout);
	return 0;
}