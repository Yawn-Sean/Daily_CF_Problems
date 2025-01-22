#include <iostream>
#include <vector>
#include <string>

using namespace std;

const int N = 300001;
const int M = 500001;


int a[N], vis[N];
vector<int> b[M];

int n, m;
int main() {
	
	ios::sync_with_stdio(false);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		b[u].push_back(v);
	}
	vis[a[n - 1]] = 1;

	int ans = 0;

	for (int i = n - 2; i >= 0; i--)
	{
		int tt = 0;
		for (int j = 0; j < b[a[i]].size(); j++)
			if (vis[b[a[i]][j]])
				tt++;

		if (tt + i + ans == n - 1)
			ans++;
		else
			vis[a[i]] = 1;
	}

	cout << ans << endl;
	return 0;

}
