#include <bits/stdc++.h>
#define debug(x) cerr << #x << " = " << x << endl;

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int a, m, b, n;
	cin >> a >> m >> b >> n;

	int sz = n + 5;
	string ans;

	auto bfs = [&] (int x, string base) -> void {
		vector<int> pre(n, -2), pre_op(n);
		pre[x] = -1;
		
		vector<int> que = {x};

		for (int i = 0; i < que.size(); i ++) {
			int u = que[i], nu;

			nu = (u + m) % n;
			if (pre[nu] == -2) {
				pre[nu] = u;
				pre_op[nu] = 0;
				que.emplace_back(nu);
			}

			nu = ((u - m) % n + n) % n;
			if (pre[nu] == -2) {
				pre[nu] = u;
				pre_op[nu] = 1;
				que.emplace_back(nu);
			}

			nu = 1ll * u * m % n;
			if (pre[nu] == -2) {
				pre[nu] = u;
				pre_op[nu] = 2;
				que.emplace_back(nu);
			}
		}

		if (pre[b] != -2) {
			int cur = b;
			string ops;

			while (cur != x) {
				ops += "+-*"[pre_op[cur]];
				cur = pre[cur];
			}

			reverse(ops.begin(), ops.end());
			ops = base + ops;

			if (ops.size() < sz) {
				sz = ops.size();
				ans = ops;
			}
		}
	};

	bfs((a % n + n) % n, "");
	bfs((a % m + m) % m % n, "%");
	bfs(0, "*%");

	if (sz <= n) cout << sz << '\n' << ans << '\n';
	else cout << -1 << '\n';

	return 0;
}