#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
using PII = pair<int, int>;
using PDI = pair<double, int>;
using PLI = pair<ll, int>;
using PLL = pair<ll, ll>;
using PSI = pair<string, int>;
using PSS = pair<string, string>;
using PDD = pair<double, double>;
#define endl '\n'

const int N = 1e5 + 10;
const int P = 998244853;
int h[N], ne[N], w[N], e[N], ind;
int _h[N], _ne[N], _w[N], _e[N], _ind;
ll dist[2][N];
ull cnt[2][N];
ll CNT[2][N];
bool vis[N];
bool _vis[N];
int n, m, s, t;

struct Data {
	Data(int a = 0, int b = 0, int c = 0)
		: a(a), b(b), c(c) {}
	int a, b, c;
};

//正
void add(int a, int b, int c) {
	e[ind] = b, w[ind] = c, ne[ind] = h[a], h[a] = ind++;
	return;
}

//反
void _add(int a, int b, int c) {
	_e[_ind] = b, _w[_ind] = c, _ne[_ind] = _h[a], _h[a] = _ind++;
}

void Dijkstra() {
	memset(dist[0], 0x3f, sizeof dist[0]);
	dist[0][s] = 0;
	cnt[0][s] = 1;
	CNT[0][s] = 1;
	priority_queue<PLL, vector<PLL>, greater<PLL>> q;
	q.push({ 0, s });
	while (q.size()) {
		auto t = q.top(); q.pop();
		ll distance = t.first, ver = t.second;
		if (vis[ver]) continue;
		vis[ver] = true;
		for (int i = h[ver]; ~i; i = ne[i]) {
			int j = e[i];
			if (dist[0][j] > distance + w[i]) {
				dist[0][j] = distance + w[i];
				cnt[0][j] = cnt[0][ver];
				CNT[0][j] = CNT[0][ver];
				q.push({ dist[0][j], j });
			}
			else if (dist[0][j] == distance + w[i]) CNT[0][j] = (CNT[0][j] +  CNT[0][ver]) % P;
		}
	}
	return;
}

void _Dijkstra() {
	memset(dist[1], 0x3f, sizeof dist[1]);
	dist[1][t] = 0;
	cnt[1][t] = 1;
	CNT[1][t] = 1;
	priority_queue<PLL, vector<PLL>, greater<PLL>> q;
	q.push({ 0, t });
	while (q.size()) {
		auto t = q.top(); q.pop();
		ll distance = t.first, ver = t.second;
		if (_vis[ver]) continue;
		_vis[ver] = true;
		for (int i = _h[ver]; ~i; i = _ne[i]) {
			int j = _e[i];
			if (dist[1][j] > distance + _w[i]) {
				dist[1][j] = distance + _w[i];
				cnt[1][j] = cnt[1][ver];
				CNT[1][j] = CNT[1][ver];
				q.push({ dist[1][j], j });
			}
			else if (dist[1][j] == distance + _w[i]) CNT[1][j] =(CNT[1][j] + CNT[1][ver]) % P;
		}
	}
	return;
}

bool check(int &u, int &v, int &val) {
	if (dist[0][u] + dist[1][v] + val != dist[0][t]) return false;
	if (cnt[0][u] * cnt[1][v] != cnt[0][t]) return false;
	if (CNT[0][u] * CNT[1][v] % P != CNT[0][t]) return false;
	return true;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	memset(h, -1, sizeof h);
	memset(_h, -1, sizeof _h);
	cin >> n >> m >> s >> t;
	vector<Data> arr;
	for (int i = 0; i < m; i++) {
		int a, b, c; cin >> a >> b >> c;
		arr.push_back(Data(a, b, c));
		add(a, b, c);
		_add(b, a, c);
	}
	Dijkstra();
	_Dijkstra();
	ll distance = dist[0][t];
	for (auto& x : arr) {
		int u = x.a, v = x.b, val = x.c;
		if (check(u, v, val)) {
			cout << "YES" << endl;
		}
		else {
			ll diff = dist[0][t] - dist[0][u] - dist[1][v];
			if (diff <= 1) cout << "NO" << endl;
			else cout << "CAN " << val - diff  + 1 << endl;
		}
	}
	return 0;
}
