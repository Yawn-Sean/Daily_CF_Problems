#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b)	for (int i(a); i <= (b); ++i)
#define dec(i, a, b)	for (int i(a); i >= (b); --i)

const int N = 1e3 + 10;

int n;
int m;
int cc[2];
int f[N];
bool flag;
long long a[N], b[N], c[N];
vector <int> v[N];

void addedge(int x, int y) {
	v[x].emplace_back(y);
	v[y].emplace_back(x);
}

int main() {

	scanf("%d", &n);
	rep(i, 1, n) scanf("%lld%lld%lld", a + i, b + i, c + i);


	rep(i, 1, n - 1) {
		rep(j, i + 1, n) {
			long long d1 = (a[i] - a[j]) * (a[i] - a[j]);
			long long d2 = (b[i] - b[j]) * (b[i] - b[j]);
			long long d3 = (c[i] + c[j]) * (c[i] + c[j]);
			if (d1 + d2 == d3) {
				addedge(i, j);
			}
		}
	}

	rep(i, 1, n) {
		queue <int> q;
		q.push(i);

		flag = true;

		memset(cc, 0, sizeof cc);
		memset(f, -1, sizeof f);
		cc[0] = 1;
		f[i] = 0;
		
		while (!q.empty()) {
			int x = q.front();
			q.pop();

			for (auto u : v[x]) {
				if (f[u] != -1) {
				   	if (f[u] == f[x]) {
						flag = false;
						break;
					}
				} else {
				   f[u] = f[x] ^ 1;
				   ++cc[f[u]];
				   q.push(u);
				}
			}
		}

		if (flag && cc[0] != cc[1]) {
			return 0 * puts("Yes");
		}
	}

	puts("No");
	return 0;
}
 
