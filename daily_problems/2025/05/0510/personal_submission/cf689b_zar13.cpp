#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n, a[N], dis[N];
bool vis[N];
int dx[] = {0, 1, -1};
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	queue<int> q;
	q.push(1);
	vis[1] = 1;
	while (q.size()) {
		int u = q.front();
		q.pop();
//		cout << "u:" << u << endl;
		dx[0] = a[u]-u;//
		for (int i = 0; i < 3; i++) {
			int v = u + dx[i];
			if (v < 1 || v > n) continue;
			if (!vis[v]) {
				dis[v] = dis[u] + 1;
				q.push(v);
				vis[v] = 1;
//				cout << v << endl;
			}
		}
	}
	for (int i = 1; i <= n; i++) cout << dis[i] << " ";
	return 0;
}
