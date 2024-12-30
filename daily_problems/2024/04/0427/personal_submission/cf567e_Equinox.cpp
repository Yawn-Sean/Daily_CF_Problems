#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

#define FIN freopen("in.txt", "r", stdin);
#define FIO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define mkp make_pair
#define int long long

const int N = 1e5 + 10, M = 1e5 + 10;
typedef pair<int, int> PII;
int n, m, s, t;
int head[N], idx, dsts[N], dstt[N];
int dfn[N], low[N], tot;
bool vis[M << 1], bri[M << 1], st[M << 1];
struct edge
{
	int v, w, nxt;
} edges[M << 1];

void addedge(int u, int v, int w)
{
	edges[idx] = {v, w, head[u]}, head[u] = idx++;
}

void add(int u, int v, int w)
{
	addedge(u, v, w), addedge(v, u, w);
}

void tarjan(int u, int pre)
{
	dfn[u] = low[u] = ++tot;
	for (int i = head[u]; ~i; i = edges[i].nxt)
	{
		if (!st[i])
			continue;
		int v = edges[i].v;
		if (!dfn[v])
		{
			tarjan(v, i);
			low[u] = min(low[u], low[v]);
			if (low[v] > dfn[u])
				bri[i] = bri[i ^ 1] = true;
		}
		else if (i != (pre ^ 1))
		{
			low[u] = min(low[u], dfn[v]);
		}
	}
}

signed main()
{
	FIO
		FIN
			memset(head, -1, sizeof head);
	cin >> n >> m >> s >> t;
	for (int i = 0, a, b, c; i < m; i++)
	{
		cin >> a >> b >> c;
		add(a, b, c);
	}
	memset(dsts, 0x3f, sizeof dsts), memset(dstt, 0x3f, sizeof dstt);
	// shortest path
	priority_queue<PII, vector<PII>, greater<PII>> pq;
	pq.emplace(mkp(dsts[s] = 0, s));
	while (pq.size())
	{
		auto [d, u] = pq.top();
		pq.pop();
		if (vis[u])
			continue;
		vis[u] = 1;
		for (int i = head[u]; ~i; i = edges[i].nxt)
		{
			if (i & 1)
				continue;
			int v = edges[i].v, w = edges[i].w;
			if (vis[v])
				continue;
			if (dsts[u] + w < dsts[v])
				pq.emplace(mkp(dsts[v] = dsts[u] + w, v));
		}
	}

	memset(vis, 0, sizeof vis);
	pq.emplace(mkp(dstt[t] = 0, t));
	while (pq.size())
	{
		auto [d, u] = pq.top();
		pq.pop();
		if (vis[u])
			continue;
		vis[u] = 1;
		for (int i = head[u]; ~i; i = edges[i].nxt)
		{
			if (i % 2 == 0)
				continue;
			int v = edges[i].v, w = edges[i].w;
			if (vis[v])
				continue;
			if (dstt[u] + w < dstt[v])
				pq.emplace(mkp(dstt[v] = dstt[u] + w, v));
		}
	}

	for (int i = 0, mi = dsts[t]; i < idx; i += 2)
	{
		int u = edges[i ^ 1].v, v = edges[i].v, w = edges[i].w;
		int d = dsts[u] + dstt[v] + w;

		if (d == mi)
			st[i] = st[i ^ 1] = 1;
	}

	//  tarjan
	tarjan(s, -1);
	for (int i = 0, mi = dsts[t]; i < idx; i += 2)
	{
		int u = edges[i ^ 1].v, v = edges[i].v, w = edges[i].w;
		int d = dsts[u] + dstt[v] + w;
		if (bri[i])
		{
			cout << "YES\n";
		}
		else
		{

			if (d - mi + 1 < w)
			{
				cout << "CAN " << d - mi + 1 << '\n';
			}
			else
				cout << "NO\n";
		}
	}
	return 0;
}